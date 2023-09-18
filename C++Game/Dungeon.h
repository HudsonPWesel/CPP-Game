#include "Pokemon.h"
#include <vector>
#ifndef Dungeon_h
#define Dungeon_h


using namespace std;

class Dungeon{
public:
    Dungeon* nextDungeon;
    Pokemon containedPokemon;
    
    
    Dungeon(Pokemon containedPokemon, Dungeon nextDungeon);
    Dungeon();
    
};
#endif /* Dungeon_h */
