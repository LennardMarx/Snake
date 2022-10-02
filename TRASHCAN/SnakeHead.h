#pragma once
#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <utility>
#include <string>
#include "/home/lennardmarx/UTwente/Programming/Snake/include/UI.h"
#include "SnakeSegment.h"

class SnakeHead : public SnakeSegment
{
public:
    SnakeHead();  // constructor
    ~SnakeHead(); // destructor

    // set and get direction
    void setDirection(std::string);
    std::string getDirection();

    void moveSnake(UI &);

    void drawSegment(UI &) override;

private:
    std::string direction;
    bool teleportCheck;
};

#endif