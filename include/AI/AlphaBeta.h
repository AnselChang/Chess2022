#pragma once

#include <cstdlib>
#include "Utility/limits.h"

#include "Computer.h"

class AlphaBeta : public Computer {
public:

    int nodesSearched = 0;

    AlphaBeta(int searchDepth): depth(searchDepth) {}

    const Move search(Game& game) {

        nodesSearched = 0;

        std::vector<Move> moves = generateLegalMoves(game);

        Move& bestMove = moves[0];
        float bestEval = F_MIN;

        for (Move& move : moves) {
            game.makeMove(move);

            float eval = alphaBeta(game, F_MIN, F_MAX, depth - 1) * (game.getBoard().turn == WHITE ? -1 : 1);
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

    float alphaBeta(Game& game, int alpha, int beta, int remainingDepth) {

        nodesSearched++;

        // Base case at leaf node. evaluate node statically
        if(remainingDepth == 0) return game.getBoard().evaluate() * (game.getBoard().turn == WHITE ? 1 : -1);

        for (const Move& move : generatePseudoLegalMoves(game.getBoard()) )  {

            game.makeMove(move);

            if (!isLegal(game.getBoard())) {
                game.unmakeMove();
                continue;
            }
            
            float score = -alphaBeta(game, -beta, -alpha, remainingDepth - 1);
            if (remainingDepth == 1) std::cout << "\t";
            //std::cout << "\t" << move << ": " << score << "\n";
            if (score >= beta) {
                game.unmakeMove();
                return beta;   //  fail hard beta-cutoff
            } else if (score > alpha) {
                alpha = score; // alpha acts like max in MiniMax
            }

            game.unmakeMove();

            
        }
        return alpha;
    }

private:
    int depth;
};

