NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MY_SOURCES = error_functions.c\main.c\operations.c\printable.c\push_swap.c\stack_operations.c\utils.c\
   
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

TEST = a.exe
MAIN = main.c

run: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) ./$(NAME) -o $(TEST) 
	./$(TEST)

.PHONY: all clean fclean re test
