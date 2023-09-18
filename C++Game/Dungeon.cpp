
#include "Dungeon.h"
#include "GameEngine.h"
#include <stdio.h>
#include <vector>

using namespace std;


Dungeon :: Dungeon(Pokemon containedPokemon, Dungeon nextDungeon): containedPokemon{containedPokemon}, nextDungeon{NULL} {};
Dungeon :: Dungeon() {};
