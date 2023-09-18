#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include "Pokemon.h"
#include "GameEngine.h"
#include "Dungeon.h"

#include <stdio.h>
int main(){
//    Implement pokemon battle music and cries
//    THis could paralyze the opponenet
//    Recoil
//   --INTIALIZE POKEMON--
    
//    -Pikachu
    map<string, int> pikachuAttackMoves;
    pikachuAttackMoves.insert({"Thunderbolt", 10});
    pikachuAttackMoves.insert({"Volt Tackle", 12});
    pikachuAttackMoves.insert({"Iron-Tail", 9});
    pikachuAttackMoves.insert({"Quick Attack", 8});
    
    Pokemon pikachu {35, "Pikachu", pikachuAttackMoves, "~/pikachu.wav", false};
    
//    -Latias
    map<string, int> latiasAttackMoves;
    latiasAttackMoves.insert({"Luster Purge", 25});
    latiasAttackMoves.insert({"Psychic", 15});
    latiasAttackMoves.insert({"Shadow Ball", 12});
    Pokemon latias {80, "Latias", latiasAttackMoves, "~/latios.wav", true};
    
    
    vector<Pokemon> possiblePokemon {pikachu, latias};
    vector<string> possiblePlayerOptions {"Enter Cave...", "Run Away"};
    vector<string> possibleEncounterOptions {"Attack","RUN"};
    map<string, int> inventory {};
    Player player {100, inventory};
    
    
    GameEngine engine {possiblePokemon, possiblePlayerOptions, player, possibleEncounterOptions};
    
    engine.playGame();
    
    
    };
    
    

