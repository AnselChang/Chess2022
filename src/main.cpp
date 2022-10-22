#include <iostream>
#include "DataStructures/BoardState.h"
#include "DataStructures/Game.h"
#include "Algorithms/LegalMoveGenerator.h"
#include "Algorithms/PseudoLegalMoveGenerator.h"
#include "Utility/Bitwise/tables.h"

// Return the number of possible positions given a starting position and a depth
long long perft(Game& game, int depth) {

    int nodes = 0;

    if (depth == 0) return 1;

    std::vector<Move> moves = generatePseudoLegalMoves(game.getBoard());
    for (const Move& move : moves) {
        game.makeMove(move);

        if (isLegal(game.getBoard())) {
            nodes += perft(game, depth - 1);
        }
        
        game.unmakeMove();
    }
    return nodes;
}

void test_perft(int depth) {
    std::cout << "Testing perft(" << depth << "):" << "\n";
    Game game;
    std::cout << perft(game, depth) << std::endl;
}

int main() {

    using namespace std;

    initLookupTables();

    //BoardState b;
    //std::cout << b << std::endl;
    //std::cout << "start" << std::endl;
    //BoardState b("rnb1kb1r/ppqppp2/2p3P1/8/7p/4P2P/PPQP2P1/RNB1KB1R w KQkq - 0 11");
    //std::cout << b << std::endl;

    //Game game("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8  ");
    //cout << perft(game, 1) << endl;

    test_perft(3);

    // Game game("rnbq1bnr/pppppppp/8/4k3/1N2PRQ1/3KB2B/PPP1PPPP/RN6 b Aha - 0 1");
    // cout << game << endl;

    // for (const Move& m : generateLegalMoves(game)) {
    //     cout << m << endl;
    // }

    //game.makeMove(Move(Square("e5"), Square("f6"), EN_PESSANT));
    //cout << game << endl;

    
}
