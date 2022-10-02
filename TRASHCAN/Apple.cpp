#include "/home/lennardmarx/UTwente/Programming/Snake/include/Apple.h"

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
