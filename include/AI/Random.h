#pragma once

#include <cstdlib>

#include "Computer.h"

class Random : public Computer {
public:
    const Move search(Game& game) {

        std::vector<Move> moves = generateLegalMoves(game);

        int randomIndex = std::rand() % moves.size();

        return moves[randomIndex];
    }
};