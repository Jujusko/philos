NAME	= philo_bonus

FILES	= time.c\
		make_processes.c\
		actions.c\
		fill_philos.c\
		fill_struct.c\
		main.c

OBJS	= $(FILES:.c=.o)

CC		= gcc -Wall -Wextra -Werror

RM		= rm -f

%.o : %.c philo.h
		$(CC) $< -c -I philo.h

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re