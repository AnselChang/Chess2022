#pragma once

#include "BoardState.h"
#include "Move.h"

// Storing a linked list of board states.
class Game {

public:

    void makeMove(const Move& move);
    void unmakeMove();

private:
    typedef struct GameState {
        BoardState board;
        GameState* prev;
    } GameState;

    GameState* current;

};