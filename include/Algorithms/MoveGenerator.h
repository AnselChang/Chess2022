#pragma once

#include <vector>
#include "DataStructures/BoardState.h"
#include "DataStructures/Move.h"

#include "Utility/Bitwise/pawns.h"
#include "Utility/Bitwise/bitscan.h"
#include "Utility/Bitwise/tables.h"

void generatePawnPushes(const BoardState& board, std::vector<Move>& moves) {
    uint64_t singleTargets = board.turn == WHITE ? wSinglePushTargets(board.pieces[WHITE][PAWN], board.empty) : bSinglePushTargets(board.pieces[BLACK][PAWN], board.empty);
    uint64_t doubleTargets = board.turn == WHITE ? wDblPushTargets(board.pieces[WHITE][PAWN], board.empty) : bDblPushTargets(board.pieces[BLACK][PAWN], board.empty);
    std::cout << board << std::endl;
    print(singleTargets);
    print(doubleTargets);

    int delta = board.turn == WHITE ? -8 : 8;
    while (singleTargets != 0) {
        int index = bitScanForwardWithReset(singleTargets);
        moves.emplace_back(index + delta, index);
    }

    while (doubleTargets != 0) {
        int index = bitScanForwardWithReset(doubleTargets);
        moves.emplace_back(index + delta*2, index);
    }
}

void generatePawnAttacks(const BoardState& board, std::vector<Move>& moves) {
    uint64_t capturesLeft, capturesRight;
    int delta;
    if (board.turn == WHITE) {
        delta = -8;
        uint64_t capturable = board.all[BLACK] | board.epSquare; // en pessant square is a "capturable" square
        capturesRight = wPawnEastAttacks(board.pieces[WHITE][PAWN]) & capturable;
        capturesLeft = wPawnWestAttacks(board.pieces[WHITE][PAWN]) & capturable;


    }
    else {
        delta = 8;
        uint64_t capturable = board.all[WHITE] | board.epSquare;
        capturesRight = bPawnEastAttacks(board.pieces[BLACK][PAWN]) & capturable;
        capturesLeft = bPawnWestAttacks(board.pieces[BLACK][PAWN]) & capturable;
    }

    while (capturesRight != 0) {
        int index = bitScanForwardWithReset(capturesRight);
        moves.emplace_back(index + delta - 1, index);
    }

    while (capturesLeft != 0) {
        int index = bitScanForwardWithReset(capturesLeft);
        moves.emplace_back(index + delta + 1, index);
    }
}

void generateKnightMoves(const BoardState& board, std::vector<Move>& moves) {

    uint64_t knights = board.pieces[board.turn][KNIGHT];
    while (knights != 0) {
        int knightStart = bitScanForwardWithReset(knights);
        uint64_t possibleMoves = arrKnightAttacks[knightStart] & ~board.all[board.turn]; // can move anywhere except own pieces
        while (possibleMoves != 0) {
            int knightEnd = bitScanForwardWithReset(possibleMoves);
            moves.emplace_back(knightStart, knightEnd);
        }
    }
}

void generateKingMoves(const BoardState& board, std::vector<Move>& moves) {

    int kingStart = bitScanForward(board.pieces[board.turn][KING]);
    uint64_t possibleMoves = arrKingAttacks[kingStart] & ~board.all[board.turn]; // can move anywhere except own pieces
    while (possibleMoves != 0) {
        int kingEnd = bitScanForwardWithReset(possibleMoves);
        moves.emplace_back(kingStart, kingEnd);
    }
}

std::vector<Move> generateMoves(const BoardState& board) {
    std::vector<Move> moves;


    
    generatePawnPushes(board, moves);
    generatePawnAttacks(board, moves);
    generateKnightMoves(board, moves);
    generateKingMoves(board, moves);

    return moves; // RVO

}
