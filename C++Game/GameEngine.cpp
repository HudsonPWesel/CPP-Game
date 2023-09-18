

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
//    Pokemon currentPokemon {dungeons.at(0)->containedPokemon};
    if(dungeons.at(0)->containedPokemon.health < 0)
        return 10; // Break out of while loop
    
    cout << "YOU FOUND A PIKACHU WHAT WILL YOU DO?" << endl;
    printOptions(possibleEncounterOptions);
//        currentPokemon.playBattleCry();
//        playBattleMusic(currentPokemon);
    
//        Encounter Options
    cout << "PIKA HEALTH: " << dungeons.at(0)->containedPokemon.health << endl;
    
    int newPlayerChoice = getPlayerChoice(possibleEncounterOptions);
    
    if(newPlayerChoice == 1)
       {
           player.health -= dungeons.at(0)->containedPokemon.attackPlayer();
           cout << "Your New Health: " << player.health << "%" << endl;
       }
    
    else{
        cout << "You Attacked Pikachu!" << endl;
        
       int dmg = rollForAtkDamage(0,dungeons.at(0)->containedPokemon.health);
       if (dmg >= dungeons.at(0)->containedPokemon.health * .25)
       {
           dungeons.at(0)->containedPokemon.health -= dmg;
           cout << dungeons.at(0)->containedPokemon.health << "%" << endl;
       }
       else
       {
           cout << "CLUTZ | You hurt yourself in confusion!" << endl;
           
           player.health -= dmg;
           cout << "Your New Health: " << player.health;
       }
           
        return 0;
   }
    return newPlayerChoice;
}

int GameEngine :: playOutsideCaveEncounter(){
    cout << "The Sun Is Burning Your Skin!" << endl;
    int dmg = rollForAtkDamage(0, 10);
    player.health -= dmg;
    
    string newHealth = player.health < 0 ? "0" : to_string(player.health);
    
    cout << "The Sun Did" << dmg << "Damage!" << endl;
    
    cout << "Your New Health: " << newHealth << "%";
    
    return -1; // They need to enter cave otherwise they need to finish the battle with pikachu
}
int GameEngine:: selectEncounter (int indexOfPlayerChoice){
    
    bool isInsideCave = indexOfPlayerChoice == 0;
    
    if(isInsideCave)
        return playAttackEncounter();

    else
        return playOutsideCaveEncounter();

    
}

void GameEngine :: generateEncounter(){
    string displayText;
    int indexOfPlayerChoice {-1};
    printOptions(possiblePlayerOptions);
    
    indexOfPlayerChoice = getPlayerChoice(possiblePlayerOptions);
    while(player.health > 0 )
            indexOfPlayerChoice = selectEncounter(indexOfPlayerChoice);
    
    if(player.health < 0)
        cout << "YOU ARE DEAD";
    else
        cout << "YOU WIN";

}

    
//if (!isStartOfGame)
//    cout << "Next Level! | CONGRATULATIONS ON BEATING THE PREVIOUS LEVEL" << endl;
//else{
//    cout << "Welcome to Pokemon Cave Text Advenure Game!" << endl;
    
////    Check if they have entered cave yet
//    bool isStartOfGame {find(possiblePlayerOptions.begin(), possiblePlayerOptions.end(), "Enter Cave...") != possiblePlayerOptions.end()};


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
    cout << dungeons.at(0)->containedPokemon.name << endl;
  
    while(player.health > 0)
        {
            generateEncounter();
            break;
        }
    
};

