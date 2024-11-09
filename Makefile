NAME = main
SRC = main.c boids/funs.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -I./mlx_linux -I/usr/include # Include directories for headers
LDFLAGS = -L./mlx_linux -lmlx_Linux -lXext -lX11 -lm -lz # Libraries to link


$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) $(CFLAGS) -pthread -o $(NAME) # Compile and link
	rm -f $(OBJ) # Remove object files after building

clean:
	rm -f $(OBJ) # Remove object files

fclean: clean
	rm -f $(NAME) # Remove the executable file


