#pragma once

#include "Square.h"

enum MoveType {NORMAL, EN_PESSANT, CASTLE};

typedef struct Move {

    int from, to;
    MoveType type;

    Move(int f, int t, MoveType moveType = NORMAL): from(f), to(t), type(moveType) {}
    Move(Square f, Square t, MoveType moveType = NORMAL): from(f.id), to(t.id), type(moveType) {}


    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const Move& move) {
        os << "Move from " << Square(move.from).getName() << " to " << Square(move.to).getName() << " (";
        switch (move.type) {
            case NORMAL:
                os << "Normal";
                break;
            case EN_PESSANT:
                os << "En pessant";
                break;
            default:
                os << "Castle";
        }
        os << ")";
        return os;
    }

} Move;