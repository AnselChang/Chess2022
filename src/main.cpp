#include <iostream>
#include "DataStructures/BoardState.h"
#include "DataStructures/Game.h"
#include "Algorithms/MoveGenerator.h"
#include "Utility/Bitwise/tables.h"

// Return the number of possible positions given a starting position and a depth
long long perft(Game& game, int depth) {

    int nodes = 0;

    if (depth == 0) return 1;

    std::vector<Move> moves = generateMoves(game.getBoard());
    for (const Move& move : moves) {
        game.makeMove(move);
        nodes += perft(game, depth - 1);
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

    //test_perft(3);

    Game game("rnbqkbnr/1pppp1pp/p7/4Pp2/8/8/PPPP1PPP/RNBQKBNR w KQkq f6 0 3");
    cout << game << endl;

    // for (const Move& m : generateMoves(game.getBoard())) {
    //     cout << m << endl;
    // }

    game.makeMove(Move(Square("e5"), Square("f6"), EN_PESSANT));
    cout << game << endl;

    
}
