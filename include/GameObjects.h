#pragma once

#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <utility>
#include <string>
#include "../include/UI.h"

//=============== Apple =============================================

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

//=============== Snake Segment ==================================

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
    int x, y, x2, y2; // protected member variable to store coordinates
};

//=============== Snake Head ====================================
// inherited from SnakeSegment

class SnakeHead : public SnakeSegment
{
public:
    SnakeHead();  // constructor
    ~SnakeHead(); // destructor

    // set and get direction
    void setDirection(std::string);
    std::string getDirection();

    // moving snake into set direction
    void moveSnake(UI &);

    // polymorphism from inherited drawSegment to have different "Sprite" for the head
    void drawSegment(UI &) override;

private:
    std::string direction; // saving current direction
    bool teleportCheck;    // check if snake "teleports" from wall to wall (borderless)
};

#endif