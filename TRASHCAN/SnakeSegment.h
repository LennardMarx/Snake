#pragma once
#ifndef SEGMENT_H
#define SEGMENT_H
#include <utility>
#include "/home/lennardmarx/UTwente/Programming/Snake/include/UI.h"

class SnakeSegment
{
public:
    SnakeSegment();  // constructor
    ~SnakeSegment(); // destructor

    // set and get position
    void setPosition(int, int);
    std::pair<int, int> getPosition();

    // set and get previous position
    void setPreviousPosition();
    std::pair<int, int> getPreviousPosition();

    // draw snake segment
    virtual void drawSegment(UI &);

protected:
    int x, y, x2, y2;
};

#endif