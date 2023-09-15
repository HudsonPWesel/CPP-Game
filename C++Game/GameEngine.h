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
#include "Pokemon.h"
#include "Player.h"

#ifndef GameEngine_h
#define GameEngine_h

class GameEngine{
public:
    Player player;
    vector<Pokemon> possiblePokemon;
    vector<string> possiblePlayerOptions;
    GameEngine(vector<Pokemon> possiblePokemon, vector<string> possiblePlayerOptions, Player player);
    void playBattleMusic();
    void playGame();
    void generateEncounter();
    
private:
    Pokemon currentPokemon;
    map<string, function<void()>> playerChoiceFunctionMap;
    void setCurrentPokemon ();
    void playTurn();
    void printOptions();
    int getPlayerChoice();
    

};

#endif /* GameEngine_h */
