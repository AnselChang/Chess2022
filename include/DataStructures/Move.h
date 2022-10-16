#pragma once

#include "Square.h"

typedef struct Move {

    Square from, to;

    Move(int f, int t): from(Square(f)), to(Square(t)) {}

    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const Move& move) {
        
        os << "Move from " << move.from << " to " << move.to;
        return os;
    }

} Move;