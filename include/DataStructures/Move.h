#pragma once

#include "Square.h"

enum MoveType {NORMAL, EN_PESSANT, CASTLE};

typedef struct Move {

    int from, to;
    MoveType type = NORMAL;

    Move(int f, int t): from(f), to(t) {}
    Move(int f, int t, MoveType moveType): from(f), to(t), type(moveType) {}
    Move(Square f, Square t): from(f.id), to(t.id) {}


    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const Move& move) {
        
        os << "Move from " << Square(move.from).getName() << " to " << Square(move.to).getName();
        return os;
    }

} Move;