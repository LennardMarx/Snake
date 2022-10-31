//===============================================================
// credit for this code to Mike Shah
// https://github.com/MikeShah/SDL2_Tutorials
//
// changes where made to the original version
// class to create a textured rectangle, used for the main menu
//===============================================================

#include <string>
// Third Party
#include <SDL2/SDL.h> // For Mac, use <SDL.h>
// #include <SDL2/SDL_image.h>

class TexturedRectangle
{
public:
    // Constructor
    TexturedRectangle(SDL_Renderer *&renderer, std::string filepath);
    // Destructor
    ~TexturedRectangle();
    //
    void Draw(int x, int y, int w, int h);
    // Copy Constructor..
    // Copy assignment operator

    // Update every frame
    void Update();
    // Render
    void Render(SDL_Renderer *&renderer);

private:
    SDL_Rect m_rectangle;
    SDL_Texture *m_texture;
};
