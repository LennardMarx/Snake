#pragma once
#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>
#include <utility>
#include <string>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include <fstream>
#include <algorithm>

#include "/home/lennardmarx/UTwente/Programming/Snake/include/GameObjects.h"
#include "/home/lennardmarx/UTwente/Programming/Snake/include/UI.h"
#include "../include/ResourceManager.hpp"
#include "../include/TexturedRectangle.hpp"
#include "../include/Text.h"

class Game
{
public:
    Game();
    ~Game();
    void play();
};

#endif