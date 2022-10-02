#include "Game.h"

Game::Game(){};
Game::~Game(){};

void Game::play()
{
    const int FPS = 10;                // set FPS
    const int frameDelay = 1000 / FPS; // delay according to FPS
    Uint32 frameStart;                 // keeps track of time (?)
    int frameTime;

    UI gui(180, 180);               // set UI size
    SnakeHead snakeHead;            // cread snakeHead object
    snakeHead.setPosition(4, 4);    // starting position snake
    snakeHead.setDirection("stop"); // starting direction

    srand((unsigned int)time(NULL));
    Apple apple;                // create apple object
    apple.setRandPosition(gui); // random starting position apple

    std::vector<SnakeSegment *> snakeBody; // create vector of snakeSegments
    snakeBody.push_back(new SnakeSegment());
    int segmentCount = 1; // keeps track of body length
    snakeBody[0]->setPosition(snakeHead.getPosition().first - 9, snakeHead.getPosition().second);

    bool pause = false;
    bool quit = false;
    bool game_over = false;
    bool menu = true;
    bool startgame_hover = false;
    bool highscores_hover = false;
    bool game_over_menu_hover = false;
    bool highscores_screen = false;
    bool highcore_back_hover = false;

    std::string lastDirection;

    // Menu Stuff
    TexturedRectangle main_menu(gui.getRenderer(), "/home/lennardmarx/UTwente/Programming/Snake/Images/Menu.bmp");
    TexturedRectangle start_game_image(gui.getRenderer(), "/home/lennardmarx/UTwente/Programming/Snake/Images/StartGame.bmp");
    TexturedRectangle highscores_image(gui.getRenderer(), "/home/lennardmarx/UTwente/Programming/Snake/Images/Highscores.bmp");

    int xMouse, yMouse;

    // noch ein test

    // Using SDL_ttf
    TTF_Init();
    Text gamePaused("Game Paused!", 35, 70, 120, 25, 'w', gui);
    Text gameOver("Game Over!", 25, 50, 130, 30, 'w', gui);
    Text gameOverMenu("Main Menu", 35, 110, 100, 20, 'w', gui);
    Text gameOverMenuYellow("Main Menu", 35, 110, 100, 20, 'y', gui);

    // highscores

    bool score_check = false;
    std::ofstream highscores_w;
    std::vector<int> highscores;
    int highscore;
    std::ifstream highscores_r("/home/lennardmarx/UTwente/Programming/Snake/highscores/highscores.txt");
    while (highscores_r >> highscore)
    {
        highscores.push_back(highscore);
    }
    highscores_r.close();

    while (!quit)
    {
        frameStart = SDL_GetTicks(); // limit framerate (see end of while loop)

        lastDirection = snakeHead.getDirection(); // DOESNT WORK YET -> updates frequently rewrite the pause (not just stop the snake but stop game)

        if (pause) // pause the game
        {
            gamePaused.renderCopy(gui); // render text for paused game
            gui.present();
        }
        else
        {
            if (menu == true)
            {
                // to check where mouse is on screen
                // std::cout << xMouse << ", " << yMouse << std::endl;
                segmentCount = 1; // reset Count of segments
                score_check = false;
                gui.clear(); // render screen black
                if (menu == true)
                {
                    main_menu.Draw(0, 0, 180, 180); // main menu background
                    main_menu.Render(gui.getRenderer());
                }
                // check if mouse hovers over the "Start Game" button
                if (xMouse > 95 && xMouse < 465 && yMouse > 235 && yMouse < 285)
                {
                    start_game_image.Draw(0, 0, 180, 180);
                    start_game_image.Render(gui.getRenderer());
                    startgame_hover = true;
                }
                else
                {
                    startgame_hover = false;
                }
                // check if mouse hovers over the "Highscores" button
                if (xMouse > 80 && xMouse < 470 && yMouse > 350 && yMouse < 410)
                {
                    highscores_image.Draw(0, 0, 180, 180);
                    highscores_image.Render(gui.getRenderer());
                    highscores_hover = true;
                }
                else
                {
                    highscores_hover = false;
                }
                // show highscores screen
                if (highscores_screen == true)
                {
                    gui.clear();
                    // UNNECESSARY IF ONLY DRAWING TEXT"!!! -> mabye also make struct with texts
                    std::string highscore_title = "Highscores";
                    const char *highscore_title_conv = highscore_title.c_str();
                    Text highscore_title_text(highscore_title_conv, 40, 25, 100, 25, 'w', gui);
                    highscore_title_text.renderCopy(gui);
                    std::string highscore_back = "< Back";
                    const char *highscore_back_conv = highscore_back.c_str();
                    Text highscore_back_text(highscore_back_conv, 3, 2, 40, 15, 'w', gui);
                    highscore_back_text.renderCopy(gui);
                    // check if mouse hovers over "back" button
                    if (xMouse > 0 && xMouse < 130 && yMouse > 0 && yMouse < 45)
                    {
                        Text highscore_back_text(highscore_back_conv, 3, 2, 40, 15, 'y', gui);
                        highscore_back_text.renderCopy(gui);
                        highcore_back_hover = true;
                    }
                    else
                    {
                        highcore_back_hover = false;
                    }
                    std::string highscore_1 = "1st: " + std::to_string(highscores.at(0));
                    std::string highscore_2 = "2nd: " + std::to_string(highscores.at(1));
                    std::string highscore_3 = "3rd: " + std::to_string(highscores.at(2));
                    std::string highscore_4 = "4th: " + std::to_string(highscores.at(3));
                    std::string highscore_5 = "5th: " + std::to_string(highscores.at(4));
                    const char *highscore_1_conv = highscore_1.c_str();
                    const char *highscore_2_conv = highscore_2.c_str();
                    const char *highscore_3_conv = highscore_3.c_str();
                    const char *highscore_4_conv = highscore_4.c_str();
                    const char *highscore_5_conv = highscore_5.c_str();
                    Text highscore_1_text(highscore_1_conv, 65, 55, 50, 15, 'w', gui);
                    Text highscore_2_text(highscore_2_conv, 65, 75, 50, 15, 'w', gui);
                    Text highscore_3_text(highscore_3_conv, 65, 95, 50, 15, 'w', gui);
                    Text highscore_4_text(highscore_4_conv, 65, 115, 50, 15, 'w', gui);
                    Text highscore_5_text(highscore_5_conv, 65, 135, 50, 15, 'w', gui);
                    highscore_1_text.renderCopy(gui);
                    highscore_2_text.renderCopy(gui);
                    highscore_3_text.renderCopy(gui);
                    highscore_4_text.renderCopy(gui);
                    highscore_5_text.renderCopy(gui);
                }
                gui.present();
            }

            //================================= when game starts ==============================================

            else if (menu == false)
            {

                gui.clear(); // render screen black

                gui.setDrawColor(204, 0, 0, 255);
                apple.drawApple(gui); // draw apple
                gui.setDrawColor(0, 102, 0, 255);
                if (!game_over)
                {
                    snakeHead.moveSnake(gui); // move snakeHead
                }
                snakeHead.drawSegment(gui); // draw snakeHead

                // when snake reaches apple
                if (snakeHead.getPosition().first == apple.getPosition().first && snakeHead.getPosition().second == apple.getPosition().second)
                {
                    apple.setRandPosition(gui);              // new random location for apple
                    snakeBody.push_back(new SnakeSegment()); // new snakeSegment
                    ++segmentCount;
                }

                // attaching segments
                if (segmentCount != 0)
                {
                    if (snakeHead.getDirection() != "stop")
                    {
                        // update position of first segment ("attach" to head)
                        snakeBody[0]->setPosition(snakeHead.getPreviousPosition().first, snakeHead.getPreviousPosition().second);
                        // snakeBody[0]->drawSegment(gui);

                        // update position of the rest of the segments
                        if (!game_over)
                        {
                            for (int i = 1; i < segmentCount; ++i)
                            {
                                snakeBody[i]->setPosition(snakeBody[i - 1]->getPreviousPosition().first, snakeBody[i - 1]->getPreviousPosition().second);
                                // snakeBody[i]->drawSegment(gui);
                            }
                        }

                        // check if snakeHead hits snakeSegment
                        for (int i = 0; i < segmentCount; ++i)
                        {
                            if (snakeBody[i]->getPosition().first == snakeHead.getPosition().first && snakeBody[i]->getPosition().second == snakeHead.getPosition().second)
                            {
                                // std::cout << "Game Over!" << '\n';
                                // std::cout << "Score: " << segmentCount << '\n';
                                // quit = true;
                                game_over = true;
                            }
                        }
                    }
                }
                for (int i = 0; i < segmentCount; ++i) // draw all snake segments
                {
                    snakeBody[i]->drawSegment(gui);
                }

                //=========================== Game Over =============================================================

                if (game_over)
                {
                    // std::cout << xMouse << ", " << yMouse << std::endl;

                    // draw game over screen
                    gameOver.renderCopy(gui);
                    gameOverMenu.renderCopy(gui);
                    std::string score_text = "Score: " + std::to_string(segmentCount);
                    const char *score_text_conv = score_text.c_str();
                    Text scoreText(score_text_conv, 35, 83, 100, 20, 'w', gui);
                    scoreText.renderCopy(gui);

                    // removing the body segments to reset snake
                    while (snakeBody.size() >= 2)
                    {
                        snakeBody.pop_back();
                    }
                    // saving score (only once to not override -> actually solved by the sorting, but still nice)
                    if (score_check == false)
                    {
                        // add the current score to the highscores vector
                        highscores.push_back(segmentCount);

                        // sort the highscores from best to worst
                        std::sort(highscores.begin(), highscores.end(), std::greater<int>());

                        // only save top 10
                        if (highscores.size() > 10) // if score sheet not filled yet
                        {
                            while (highscores.size() > 10)
                            {
                                highscores.pop_back();
                            }
                        }

                        // saving the updated score list to the text file
                        highscores_w.open("/home/lennardmarx/UTwente/Programming/Snake/highscores/highscores.txt");
                        for (const auto &i : highscores)
                        {
                            highscores_w << i << '\t';
                        }
                        highscores_w.close();
                        score_check = true;
                    }

                    // check if mouse hovers over "back to main menu"
                    if (xMouse > 108 && xMouse < 408 && yMouse > 340 && yMouse < 380)
                    {
                        gameOverMenuYellow.renderCopy(gui);
                        game_over_menu_hover = true;
                    }
                    else
                    {
                        game_over_menu_hover = false;
                    }
                }
                gui.present(); // render screen
            }
        } // end else (pause game)

        //========================= Event checks ===============================================================

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // stop when pressing "x" (?)
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            // key presses
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                case SDLK_UP:
                    if (snakeHead.getDirection() != "down")
                    {
                        snakeHead.setDirection("up");
                    }
                    break;
                case SDLK_RIGHT:
                    if (snakeHead.getDirection() != "left")
                    {
                        snakeHead.setDirection("right");
                    }
                    break;
                case SDLK_DOWN:
                    if (snakeHead.getDirection() != "up")
                    {
                        snakeHead.setDirection("down");
                    }
                    break;
                case SDLK_LEFT:
                    if (snakeHead.getDirection() != "right")
                    {
                        snakeHead.setDirection("left");
                    }
                    break;
                case SDLK_SPACE:
                    pause = !pause;
                    break;
                default:
                    break;
                }
            }
            // Tracking mouse movement
            if (event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
            }
            // Checking mouse clicks
            if (event.type == SDL_MOUSEBUTTONDOWN)
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    if (startgame_hover == true)
                    {
                        menu = false;
                    }
                    if (game_over_menu_hover == true)
                    {
                        menu = true;
                        game_over = false;
                        game_over_menu_hover = false;
                    }
                    if (highscores_hover == true)
                    {
                        highscores_screen = true;
                    }
                    if (highcore_back_hover == true)
                    {
                        highscores_screen = false;
                        highcore_back_hover = false;
                    }
                    break;
                }
        }

        // frame time to limit FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}