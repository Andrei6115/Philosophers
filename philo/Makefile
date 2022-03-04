NAME 	=	philosophers
HEADER  =   philosophers.h
SOURCES = 	utils/ft_atoi.c \
			actions.c \
			any_utilis.c \
			main.c \
			philosophers.c \
			spect.c \

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINLIBFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) libft mlx
	$(CC) $(CFLAGS) $(MINLIBFLAGS) -o $(NAME) $(OBJECTS) libft/libft.a

test: $(OBJECTS) $(HEADER) libft mlx
	$(CC) $(CFLAGS) $(MINLIBFLAGS) -o $(NAME) $(OBJECTS) libft/libft.a
	leaks -atExit -- ./so_long maps/leaks_test.ber

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

mlx:
	make -C minilibx

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C minilibx clean
	
fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re test