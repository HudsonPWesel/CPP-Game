#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <map>
#include <ranges>

using namespace std;

#ifndef Player_h
#define Player_h


class Player{
public:
    int health;
    vector<string> availableOptions;
    map<string, int> inventory;
    Player(int playerHealth, map<string, int> inventory);
    Player ();
    
    
};

#endif /* Player_h */
