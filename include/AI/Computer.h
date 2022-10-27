#pragma once

#include "DataStructures/Game.h"
#include "Algorithms/LegalMoveGenerator.h"
#include "Algorithms/PseudoLegalMoveGenerator.h"

// interface
class Computer {
public:
    virtual const Move search(Game& game) = 0;
    virtual ~Computer() {}
};