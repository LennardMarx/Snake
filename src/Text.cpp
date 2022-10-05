#include "../include/Text.h"

// constructor
Text::Text(std::string _text, int _x, int _y, int _w, int _h, char _color, UI &_ui)
{
    // setting the text color
    text_to_char = _text.c_str();
    if (_color == 'w')
    {
        color = White;
    }
    else if (_color == 'y')
    {
        color = Yellow;
    }
    surfaceMessage = TTF_RenderText_Solid(myFont, text_to_char, color);
    Message = SDL_CreateTextureFromSurface(_ui.getRenderer(), surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    rectPosition(_x, _y, _w, _h); // position and size of the text
}

// destructor
Text::~Text()
{
    if (Message)
        SDL_DestroyTexture(Message);
    if (myFont)
        TTF_CloseFont(myFont);
}

void Text::renderCopy(UI &_ui)
{
    SDL_RenderCopy(_ui.getRenderer(), Message, NULL, &Text_rect);
}

void Text::rectPosition(int _x, int _y, int _w, int _h)
{
    Text_rect.x = _x; // controls the rect's x coordinate
    Text_rect.y = _y; // controls the rect's y coordinte
    Text_rect.w = _w; // controls the width of the rect
    Text_rect.h = _h; // controls the height of the rect
}

// void Text::setFont(const char *_font)
// {
//     myFont = TTF_OpenFont(_font, 32);
// }

const char *Text::getFont()
{
    return path;
}