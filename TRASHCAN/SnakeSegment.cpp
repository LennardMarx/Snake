#include "/home/lennardmarx/UTwente/Programming/Snake/include/SnakeSegment.h"

SnakeSegment::SnakeSegment() // constructor
{
}
SnakeSegment::~SnakeSegment() // destructor
{
}

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