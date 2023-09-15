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

void GameEngine :: playTurn(){
    setCurrentPokemon();
    currentPokemon.playBattleCry();
    playBattleMusic();
    
}

void GameEngine:: playBattleMusic() {
    string musicName = currentPokemon.isLegendary ? "~/bossmusic.wav" :"~/battlewusic.wav" ;
    
    cout << musicName << endl;
    
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
