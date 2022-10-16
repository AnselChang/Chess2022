#include "DataStructures/BoardState.h"

BoardState::BoardState(std::string fen) {

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < NUM_PIECES; j++)
            pieces[i][j] = 0;

    std::cout << fen << std::endl;

    int y = 7;
    int x = 0;

    int i = 0;
    // Calculate board position
    while (i < fen.size() && fen.at(i) != ' ') {

        char c = fen.at(i);
        if (c == '/') { // Go down one row
            y--;
            x = 0;
        } else if (c >= 49 && c <= 56) { // is number, shift x that amount
            x += c - 48;
        } else { // if a piece, figure out which color and piece it is, and set corresponding bit
            ColorPiece cp(c);
            pieces[cp.color][cp.piece] = setOn(pieces[cp.color][cp.piece], y*8 + x);
            x += 1;
        }
        i += 1;
    }

    if (i == fen.size()) {
        kingsideCastling = {true, true};
        queensideCastling = {true, true};
        turn = WHITE;
    } else {

        // Calculate who's turn
        i++; // i now at w or b
        turn = (fen.at(i) == 'w') ? WHITE : BLACK;
        i++; // i now at castling

        // Calculate castling
        std::string castling = fen.substr(i, fen.find(" ", i)); // substring of just the castling portion
        kingsideCastling[WHITE] = castling.find('K') != std::string::npos;
        queensideCastling[WHITE] = castling.find('Q') != std::string::npos;
        kingsideCastling[BLACK] = castling.find('k') != std::string::npos;
        queensideCastling[BLACK] = castling.find('q') != std::string::npos;
    }

    epSquare = 0;

    recalculateAll();

}


void BoardState::recalculateAll() {
    all[WHITE] = pieces[WHITE][PAWN]; // copy by value
    all[BLACK] = pieces[BLACK][PAWN];

    for (int i = 1; i < NUM_PIECES; i++) {
        all[WHITE] += pieces[WHITE][i];
        all[BLACK] += pieces[BLACK][i];
    }

    empty = ~(all[WHITE] + all[BLACK]);

}

// Get color and piece at 0-63 index
ColorPiece BoardState::pieceAt(int index) const {
    for (int color = 0; color < 2; color++) {
        for (int piece = 0; piece < NUM_PIECES; piece++) {
            if (get(pieces[color][piece], index) == 1) {
                return {color, piece};
            }
        }
    }
    return {COLOR_ERROR, PIECE_ERROR};
}

void BoardState::removePiece(ColorPiece cp, int location) {
    pieces[cp.color][cp.piece] = setOff(pieces[cp.color][cp.piece], location);
}

void BoardState::addPiece(ColorPiece cp, int location) {
    pieces[cp.color][cp.piece] = setOn(pieces[cp.color][cp.piece], location);
}