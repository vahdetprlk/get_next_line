NAME	= get_next_line.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

FILES	= $(shell find . -type f ! -name "*_bonus.c" -name "*.c")
OBJ		= $(FILES:%.c=%.o)

BSRC	= $(shell find . -type f -name "*_bonus.c")
B_OBJ	= $(BSRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

bonus: $(OBJ) $(B_OBJ)
	@ar -rc $(NAME) $(OBJ) $(B_OBJ)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
