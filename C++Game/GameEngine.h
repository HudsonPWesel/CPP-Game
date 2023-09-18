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
#include "Dungeon.h"

#ifndef GameEngine_h
#define GameEngine_h


using namespace std;
class GameEngine{
    
    
public:
    Player player;
    vector<Pokemon> possiblePokemon;
    vector<string> possiblePlayerOptions;
    vector<string> possibleEncounterOptions;
    GameEngine(vector<Pokemon> possiblePokemon, vector<string> possiblePlayerOptions, Player player, vector<string> possibleEncounterOptions);
    vector<Dungeon*> dungeons;
   
    void playBattleMusic(Pokemon currentPokemon);
    void playGame();
    void generateEncounter();
    void setDungeons();
    int selectEncounter(int indexOfPlayerChoice);
    int playAttackEncounter();
    
private:
    map<string, function<void()>> playerChoiceFunctionMap;
    
    void printOptions(vector<string> options);
    int getPlayerChoice(vector<string> options);
    void playEncounter(int playerChoice);
    int playOutsideCaveEncounter();
    

};

#endif /* GameEngine_h */

