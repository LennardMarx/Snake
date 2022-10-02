#include "GameObjects.h"

//============ Apple ===========================s

Apple::Apple() {}
Apple::~Apple() {}

// set random position
void Apple::setRandPosition(UI &ui)
{
    x = (rand() % ((ui.sizeX) / 9) - ((ui.sizeX / 2) / 9)) * 9 + 4;
    y = (rand() % ((ui.sizeY) / 9) - ((ui.sizeY / 2) / 9)) * 9 + 4;
}

// get position
std::pair<int, int> Apple::getPosition()
{
    std::pair<int, int> pos(x, y);
    return pos;
}

// draw the apple
void Apple::drawApple(UI &ui)
{
    ui.drawCircle(x, y);
}

//============= Snake Segment ======================

SnakeSegment::SnakeSegment() // constructor
{
}
SnakeSegment::~SnakeSegment() // destructor
{
}

// set and get segment position
void SnakeSegment::setPosition(int _x, int _y)
{
    setPreviousPosition();
    x = _x;
    y = _y;
}
std::pair<int, int> SnakeSegment::getPosition()
{
    std::pair<int, int> pos(x, y);
    return pos;
}

// set and get previous position
void SnakeSegment::setPreviousPosition()
{
    x2 = x;
    y2 = y;
}
std::pair<int, int> SnakeSegment::getPreviousPosition()
{
    std::pair<int, int> prevPos(x2, y2);
    return prevPos;
}

// draw snake segment
void SnakeSegment::drawSegment(UI &ui)
{
    ui.drawSmallPixel(x, y);
}

//================ Snake Head ==================================

SnakeHead::SnakeHead() {} // : SnakeSegment() {}
SnakeHead::~SnakeHead() {}

// set and get direction
void SnakeHead::setDirection(std::string _direction)
{
    direction = _direction;
}
std::string SnakeHead::getDirection()
{
    return direction;
}

// moving snake head into set position
void SnakeHead::moveSnake(UI &ui)
{
    // let snake appear at other side of screen
    teleportCheck = false; // check if snake teleported
    if (getPosition().first > (ui.sizeX / 2))
    {
        setPosition(-(ui.sizeX / 2) + 4, y);
        teleportCheck = true;
    }
    else if (getPosition().first < -(ui.sizeX / 2))
    {
        setPosition((ui.sizeX / 2) - 5, y);
        teleportCheck = true;
    }
    else if (getPosition().second > (ui.sizeY / 2))
    {
        setPosition(x, -(ui.sizeY / 2) + 4);
        teleportCheck = true;
    }
    else if (getPosition().second < -(ui.sizeY / 2))
    {
        setPosition(x, (ui.sizeY / 2) - 5);
        teleportCheck = true;
    }

    // only move if not teleported
    if (!teleportCheck)
    {
        // update position according to direction
        if (direction == "up")
        {
            setPosition(x, y - 9);
        }
        else if (direction == "right")
        {
            setPosition(x + 9, y);
        }
        else if (direction == "down")
        {
            setPosition(x, y + 9);
        }
        else if (direction == "left")
        {
            setPosition(x - 9, y);
        }
        else if (direction == "stop")
        {
            setPosition(x, y);
        }
    }
}

// overridden drawSegment to have head bigger than segments
void SnakeHead::drawSegment(UI &ui)
{
    ui.drawPixel(x, y);
}