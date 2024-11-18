NAME = main
SRC = main.c boids/funs.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -I/usr/include/SDL2 # Include directories for headers
LDFLAGS = -lm -lSDL2 -lSDL2_image -pthread # Libraries to link

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) # Compile and link

clean:
	rm -f $(OBJ) # Remove object files

fclean: clean
	rm -f $(NAME) # Remove the executable file

