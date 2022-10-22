#include "DataStructures/Game.h"
#include <assert.h>

void updateBoardWithMove(BoardState& board, const Move& move) {

    board.ep = -1; // reset en pessant square. Only overwritten on double pawn jump

    ColorPiece movingPiece = board.pieceAt(move.from);
    ColorPiece capturedPiece = board.pieceAt(move.to);
    setOff(board.pieces[board.otherTurn][capturedPiece.piece], move.to); // Remove captured piece, if any
    setOff(board.pieces[board.turn][movingPiece.piece], move.from); // Remove piece from old square

    if (move.type == PROMOTION) {
        setOn(board.pieces[board.turn][move.promotionPiece], move.to); // Move to new square
    } else {
        setOn(board.pieces[board.turn][movingPiece.piece], move.to); // Move to new square
    }

    // Handle en pessant
    if (move.type == EN_PESSANT) {
        int capturedSquare = move.to - (board.turn == WHITE ? 8 : -8);
        setOff(board.pieces[board.otherTurn][PAWN], capturedSquare);

    } else if (move.type == CASTLE) {

        // Handle moving rook. We know rook old position since castling is legal
        int rookFrom, rookTo;
        if (move.to % 8 == 2) { // castle queenside.
            rookFrom = board.turn == WHITE ? 0 : 56; // Remove rook from A file
            rookTo = board.turn == WHITE ? 3 : 59; // Add rook to D file
        } else if (move.to % 8 == 6) { // castle king side. Remove rook from h file
            rookFrom = board.turn == WHITE ? 7 : 63; //  Remove rook from H file
            rookTo = board.turn == WHITE ? 5 : 61; // Add rook to F file
        } else {
            assert(false); // castling flag is set but not castling either way. something wrong.
        }
        setOff(board.pieces[board.turn][ROOK], rookFrom); 
        setOn(board.pieces[board.turn][ROOK], rookTo);

    } else if (movingPiece.piece == PAWN && (move.from - move.to == 16 || move.from - move.to == -16)) {
        // Create en pessant square if pawn double jumped
        board.ep = (move.from + move.to) / 2;
    }

    // Move king cached position if king is moved
    if (movingPiece.piece == KING) board.kings[board.turn] = move.to;

    // Update castling flags. If rook is not where it started, set to false
    if ( (board.pieces[board.turn][ROOK] & getSingle(board.turn == WHITE ? 0 : 56)) == 0 ) {
        board.queensideCastling[board.turn] = false;
    }
    if ( (board.pieces[board.turn][ROOK] & getSingle(board.turn == WHITE ? 7 : 63)) == 0 ) {
        board.kingsideCastling[board.turn] = false;
    }
    if (board.pieces[board.turn][KING] != getSingleC(board.turn == WHITE ? 4 : 60)) {
        board.queensideCastling[board.turn] = false;
        board.kingsideCastling[board.turn] = false;
    }

    std::swap(board.turn, board.otherTurn);
    board.recalculateAll();

}

// Precondition: assume that move is valid (check happened already)
void Game::makeMove(const Move& move) {
    
    // create a copy of current gamestate for new gamestate
    GameState* newState = new GameState(*current);

    // make move for newState
    updateBoardWithMove(newState->board, move);

    // shift pointer over to new state
    newState->prev = current;
    current = newState;
}

// Pop the top of the linked list and shift back game state pointer by 1 to previous move
void Game::unmakeMove() {
    assert(current != nullptr);
    GameState* previous = current->prev;
    delete current;
    current = previous;
}