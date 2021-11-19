NAME	= philo

FILES	= time.c\
		init.c\
		actions.c\
		newPhilo.c

OBJS	= $(FILES:.c=.o)

CC		= gcc -Wall -Wextra -Werror

RM		= rm -f

%.o : %.c philo.h
		$(CC) $< -c -I philo.h

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o philo

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re