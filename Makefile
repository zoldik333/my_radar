##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-BSQ-theo.vermorel
## File description:
## Makefile
##

SRC = $(shell find ./src/ -type f -name '*.c')

OBJ = $(SRC:.c=.o)

LIBS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lm

NAME = my_radar

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) *.c $(OBJ) -I./includes/ $(LIBS) -g
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all
