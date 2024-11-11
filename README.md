# boids_algorithm


## setup working with mlx_linux
	see the source: https://github.com/KaraniAbdellah/fract_ol

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




