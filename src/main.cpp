#include <iostream>
#include <memory>
#include "DataStructures/BoardState.h"
#include "DataStructures/Game.h"
#include "Algorithms/LegalMoveGenerator.h"
#include "Algorithms/PseudoLegalMoveGenerator.h"
#include "Utility/Bitwise/tables.h"
#include "AI/Computer.h"
#include "AI/Random.h"

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

Color userSelectColor() {
    using namespace std;

    std::string input;
    while (true) {
        cout << "Select White (w) or Black (b): " << endl;
        cin >> input;
        if (input.find('w') != std::string::npos) return WHITE;
        else if (input.find('b') != std::string::npos) return BLACK;
        cout << "Error: Enter 'w' or 'b'." << endl;
    }

}

const Move getLegalUserMove(Game& game, std::vector<Move>& legalMoves) {
    using namespace std;

    std::string input;
    while (true) {
        cout << "Enter valid move: " << endl;
        cin >> input;

        for (const Move& move : legalMoves) {
            if (move.getName() == input) return move;
        }
        
        cout << "Error: Invalid move." << endl;
    }
}

void playUserAgainstComputer(Computer* computer) { 

    using namespace std;

    Game game("4k3/4P3/4K3/8/8/8/8/8 b - - 0 1");

    Color userColor = userSelectColor();

    cout << "You selected: " << (userColor == WHITE ? "White" : "Black") << endl;

    while (true) { // game termination

        std::vector<Move> legalMoves = generateLegalMoves(game);

        if (game.getBoard().turn == userColor) { // User's turn
            
            if (legalMoves.size() == 0) {

                if (!isCurrentKingInCheck(game)) cout << "Stalemate." << endl;
                else cout << "Checkmate. Computer (" << (userColor == WHITE ? "Black" : "White") << ") wins!" << endl;
                break;
            }

            const Move userMove = getLegalUserMove(game, legalMoves);
            game.makeMove(userMove);
            cout << game << "\n" << "You moved: " << userMove << endl;
        }
        else {

            if (legalMoves.size() == 0) {

                if (!isCurrentKingInCheck(game)) cout << "Stalemate." << endl;
                else cout << "Checkmate. You (" << (userColor == WHITE ? "White" : "Black") << ") win!" << endl;
                break;
            }

            const Move computerMove = computer->search(game);
            game.makeMove(computerMove);
            cout << game << "\n" << "Computer moved: " << computerMove << endl;

        }

    }

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

    //test_perft(6);

    unique_ptr<Computer> computer = make_unique<Random>();
    playUserAgainstComputer(computer.get());

    // Game game("rnbq1bnr/pppppppp/8/4k3/1N2PRQ1/3KB2B/PPP1PPPP/RN6 b Aha - 0 1");
    // cout << game << endl;

    // for (const Move& m : generateLegalMoves(game)) {
    //     cout << m << endl;
    // }

    //game.makeMove(Move(Square("e5"), Square("f6"), EN_PESSANT));
    //cout << game << endl;

    
}
