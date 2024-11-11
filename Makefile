NAME = main
SRC = main.c boids/funs.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -I./mlx_linux -I/usr/include -I/usr/include/SDL2 # Include directories for headers
LDFLAGS = -L./mlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -lSDL2 # Libraries to link

$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) $(CFLAGS) -pthread -o $(NAME) # Compile and link
	rm -f $(OBJ) # Remove object files after building

clean:
	rm -f $(OBJ) # Remove object files

fclean: clean
	rm -f $(NAME) # Remove the executable file


