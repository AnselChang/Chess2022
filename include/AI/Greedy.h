#pragma once

#include <cstdlib>
#include <limits>

#include "Computer.h"

class Greedy : public Computer {
public:
    const Move search(Game& game) {

        std::vector<Move> moves = generateLegalMoves(game);

        Move& bestMove = moves[0];
        float bestEval = std::numeric_limits<float>::min();

        for (Move& move : moves) {
            game.makeMove(move);

            float eval = game.getBoard().relEval * (game.getBoard().turn == WHITE ? -1 : 1);
            if (eval > bestEval) {
                bestEval = eval;
                bestMove = move;
            }

            game.unmakeMove();
        }

        return bestMove;
    }
};