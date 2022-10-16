#include "DataStructures/Game.h"
#include <assert.h>

// Precondition: assume that move is valid (check happened already)
void Game::makeMove(const Move& move) {
    
    // create a copy of current gamestate for new gamestate
    GameState* newState = new GameState(*current);

    // make move for newState
    // TODO

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