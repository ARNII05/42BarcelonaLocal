NAME = libftprintf.a

RM = rm -fr
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
      ft_printable.c \
      ft_print_hexa.c

OBJ = $(SRC:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o : %.c Makefile ft_printf.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

TEST = test
MAIN = main.c

run: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) ./$(NAME) -o $(TEST) 
	./$(TEST)

.PHONY: all clean fclean re test

