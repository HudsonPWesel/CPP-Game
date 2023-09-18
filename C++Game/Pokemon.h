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
using namespace std;

#ifndef Monster_h
#define Monster_h

class Pokemon{
public:
    int health;
    
    string name;
    map<string,int> attackMoves;
    bool isLegendary;
    
    int attackPlayer();
    void playBattleCry();
    
    Pokemon(int health, string name, map<string, int> attackMoves, string battleCry, bool isLegendary);
    Pokemon();
private:
    bool calculateIsCriticalAttack();
    string chooseAttack();
    string battleCry;
    
    
    
    
  
    
};

#endif /* Monster_h */
