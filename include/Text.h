#pragma once
#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../include/UI.h"

class Text
{
public:
    Text(std::string, int, int, int, int, char, UI &); // constructor
    ~Text();

    void renderCopy(UI &);

    void rectPosition(int, int, int, int);

private:
    SDL_Rect Text_rect;
    TTF_Font *myFont = TTF_OpenFont("/home/lennardmarx/UTwente/Programming/Snake/Images/RetroGaming.ttf", 32);

    // choice of text colors
    SDL_Color White = {255, 255, 255, 255};
    SDL_Color Yellow = {251, 211, 17, 255};
    SDL_Color color;

    // surface and texture pointers
    SDL_Surface *surfaceMessage;
    SDL_Texture *Message;

    // const char pointer needed to convert the Text
    const char *text_to_char;
};

#endif