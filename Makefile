NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MY_SOURCES = ft_printf.c\
             
OBJS = $(MY_SOURCES:.c=.o)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

all: $(NAME)

%.o : %.c Makefile libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

TEST = test_trim.exe
MAIN = main.c

test: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) -L. -lft -o $(TEST)

.PHONY: all clean fclean re test bonus