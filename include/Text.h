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

    // void setFont(const char *);
    const char *getFont();

private:
    SDL_Rect Text_rect;

    std::string base_path = SDL_GetBasePath();
    std::string rel_path = "Images/RetroGaming.ttf";
    std::string total_path = base_path + rel_path;
    const char *path = total_path.c_str();
    TTF_Font *myFont = TTF_OpenFont(path, 32);

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