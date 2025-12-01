NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
      ft_printable.c \
      ft_print_hexa.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

MAIN = main.c
OUTPUT = test

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(NAME): $(OBJ) $(LIBFT) Makefile ft_printf.h
	ar rcs $(NAME) $(OBJ)
	ar x $(LIBFT)      
	ar rcs $(NAME) *.o 
	rm -f *.o

run: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(OUTPUT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run
