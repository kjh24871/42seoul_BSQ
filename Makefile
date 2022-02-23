NAME = bsq
SRCS = srcs/main.c srcs/logic.c srcs/print_return_map.c srcs/check_map.c srcs/tools.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)	
	gcc -Wall -Wextra -Werror $^ -o $(NAME) -fsanitize=address

%.o : %.c
	gcc -c -Wall -Wextra -Werror $< -o $@ -I includes

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
