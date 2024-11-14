# boids_algorithm



## setup working with mlx_linux
	see the source: https://github.com/KaraniAbdellah/fract_ol
	NOTE: if you are working with mlx_linux (if my case i am working just with SDL2)


## setup working with SDL2

``` bash
sudo apt update
sudo apt install libsdl2-dev
```

<b>set the flags in makefile: </b>

``` bash
CFLAGS = -I./mlx_linux -I/usr/include -I/usr/include/SDL2 # Include directories for headers
LDFLAGS = -L./mlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -lSDL2 # Libraries to link
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













