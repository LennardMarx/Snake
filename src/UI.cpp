/*
 *  Created on: May 14, 2018
 *      Author: Johan Engelen
 *  Ported from D source by same author.
 *  Heavily modified by me!
 * 
 *  Methods to inizialize the UI with the window and renderer
 *  as well as methods to draw pixels manually on the screen.
 */

#include "../include/UI.h"

// constructor
UI::UI(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY)
{
    initialize(sizeX, sizeY); // calling the initialize method with the given size
}

// destructor
UI::~UI()
{
    if (renderer)
        SDL_DestroyRenderer(renderer); // clean up renderer
    if (window)
        SDL_DestroyWindow(window); // clean up window
    SDL_Quit(); // quit SDL2
}

// making everything black
void UI::clear()
{
    setDrawColor(0, 0, 0, 255);
    SDL_RenderClear(renderer);
    setDrawColor(255, 255, 255, 255);
}

// showing everything rendered
void UI::present()
{
    SDL_RenderPresent(renderer);
}

// 9x9 "pixel"
void UI::drawPixel(int x, int y)
{
    for (int i = x - 4; i <= x + 4; ++i)
    {
        for (int j = y - 3; j <= y + 3; ++j)
        {
            SDL_RenderDrawPoint(renderer, i + sizeX / 2, j + sizeY / 2);
        }
    }
    for (int i = x - 3; i <= x + 3; ++i)
    {
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y - 4) + sizeY / 2);
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y + 4) + sizeY / 2);
    }
}

// 7x7 "pixel"
void UI::drawSmallPixel(int x, int y)
{
    for (int i = x - 3; i <= x + 3; ++i)
    {
        for (int j = y - 2; j <= y + 2; ++j)
        {
            SDL_RenderDrawPoint(renderer, i + sizeX / 2, j + sizeY / 2);
        }
    }
    for (int i = x - 2; i <= x + 2; ++i)
    {
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y - 3) + sizeY / 2);
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y + 3) + sizeY / 2);
    }
}

// 9x9 "circle"
void UI::drawCircle(int x, int y)
{
    for (int i = x - 1; i <= x + 1; ++i)
    {
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y - 4) + sizeY / 2);
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y + 4) + sizeY / 2);
    }
    for (int i = x - 2; i <= x + 2; ++i)
    {
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y - 3) + sizeY / 2);
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y + 3) + sizeY / 2);
    }
    for (int i = x - 3; i <= x + 3; ++i)
    {
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y - 2) + sizeY / 2);
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y + 2) + sizeY / 2);
    }
    for (int i = x - 4; i <= x + 4; ++i)
    {
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y - 1) + sizeY / 2);
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, y + sizeY / 2);
        SDL_RenderDrawPoint(renderer, i + sizeX / 2, (y + 1) + sizeY / 2);
    }
}

// changing draw color on the go
void UI::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

// initializing window, renderer and setting size / position
void UI::initialize(int sizeX, int sizeY)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    // Create a Window
    window = SDL_CreateWindow("Snake", 0, 0, sizeX, sizeY, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //  | SDL_RENDERER_PRESENTVSYNC

    // scale window
    SDL_SetWindowSize(window, sizeX * 3, sizeY * 3);
    // adjust render scale
    SDL_RenderSetScale(renderer, 3, 3);
    // place window in middle of screen after scaling
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

SDL_Renderer *&UI::getRenderer() // pointer reference to the renderer
{
    return renderer;
}
SDL_Window *UI::getWindow() // pointer to the window
{
    return window;
}
