/*
 *  Created on: May 14, 2018
 *      Author: Johan Engelen
 *  Ported from D source by same author.
 *  Heavily modified by me!
 * 
 *  Declatation of the UI class to create an interface
 */

#ifndef SRC_UI_H_
#define SRC_UI_H_

#include <SDL2/SDL.h>

class UI
{
public:
    const int sizeX;
    const int sizeY;

    UI(int, int); // constructor
    ~UI();        // desctructor

    void clear();   // makes screen black
    void present(); // renders visualized things

    // 9x9 "pixel"
    void drawPixel(int, int);
    // 7x7 "pixel"
    void drawSmallPixel(int, int);
    // 9x9 "circle"
    void drawCircle(int, int);

    // changing the draw color on the go
    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    SDL_Renderer *&getRenderer(); // pointer reference to the renderer
    SDL_Window *getWindow();      // pointer to the window

private:
    void initialize(int, int);

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
};

#endif /* SRC_UI_H_ */