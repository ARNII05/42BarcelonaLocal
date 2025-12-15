NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MY_SOURCES = push_swap.c\utils.c\error_functions.c\ft_itoa.c\
   
OBJS = $(MY_SOURCES:.c=.o)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

all: $(NAME)

%.o : %.c Makefile push_swap.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

TEST = test_trim.exe
MAIN = main.c

run: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) -L. -lft -o $(TEST)

.PHONY: all clean fclean re test
