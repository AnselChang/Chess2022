#pragma once

#include <iostream>
#include "Utility/Bitwise.h"

class Bitboard {

public:

    static Bitboard zeros() { return Bitboard(0); }
    static Bitboard ones() { return Bitboard(std::numeric_limits<uint64_t>::max()); }

    Bitboard(uint64_t _bb): bb(_bb) {}
    Bitboard(): bb(0) {}

    Bitboard& operator+=(const Bitboard& other) {
        bb += other.bb;
        return *this;
    }

    Bitboard operator+(const Bitboard& other) {
        return Bitboard(bb + other.bb);
    }

    // Get the value of a bit at location k
    int get(int k) const {
        return (bb >> k) & 1;
    }

    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const Bitboard& bitboard) {
        
        for (int y = 7; y >= 0; y--) {
            os << "\n";
            for (int x = 0; x < 8; x++) {
                os << bitboard.get(y*8 + x) << " ";
            }
        }
        os << std::endl;
        return os;
    }


private:

    uint64_t bb;

};