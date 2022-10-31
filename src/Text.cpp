//===============================================================
// Methods of the Text class used for printing Text on the screen
//===============================================================

#include "../include/Text.h"

// constructor
Text::Text(std::string _text, int _x, int _y, int _w, int _h, char _color, UI &_ui)
{
    text_to_char = _text.c_str(); // converting tet to char array
    // setting the text color
    if (_color == 'w')
    {
        color = White;
    }
    else if (_color == 'y')
    {
        color = Yellow;
    }
    // converting the text to a rederable suface
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

// copying the texture to the rendering target
void Text::renderCopy(UI &_ui)
{
    SDL_RenderCopy(_ui.getRenderer(), Message, NULL, &Text_rect);
}

// set the position and size of the rect
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

// get the path to the font
const char *Text::getFont()
{
    return path;
}