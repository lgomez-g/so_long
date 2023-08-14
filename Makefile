SRCS_DIR = SRCS
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJ = $(SRCS:.c=.o)
NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O3 -fsanitize=address
LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES = -Imlx_linux

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
