#pragma once

#include <iostream>
#include <string>

/*
black
56 57 58 59 60 61 62 63
...
08 09 10 11 12 13 14 15
00 01 02 03 04 05 06 07
white
*/

class Square {

public:

    explicit Square(int pos0to63): id(pos0to63) {}

    // x is 0 left, 7 right. y is 0 white (bottom), 7 black (top)
    explicit Square(int x, int y): id(y*8 + x) {}

    // lowercase 'a' = 97
    explicit Square(std::string name): id( ((int) name.at(0)) - 97 + ((int) name.at(1) - 49)*8 ) {}

    std::string getName() const {
        int row = id / 8;
        int column = id % 8;
        char c = column + 97;
        return std::string(1, c) + std::to_string(row+1);
    }

    // Overload printing
    friend std::ostream& operator<<(std::ostream& os, const Square& sq) {
        //os << "Square(" << sq.id << ") at " << sq.getName();
        os << sq.getName();
        return os;
    }

    int id;
};