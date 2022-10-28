#pragma once

#include <array>
#include "Utility/Bitwise/common.h"
#include "Utility/constants.h"
#include "DataStructures/Square.h"

class BoardState {

public:

    BoardState(std::string fen);
    BoardState():
        BoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1")
    {}


    void recalculateAll();

    // Get color and piece at 0-63 index
    ColorPiece pieceAt(int index) const;

    void removePiece(ColorPiece cp, int location);
    void addPiece(ColorPiece cp, int location);


    std::array<uint64_t, NUM_PIECES>& myPieces() {return pieces[turn]; };

    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const BoardState& boardState) {
        
        for (int y = 7; y >= 0; y--) {
            os << "\n";
            for (int x = 0; x < 8; x++) {
                os << boardState.pieceAt(y*8 + x) << " ";
            }
        }
        os << "\n";
        if (boardState.kingsideCastling[WHITE]) os << "K";
        if (boardState.queensideCastling[WHITE]) os << "Q";
        if (boardState.kingsideCastling[BLACK]) os << "k";
        if (boardState.queensideCastling[BLACK]) os << "q";
        os << "\nEvaluation: " << boardState.relEval;
        os << "\n" << (boardState.turn == WHITE ? "White" : "Black") << " to move" << std::endl;
        return os;
    }

    std::array<std::array<uint64_t, NUM_PIECES>, 2> pieces;
    std::array<uint64_t, 2> all;
    uint64_t empty;
    int ep = -1; // en pessant square, for when previous move was a double pawn jump

    float relEval = 0; // relative evaluation

    Color turn;
    Color otherTurn;
    std::array<bool, 2> queensideCastling;
    std::array<bool, 2> kingsideCastling;
    std::array<int, 2> kings;

};