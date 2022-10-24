#pragma once

#include "Square.h"
#include "Utility/constants.h"

enum MoveType {NORMAL, EN_PESSANT, CASTLE, PROMOTION};

typedef struct Move {

    int from, to;
    MoveType type;

    Piece promotionPiece = PIECE_ERROR;

    Move(int f, int t, MoveType moveType = NORMAL): from(f), to(t), type(moveType) {}
    Move(Square f, Square t, MoveType moveType = NORMAL): from(f.id), to(t.id), type(moveType) {}

    std::string getName() const {
        return Square(from).getName() + Square(to).getName();
    }


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
            case PROMOTION:
                os << "Promotion";
                break;
            default:
                os << "Castle";
        }
        os << ")";
        return os;
    }

} Move;