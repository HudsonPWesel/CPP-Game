

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <map>
#include <ranges>
#include <libproc.h>
#include <stdio.h>
#include <unistd.h>
#include <iomanip>
#include <string.h>
#include <signal.h>
#include "GameEngine.h"
#include "Dungeon.h"
#include "Pokemon.h"
#include <vector>
#include <stdio.h>
using namespace std;


//1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

GameEngine :: GameEngine(vector<Pokemon> possiblePokemon, vector<string> possiblePlayerOptions, Player player, vector<string> possibleEncounterOptions) : possiblePokemon{possiblePokemon}, possiblePlayerOptions{possiblePlayerOptions}, player{player}, possibleEncounterOptions{possibleEncounterOptions}{
    
};


// TODO: IMPLEMENT BINARY TREE


int rollForAtkDamage(int min, int max){
    srand(unsigned (time(0)));
    return rand() % max;
}

int GameEngine:: playAttackEncounter(){
    int newPlayerChoice {10}; // Break out of loop;

    Pokemon* currentPokemon = &(dungeons.at(flipCoin())->containedPokemon);
    string playerHealthMessage {};
    
    
    
    while(currentPokemon->health > 0 && player.health > 0)
    {
        cout << "\n YOU FOUND A " << currentPokemon->name <<  " WHAT WILL YOU DO?" << endl;
        
        printOptions(possibleEncounterOptions);
        //        currentPokemon.playBattleCry();
//        playBattleMusic(*currentPokemon);
        
        //        Encounter Options
        
        newPlayerChoice = getPlayerChoice(possibleEncounterOptions);
        
        player.health -= currentPokemon->attackPlayer();
        
        if(player.health <= 0)
            break;

        cout << "Your New Health: " + to_string(player.health) + "%";
        
//        Attack Pokemon selected
        if(newPlayerChoice == 0){
            
            cout << "\n You Attacked " << currentPokemon->name << endl;
            
            int dmg = rollForAtkDamage(0,currentPokemon->health);
            
            
            
            if (dmg >= 1)
            {
                cout << "You Did " << dmg << " Damage! " << endl;
                
                currentPokemon->health -= dmg;
                
                cout << currentPokemon->name<< "'s Health: " << currentPokemon->health << "%" << endl;
                
            }
            else
            {
                cout << "CLUTZ | You hurt yourself in confusion!" << endl;
                
                player.health -= dmg;
                cout << playerHealthMessage;
            }
            
        }
        
    }
    return newPlayerChoice;
}
void GameEngine :: playOutsideCaveEncounter(){
    int newPlayerChoice {1};
    while(newPlayerChoice == 1){
        
        cout << "The Sun Is Burning Your Skin!" << endl;
        int dmg = rollForAtkDamage(0, 10);
        player.health -= dmg;
        
        string newHealth = player.health < 0 ? "0" : to_string(player.health);
        
        cout << "The Sun Did " << dmg << " Damage!" << endl;
        
        cout << "Your New Health: " << newHealth << "%";
        
        printOptions(possiblePlayerOptions);
        newPlayerChoice = getPlayerChoice(possiblePlayerOptions);
    }
     // They need to enter cave otherwise they need to finish the battle with pikachu
    playAttackEncounter();
}
void GameEngine:: selectEncounter (int indexOfPlayerChoice){
    
    bool isInsideCave = indexOfPlayerChoice == 0;
    
    while(isInsideCave && player.health > 0 && indexOfPlayerChoice == 0)
        indexOfPlayerChoice = playAttackEncounter();

    while(indexOfPlayerChoice == 1 && player.health > 0)
        playOutsideCaveEncounter();
    
}

void GameEngine :: generateEncounter(){
    int indexOfPlayerChoice;
    
        printOptions(possiblePlayerOptions);
        indexOfPlayerChoice = getPlayerChoice(possiblePlayerOptions);
        selectEncounter(indexOfPlayerChoice);
        
    }

int GameEngine:: flipCoin(){
    srand(unsigned (time(0)));
    
    int val = random() % 2;
    return val;
     
}


int GameEngine :: getPlayerChoice(vector<string> options) {
    int userChoice {};
    
    do {
        cout << "Enter an option via a number between 0-" << options.size() - 1<< endl;
        cin >> userChoice;
    } while (userChoice < 0 || userChoice > possiblePlayerOptions.size());
    
    return userChoice;
}

void GameEngine :: printOptions(vector<string> options) {
    
    string optionsDisplayHeader { "\n Here are your available options: \n"};
    cout << optionsDisplayHeader << endl;
    for(int i {0}; i < options.size(); i++)
        cout << setw(25) << left << " " << options.at(i) << right << " [" + to_string(i) + "]" << endl;

    
}

void GameEngine:: playBattleMusic(Pokemon currentPokemon) {
    string musicName = currentPokemon.isLegendary ? "~/bossmusic.wav" : "~/battlemusic.wav" ;
    
    
    string commandString = "afplay -t 20 " + musicName;

    const char* charPointer = commandString.c_str();
    system(charPointer);
}

void GameEngine :: setDungeons() {
    Dungeon d2;
    Dungeon d1;
    dungeons.push_back(new Dungeon(possiblePokemon.at(0), d2));
    dungeons.push_back(new Dungeon(possiblePokemon.at(1), d1));

}
 
void GameEngine:: playGame() {
    setDungeons();
    
    generateEncounter();
    
    if(player.health >= 0)
        cout << "You Lose!";
        
    else{
        system("afplay ~/kirby.wav");
        cout << "Your Final Score: " << (abs(player.health * 32)) << "Points!";
    }
    
    
};

