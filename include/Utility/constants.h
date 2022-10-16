#pragma once

enum Piece {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, PIECE_ERROR};
constexpr int NUM_PIECES = 6;

enum Color {WHITE, BLACK, COLOR_ERROR};

typedef struct ColorPiece {
    Color color;
    Piece piece;

    ColorPiece(int c, int p):
        color(static_cast<Color>(c)),
        piece(static_cast<Piece>(p))
    {}

    char getSymbol() const {

        // null piece
        if (color == COLOR_ERROR || piece == PIECE_ERROR) return '-';

        char c;
        switch (piece) {
            case PAWN:
                c = 'P';
                break;
            case KNIGHT:
                c = 'N';
                break;
            case BISHOP:
                c = 'B';
                break;
            case ROOK:
                c = 'R';
                break;
            case QUEEN:
                c = 'Q';
                break;
            default:
                c = 'K';
        };

        // make lowercase if black
        if (color == BLACK) c += 32;

        return c;
    }

    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const ColorPiece& cp) {
        os << cp.getSymbol();
        return os;
    }

} ColorPiece;