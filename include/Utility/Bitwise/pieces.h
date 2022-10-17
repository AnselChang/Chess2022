#pragma once

#include <cstdint>
#include "common.h"
#include "bitscan.h"
#include "Utility/constants.h"
#include "tables.h"

uint64_t getPositiveRayAttacks(uint64_t occupied, Direction dir8, int square) {
   uint64_t attacks = rayAttacks[dir8][square];
   uint64_t blocker = attacks & occupied;
   if ( blocker ) {
      square = bitScanForward(blocker);
      attacks ^= rayAttacks[dir8][square];
   }
   return attacks;
}

uint64_t getNegativeRayAttacks(uint64_t occupied, Direction dir8, int square) {
   uint64_t attacks = rayAttacks[dir8][square];
   uint64_t blocker = attacks & occupied;
   if ( blocker ) {
      square = bitScanReverse(blocker);
      attacks ^= rayAttacks[dir8][square];
   }
   return attacks;
}