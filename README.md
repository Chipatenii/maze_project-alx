The ALX Project - The Maze Game
--------------

![image](https:)

The goal of this __Maze Game Project__ is to create a 3D game using the raycasting technique.
Raycasting is a rendering technique used in computer graphics to simulate
a `3D environment` in a `2D space`. I have always been fascinated and curious as to
how games are made and how they are developed.
Once this opportunity presented itself to develop __a maze game__ using `SDL2`, `C` and `the raycasting technique`,
I invested maximum time ensuring that I get a good grasp of what I needed to do to make this a reality.
This project is to be implemented on `Ubuntu 14.04 LTS`
using the gcc compiler and the SDL2 and SDL2_image library for graphics and input.

After the installation of __SDL2__, the test below was carried out to verify that __SDL2__ has been correctly installed:

```c
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
```

## The Project Requirement

- All functions in the code must be commented.
- To promote consistency, all functions must be maximum 40 lines long (one statement per line) and maximum 80 columns long.
- All codes must fit the `Holberton School coding style`.
- All codes must be well documented in respect to the `Holberton School documentation format`
- The entire repository is checked using `Betty`.

## The Project Context
On the map in __the maze game__, __the player__ can move in all four directions using keys `W`, `A`, `S`, and `D`.

The player can navigate through the maze, making left or right turns as desired.

If the player encounters a wall, they are unable to proceed unless they alter their direction.

The player has the capability to move in multiple directions and simultaneously rotate.

## Installation

Clone this repository:

```
git clone [https://github.com/Chipatenii/maze_project-alx]
```

## The Project Controls

```W```: Move forward.

```S```: Move backward.

```A```: Rotate left.

```D```: Rotate right.

```Mouse movement left/right```: Adjust your view to the left or right.

```M```: Disable the map display. Clicking won't show the 2D map.

```N```: Enable the map display. The 2D map will become visible once more if it was hidden.

## The Project Directories

[`headers`](https://github.com/Chipatenii/maze_project-alx/tree/main/headers)

All the header files are in here.

[`images`](https://github.com/Chipatenii/maze_project-alx/tree/main/images)

This contains all image files.

[`maps`](https://github.com/HBIbidunni/alx-maze_project/tree/master/maps)

This will be used by the program to output the map layout using the data map files

[`src`](https://github.com/Chipatenii/maze_project-alx/tree/main/src)

All the source code files written in C are in this folder.

[`tests`](https://github.com/Chipatenii/maze_project-alx/tree/main/tests)

This folder contains the SDL2 test file.

## Contributions

- Begin by examining the source files located within the "src" directory and the header files in the "header" directory.

- Duplicate the repository and establish a new branch using the following command: __$ git checkout https://github.com/HBIbidunni/alx-maze_project -b [name_of_new_branch]__.

- Introduce a new feature, resolve any existing bugs, or undertake code refactoring as needed.

- If applicable, create or revise test cases to ensure the changes are properly validated.

- If necessary, update the README.md file to reflect any modifications.

- Finally, initiate a Pull Request, providing a comprehensive description of the alterations made.

## The Project Inspiration

The __Maze Game Project__ is a game directly inspired by Wolfenstein3D, which was developed in 1992.
For this project, a game engine was not required.

## Author

- __Innocent Manda__ - [Github](https://github.com/chipatenii)/ [Contact Me](mailto:innocentmanda70@gmail.com)

## The 3D Maze Game Project Demo(click :point_down:)
[![The 3D Maze Project](https://img.youtube.com/vi/qoXFZv-hLW0/0.jpg)](https://www.youtube.com/watch?v=qoXFZv-hLW0)
