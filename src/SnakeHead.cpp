#include "/home/lennardmarx/UTwente/Programming/Snake/include/SnakeHead.h"
#include "/home/lennardmarx/UTwente/Programming/Snake/include/SnakeSegment.h"
#include "/home/lennardmarx/UTwente/Programming/Snake/include/UI.h"

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