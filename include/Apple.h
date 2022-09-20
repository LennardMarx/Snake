#pragma once

#ifndef APPLE_H
#define APPLE_H

#include "/home/lennardmarx/UTwente/Programming/Snake/include/UI.h"
#include <utility>

class Apple
{
public:
    Apple();
    ~Apple();
    // set random position
    void setRandPosition(UI &ui);

    // get position
    std::pair<int, int> getPosition();

    // draw the apple
    void drawApple(UI &ui);

private:
    int x, y;
};

#endif