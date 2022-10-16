#pragma once

#include <cstdint>
#include "common.h"

uint64_t knightAttacks(uint64_t knights) {
   uint64_t west, east, attacks;
   east     = eastOne (knights);
   west     = westOne (knights);
   attacks  = (east|west) << 16;
   attacks |= (east|west) >> 16;
   east     = eastOne (east);
   west     = westOne (west);
   attacks |= (east|west) <<  8;
   attacks |= (east|west) >>  8;
   return attacks;
}
uint64_t arrKnightAttacks[64];


uint64_t kingAttacks(uint64_t kingSet) {
   uint64_t attacks = eastOne(kingSet) | westOne(kingSet);
   kingSet    |= attacks;
   attacks    |= nortOne(kingSet) | soutOne(kingSet);
   return attacks;
}
uint64_t arrKingAttacks[64];


void initLookupTables() {

    for (int i = 0; i < 64; i++) {
        uint64_t square = setOn(0, i);
       arrKnightAttacks[i] = knightAttacks(square);
       arrKingAttacks[i] = kingAttacks(square);
    }

}