#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <map>
#include <ranges>
#include "Player.h"

#include <stdio.h>

Player :: Player(int playerHealth, map<string, int> inventory) : health{playerHealth}, inventory{inventory} {
    cout << "Player Spawned!" << endl;
};
Player :: Player (): Player {{},{}} {
    cout << "Player Spawned!" << endl;
};
    
   


