In this project I build the classic "Snake Game" in C++ while using the SDL2 (Simple DirectMedia Layer 2) library for visualization.
The interface is navigatalble via the mouse, the game is played with the arrow keys.

Building the Snake Game

Assumptions:

1. You are on a Linux system or in a Virtual Box running Linux
2. You have C++ and the g++ compiler installed

Preceding steps:

1. Please install SDL2, as well as SDL2_ttf:
   For Debian based systems: (for other systems please use the according package manager)

   $ sudo apt upgrade
   $ sudo apt install libsdl2-dev
   $ sudo apt install libsdl2-ttf-dev

2. Open a terminal emulator in the base folder ("Snake"), or move to the Snake folder manually

3. Give the compiling script executable rights: (alternatively through the GUI)

   $ chmod +x build.sh

4. Compile the program into an executable by running:

   $ ./build.sh

5. Give the executable executable rights by running: (alternatively through the GUI)

   $ chmod +x snake

Now you can run the game with the following command:

    $ ./snake
    
