// #include "Events.h"

// void Events::checkEvents()
// {

//     while (SDL_PollEvent(&event))
//     {
//         // stop when pressing "x" (?)
//         if (event.type == SDL_QUIT)
//         {
//             quit = true;
//         }
//         // key presses
//         if (event.type == SDL_KEYDOWN)
//         {
//             switch (event.key.keysym.sym)
//             {
//             case SDLK_ESCAPE:
//                 quit = true;
//                 break;
//             case SDLK_UP:
//                 if (snakeHead.getDirection() != "down")
//                 {
//                     snakeHead.setDirection("up");
//                 }
//                 break;
//             case SDLK_RIGHT:
//                 if (snakeHead.getDirection() != "left")
//                 {
//                     snakeHead.setDirection("right");
//                 }
//                 break;
//             case SDLK_DOWN:
//                 if (snakeHead.getDirection() != "up")
//                 {
//                     snakeHead.setDirection("down");
//                 }
//                 break;
//             case SDLK_LEFT:
//                 if (snakeHead.getDirection() != "right")
//                 {
//                     snakeHead.setDirection("left");
//                 }
//                 break;
//             case SDLK_SPACE:
//                 pause = !pause;
//                 break;
//             default:
//                 break;
//             }
//         }
//         // Tracking mouse movement
//         if (event.type == SDL_MOUSEMOTION)
//         {
//             SDL_GetMouseState(&xMouse, &yMouse);
//         }
//         // Checking mouse clicks
//         if (event.type == SDL_MOUSEBUTTONDOWN)
//             switch (event.button.button)
//             {
//             case SDL_BUTTON_LEFT:
//                 if (startgame_hover == true)
//                 {
//                     menu = false;
//                 }
//                 if (game_over_menu_hover == true)
//                 {
//                     menu = true;
//                     game_over = false;
//                     game_over_menu_hover = false;
//                 }

//                 // std::cout << "Hilfe!" << std::endl;
//                 break;
//             }
//     }
// }