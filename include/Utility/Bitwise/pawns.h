#pragma once

#include <cstdint>
#include "common.h"

// dealing with pawn pushes
uint64_t wSinglePushTargets(uint64_t wpawns, uint64_t empty) {
   return nortOne(wpawns) & empty;
}

uint64_t wDblPushTargets(uint64_t wpawns, uint64_t empty) {
   const uint64_t rank4 = 0x00000000FF000000;
   uint64_t singlePushs = wSinglePushTargets(wpawns, empty);
   return nortOne(singlePushs) & empty & rank4;
}

uint64_t bSinglePushTargets(uint64_t bpawns, uint64_t empty) {
   return soutOne(bpawns) & empty;
}

uint64_t bDblPushTargets(uint64_t bpawns, uint64_t empty) {
   const uint64_t rank5 = 0x000000FF00000000;
   uint64_t singlePushs = bSinglePushTargets(bpawns, empty);
   return soutOne(singlePushs) & empty & rank5;
}

// dealing with pawn attacks
uint64_t wPawnEastAttacks(uint64_t wpawns) {return noEaOne(wpawns);}
uint64_t wPawnWestAttacks(uint64_t wpawns) {return noWeOne(wpawns);}

uint64_t bPawnEastAttacks(uint64_t bpawns) {return soEaOne(bpawns);}
uint64_t bPawnWestAttacks(uint64_t bpawns) {return soWeOne(bpawns);}

uint64_t wPawnAnyAttacks(uint64_t wpawns) {
   return wPawnEastAttacks(wpawns) | wPawnWestAttacks(wpawns);
}

uint64_t bPawnAnyAttacks(uint64_t wpawns) {
   return bPawnEastAttacks(wpawns) | bPawnWestAttacks(wpawns);
}