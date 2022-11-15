#pragma once

#include <cstdlib>
#include "Utility/limits.h"

#include "Computer.h"

class Minimax : public Computer {
public:

    int nodesSearched = 0;

    Minimax(int searchDepth): depth(searchDepth) {}

    const Move search(Game& game) {

        nodesSearched = 0;

        std::vector<Move> moves = generateLegalMoves(game);

        Move& bestMove = moves[0];
        float bestEval = F_MIN;

        for (Move& move : moves) {
            game.makeMove(move);

            float eval = minimax(game, depth - 1) * (game.getBoard().turn == WHITE ? -1 : 1);
            //std::cout << move << ": " << eval << "\n";
            if (eval > bestEval) {
                bestEval = eval;
                bestMove = move;
            }

            game.unmakeMove();
        }

        std::cout << "Nodes searched: " << nodesSearched << std::endl;
        return bestMove;
    }

    float minimax(Game& game, int remainingDepth) {

        nodesSearched++;

        // Base case at leaf node. evaluate node statically
        if(remainingDepth == 0) return game.getBoard().evaluate() * (game.getBoard().turn == WHITE ? 1 : -1);

        int max = F_MIN;

        for (const Move& move : generateLegalMoves(game) )  {

            game.makeMove(move);
            
            float score = -minimax(game, remainingDepth - 1);
            //if (remainingDepth == 1) std::cout << "\t";
            //std::cout << "\t" << move << ": " << score << "\n";
            if (score > max) {
                max = score;
            }

            game.unmakeMove();

            
        }
        return max;
    }

private:
    int depth;
};

