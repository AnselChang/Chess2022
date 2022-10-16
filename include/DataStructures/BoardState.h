#pragma once

#include <array>
#include "Bitboard.h"
#include "Utility/constants.h"

class BoardState {

public:

    static BoardState empty() { return BoardState(); }
    static BoardState newGame() { return BoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"); }

    BoardState(std::string fen) {

        int y = 7;
        int x = 0;

        for (char c : fen) {
            if (c == '/') { // Go down one row
                y--;
                x = 0;
            } else if (c >= 49 && c <= 56) { // is number, shift x that amount
                x += c - 48;
            } else { // if a piece, figure out which color and piece it is, and set corresponding bit
                ColorPiece cp(c);
                pieces[cp.color][cp.piece].set(y*8 + x);
                x += 1;
            }
        }
        recalculateAll();

    }
    BoardState() {}

    void recalculateAll() {
        all[WHITE] = pieces[WHITE][PAWN]; // copy by value
        all[BLACK] = pieces[BLACK][PAWN];

        for (int i = 1; i < NUM_PIECES; i++) {
            all[WHITE] += pieces[WHITE][i];
            all[BLACK] += pieces[BLACK][i];
        }
    }

    // Get color and piece at 0-63 index
    ColorPiece pieceAt(int index) const {
        for (int color = 0; color < 2; color++) {
            for (int piece = 0; piece < NUM_PIECES; piece++) {
                if (pieces[color][piece].get(index) == 1) {
                    return {color, piece};
                }
            }
        }
        return {COLOR_ERROR, PIECE_ERROR};
    }

    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const BoardState& boardState) {
        
        for (int y = 7; y >= 0; y--) {
            os << "\n";
            for (int x = 0; x < 8; x++) {
                os << boardState.pieceAt(y*8 + x) << " ";
            }
        }
        os << std::endl;
        return os;
    }

private:

    std::array<std::array<Bitboard, NUM_PIECES>, 2> pieces;
    std::array<Bitboard, 2> all;

};