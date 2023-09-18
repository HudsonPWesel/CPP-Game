#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

#include "Pokemon.h"

using namespace std;

Pokemon :: Pokemon(int health, string name, map<string,int> attackMoves, string battleCry, bool isLegendary) : health{health}, name{name},attackMoves{attackMoves}, battleCry{battleCry}, isLegendary{isLegendary} {};

Pokemon :: Pokemon() : Pokemon {{},{},{},{}, {}} {};

int Pokemon :: attackPlayer(){

    playBattleCry();
    
    bool isCriticalAttack {calculateIsCriticalAttack()};
    
    string chosenAttack {chooseAttack()};
    
    int damageDelt = attackMoves[chosenAttack];
    damageDelt = isCriticalAttack ? damageDelt * 2: damageDelt;
  
    cout << name << " Used : " << chosenAttack << endl << "Dmg Delt: " << damageDelt << endl;
    return damageDelt;
    
//TODO:  Add Battle Music
    
//TODO: Try to add battle for only while the player has not provided input

// TODO: Deal damage to player
    
}

bool Pokemon ::  calculateIsCriticalAttack(){
    srand(unsigned (time(0)));
    
    int coinFlip = rand() % 2;
    return coinFlip == 1;
    
}

string Pokemon :: chooseAttack(){
    vector<string> attackNames {};
    
    srand(unsigned (time(0)));
    
    for (auto it = attackMoves.begin(); it != attackMoves.end(); it++)
        attackNames.push_back(it->first);
    
    int attackChoice = rand() % attackMoves.size();
    
    return attackNames[attackChoice];
    
}

void Pokemon :: playBattleCry(){
    
    
    string commandString = "afplay -t 1 " + battleCry;
    
    cout << commandString << endl;
    const char* charPointer = commandString.c_str();
    system(charPointer);
    
}

