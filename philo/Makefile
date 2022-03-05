NAME 	=	philosophers
HEADER  =   philosophers.h

SOURCES = 	ft_atoi.c \
			actions.c \
			main.c \
			any_utils.c \
			philosophers.c \
			spect.c 

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

test: $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	leaks -atExit -- ./so_long maps/leaks_test.ber

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test