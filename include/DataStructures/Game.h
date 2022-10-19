#pragma once

#include "BoardState.h"
#include "Move.h"

// Storing a linked list of board states.
class Game {

public:

    Game(std::string fen) {
        current = new GameState(BoardState(fen));
    }

    Game() {
        current = new GameState(BoardState());
    }

    void makeMove(const Move& move);
    void unmakeMove();
    
    const BoardState& getBoard() { return current->board; }

    ~Game() {
        while (current != nullptr) {
            GameState* prev = current->prev;
            delete current;
            current = prev;
        }
    }

    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const Game& game) {
        os << game.current->board;
        return os;
    }

private:
    typedef struct GameState {
        BoardState board;
        GameState* prev;
        
        GameState(BoardState b): board(b), prev(nullptr) {}

    } GameState;

    GameState* current;



};