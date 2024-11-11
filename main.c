#include <stdio.h>
#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include <math.h>
#include <string.h>
#include "boids/header.h"



int main() {
	
	
	void *mlx = mlx_init();
	if (mlx == NULL) {
		printf("can not found mlx library\n"); exit(1);
	}
	
	void *new_win = mlx_new_window(mlx, WIDTH, HEIGHT, "boids");
	if (new_win == NULL) {
		printf("can not create new window\n"); exit(1);
	}
	
	void *new_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (new_img == NULL) {
		printf("can not create image in memory\n"); exit(1);
	}
	
	int bpp, size_line, endian;
	int *data = (int *) mlx_get_data_addr(new_img, &bpp, &size_line, &endian);
	
	
	mlx_put_image_to_window(mlx, new_win, new_img, 0, 0);
	
	make_boid(data, size_line);
	
	
	mlx_loop(mlx);
	
	
	
	return 0;
}


// mlx_string_put(mlx, new_win, (WIDTH / 2) - 50, 100, 0x0000FF00, "HELLO WORLD");








