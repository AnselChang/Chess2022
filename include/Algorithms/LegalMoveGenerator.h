#pragma once

#include "DataStructures/Game.h"
#include "PseudoLegalMoveGenerator.h"
#include <vector>

// Check for whether pseudo-legal moves are legal -> whether the king is in check for the resultant board
// We're checking if the current player is checking the other player
bool isLegal(const BoardState& boardState) {
    
    // Pawn checks. If the bitboard of the possible pawn checks with the king intersects the pawns, then check detected
    if (arrPawnAttacks[boardState.otherTurn][boardState.kings[boardState.otherTurn]] & boardState.pieces[boardState.turn][PAWN]) {
        return false;
    }

    // Knight checks. If the bitboard of the possible knight checks with the king intersects the knights, then check detected
    if (arrKnightAttacks[boardState.kings[boardState.otherTurn]] & boardState.pieces[boardState.turn][KNIGHT]) {
        return false;
    }

    // King checks. If the bitboard of the possible knight checks with the king intersects the knights, then check detected
    if (arrKingAttacks[boardState.kings[boardState.otherTurn]] & boardState.pieces[boardState.turn][KING]) {
        return false;
    }

    // Rook/Queen orthogonal checks

    // The bitmask of squares, including pieces, that can reach king orthogonally
    uint64_t reachable = getOrthogonalTargets(~boardState.empty, boardState.kings[boardState.otherTurn]);
    // the bitmask of pieces that can orthogonally attack the king
    uint64_t possibleAttackers = boardState.pieces[boardState.turn][ROOK] | boardState.pieces[boardState.turn][QUEEN];

    // The intersection of the two bitmasks are pieces that are currently attacking the king. If so, check and therefore illegal
    if ((reachable & possibleAttackers) != 0) return false;

    // Bishop/Queen diagonal checks

    // The bitmask of squares, including pieces, that can reach king diagonally
    reachable = getDiagonalTargets(~boardState.empty, boardState.kings[boardState.otherTurn]);
    // the bitmask of pieces that can orthogonally attack the king
    possibleAttackers = boardState.pieces[boardState.turn][BISHOP] | boardState.pieces[boardState.turn][QUEEN];

    // The intersection of the two bitmasks are pieces that are currently attacking the king. If so, check and therefore illegal
    if ((reachable & possibleAttackers) != 0) return false;

    // No checks, so position is legal
    return true;

}

// Generate pseudo-legal moves, and then remove non-legal moves from move list
std::vector<Move> generateLegalMoves(Game& game) {

    std::vector<Move> moves = generatePseudoLegalMoves(game.getBoard());
    
    for (auto iter = moves.begin(); iter != moves.end(); ) {

        game.makeMove(*iter);

        if (isLegal(game.getBoard())) iter++;
        else {
            std::cout << "Illegal: " << *iter << std::endl;
            iter = moves.erase(iter);
        }

        game.unmakeMove();

    }

    return moves;

}

