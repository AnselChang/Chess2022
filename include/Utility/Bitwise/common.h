#pragma once

#include <iostream>
#include <cstdint>
//#include <limits>


// Get the value of a bit at location k. Slow for multiple bits; prefer other bitwise operations
static int get(uint64_t bb, int k) {
    return (bb >> k) & 1;
}

// Set the value of a bit at location k to 1. Slow for multiple bits; prefer other bitwise operations
static uint64_t setOn(uint64_t bb, int k) {
    return bb | (1ULL << k);
}

// Set the value of a bit at location k to 1. Slow for multiple bits; prefer other bitwise operations
static uint64_t setOff(uint64_t bb, int k) {
    return bb & ~(1UL << k);
}

static void print(uint64_t bb) {
    for (int y = 7; y >= 0; y--) {
        std::cout << "\n";
        for (int x = 0; x < 8; x++) {
            std::cout << get(bb, y*8 + x) << " ";
        }
    }
    std::cout << std::endl;
}


// Shifting bitboards
inline uint64_t soutOne (uint64_t b) {return  b >> 8;}
inline uint64_t nortOne (uint64_t b) {return  b << 8;}


const uint64_t notAFile = 0xfefefefefefefefe; // ~0x0101010101010101
const uint64_t notHFile = 0x7f7f7f7f7f7f7f7f; // ~0x8080808080808080

// Post-shift masks
inline uint64_t eastOne (uint64_t b) {return (b << 1) & notAFile;}
inline uint64_t noEaOne (uint64_t b) {return (b << 9) & notAFile;}
inline uint64_t soEaOne (uint64_t b) {return (b >> 7) & notAFile;}
inline uint64_t westOne (uint64_t b) {return (b >> 1) & notHFile;}
inline uint64_t soWeOne (uint64_t b) {return (b >> 9) & notHFile;}
inline uint64_t noWeOne (uint64_t b) {return (b << 7) & notHFile;}

