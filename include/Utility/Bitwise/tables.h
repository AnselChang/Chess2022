#pragma once

#include <cstdint>
#include "common.h"
#include "Utility/constants.h"

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

// Initialize rays from specified direction. Bruteforce
uint64_t rayAttacks[8][64];
void initRay(Direction direction, int dx, int dy) {
   
   for (int x=0; x<8; x++) { // iterate through all indicies of 2d array rays
      for (int y=0; y<8; y++) {
            int x0 = x + dx;
            int y0 = y + dy;
            uint64_t result = 0;
            
            while (x0 >= 0 && x0 < 8 && y0 >= 0 && y0 < 8) { // while in bounds
               
               result += getSingle(Square(x0, y0).id);
               
               x0 += dx;
               y0 += dy;
            }
            rayAttacks[direction][Square(x, y).id] = result;
      }
   }
};

const uint64_t queensideCastlingSquares[2] = {getSingle(1) + getSingle(2) + getSingle(3), getSingle(57) + getSingle(58) + getSingle(59)};
const uint64_t kingsideCastlingSquares[2] = {getSingle(5) + getSingle(6), getSingle(61) + getSingle(62)};

const uint64_t defaultKing[2] = {4, 60};

void initLookupTables() {

   for (int i = 0; i < 64; i++) {
      uint64_t square = getSingle(i);
      arrKnightAttacks[i] = knightAttacks(square);
      arrKingAttacks[i] = kingAttacks(square);
   }

    initRay(NORTH,0,1);
   initRay(NORTHEAST,1,1);
   initRay(EAST,1,0);
   initRay(SOUTHEAST,1,-1);
   initRay(SOUTH,0,-1);
   initRay(SOUTHWEST,-1,-1);
   initRay(WEST,-1,0);
   initRay(NORTHWEST,-1,1);

}