#include <stdio.h>
#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include "header.h"
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>



/*
	each boid has [position, velocity, acceleration]
	roles of boids: [seperation, alignment, cohesion]

	Separation: boids move away from other boids that are too close
	Alignment: boids attempt to match the velocities of their neighbors
	Cohesion: boids move toward the center of mass of their neighbors

*/


void print() {
	printf("Hello Boids");
}




// size_line: number of pixels * 4
// HEIGHT is number of pixels
void make_boid(int *data, int size_line) {
	
	
	// make a first boids like (rectangle in the center)
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			data[x + y * (HEIGHT)] = 1873461;
		}
	}
	
	

	
}








