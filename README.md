# boids_algorithm



## Start working with SDL2

``` bash
sudo apt update
sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev // for using image with SDL2
```

<b>set the flags in makefile: </b>

``` bash
CFLAGS = -I/usr/include/SDL2 # Include directories for headers
LDFLAGS = -lm -lSDL2 -lSDL2_image -pthread # Libraries to link
```

in main header file include <code>#include <SDL2/SDL.h></code>

## Intro to SDL2
SDL is Simple DirectMedia Layer.It is a cross-platform development library 
designed to provide low level access to audio, keyboard, mouse, joystick, 
and graphics hardware via OpenGL and Direct3D.It can be used to make animations and video games.

// for initializing and shutdown functions
<code>#include <SDL2/SDL.h></code>
 
// for rendering images and graphics on screen
<code>#include <SDL2/SDL_image.h></code> 

// for using SDL_Delay() functions
<code>#include <SDL2/SDL_timer.h></code> 













