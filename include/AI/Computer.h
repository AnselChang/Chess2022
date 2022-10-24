#pragma once

#include "DataStructures/Game.h"

// interface
class Computer {
public:
    virtual const Move search(Game& game) = 0;
    virtual ~Computer() {}
};