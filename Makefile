SRCS	= ./srcs/error.c\
		./srcs/ft_itoa.c\
		./srcs/get_next_line_utils.c\
		./srcs/get_next_line.c\
		./srcs/libft_utils.c\
		./srcs/pile_handling.c\
		./srcs/push_swap.c\
		./srcs/push.c\
		./srcs/push2.c\
		./srcs/rotate.c\
		./srcs/swap.c\

RENAME		= mv a.out checker
OBJ			= $(SRCS:.c=.o)
NAME		= checker
FS			= a.out.dSYM checker.dSYM
CC			= gcc
RM			= rm -f
RM_DIR		= rm -rf
CFLAGS		= -Wall -Wextra -Werror
$(NAME):		$(OBJ)
				@$(CC) $(CFLAGS) $(SRCS)
				@$(RENAME)
all:			$(NAME)
clean:
				@$(RM) $(OBJ)
fclean:			clean
				@$(RM) $(NAME)
				@$(RM_DIR) $(FS)
re:				fclean all
.PHONY:			all clean fclean re
