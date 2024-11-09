#include <stdio.h>
#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include "header.h"
#include <math.h>
#include <string.h>


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






