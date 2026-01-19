NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = error_functions.c ft_split.c main.c operations.c printable.c push_swap.c stack_operations.c utils.c
   
OBJ = $(SRC:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c Makefile push_swap.h
	$(CC) -c -o $@ $<

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

TEST = push_swap.exe
MAIN = main.c

run: $(NAME)
	$(CC) $(MAIN) ./$(NAME) -o $(TEST)

.PHONY: all clean fclean re test