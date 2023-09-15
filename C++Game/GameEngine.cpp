//
//  GameEngine.cpp
//  C++Game
//
//  Created by Hudson Wesel on 9/15/23.
//

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

using namespace std;

#include <stdio.h>

GameEngine :: GameEngine(vector<Pokemon> possiblePokemon, vector<string> possiblePlayerOptions, Player player) : possiblePokemon{possiblePokemon}, possiblePlayerOptions{possiblePlayerOptions}, player{player} {};

void GameEngine :: setCurrentPokemon(){
    srand(unsigned (time(0)));
    currentPokemon = possiblePokemon.at(rand() % possiblePokemon.size());
    
}

// TODO: IMPLEMENT BINARY TREE OR LINKED LIST
void GameEngine :: generateEncounter(){
    string displayText;
    
    bool isStartOfGame {find(possiblePlayerOptions.begin(), possiblePlayerOptions.end(), "Enter Cave...") != possiblePlayerOptions.end()};
    
    printOptions();
    
    if (!isStartOfGame)
        cout << "Next Level!" << endl;
    else{
        cout << "Welcome to Pokemon Cave Text Advenure Game!" << endl;
    }
    
    
    
    string playerChoice {possiblePlayerOptions.at(getPlayerChoice())};
    cout << playerChoice << endl;
    
    
    
}

int GameEngine :: getPlayerChoice() {
    int userChoice {};
    
    do {
        cout << "Enter an option via a number between 0-" << possiblePlayerOptions.size() - 1<< endl;
        cin >> userChoice;
    } while (userChoice < 0 || userChoice > possiblePlayerOptions.size());
    
    return userChoice;
}
void GameEngine :: printOptions() {
    
    string optionsDisplayHeader { "\n Here are your available options: \n"};
    cout << optionsDisplayHeader << endl;
    for(int i {0}; i < possiblePlayerOptions.size(); i++)
        cout << setw(25) << left << " " << possiblePlayerOptions.at(i) << right << " [" + to_string(i) + "]" << endl;
    
    
    
    
}

void GameEngine :: playTurn(){
    setCurrentPokemon();
    generateEncounter();
//    currentPokemon.playBattleCry();
//    playBattleMusic();
    
    
}

void GameEngine:: playBattleMusic() {
    string musicName = currentPokemon.isLegendary ? "~/bossmusic.wav" : "~/battlemusic.wav" ;
    
    
    string commandString = "afplay -t 10 " + musicName;

    const char* charPointer = commandString.c_str();
    system(charPointer);
}
void GameEngine:: playGame() {
    while(player.health > 0)
        {
            playTurn();
            break;
        }
    
};
