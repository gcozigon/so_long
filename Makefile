LIBFT			=	utils/libft/libft.a

PRINTF			=	utils/ft_printf/libftprintf.a

SRCS			=	srcs/index.c srcs/check_map.c srcs/check_elem.c srcs/check_path.c srcs/graphics.c srcs/graphics_utils.c utils/get_next_line/get_next_line.c utils/get_next_line/get_next_line_utils.c \

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -g3 -Wall -Wextra -Werror

NAME			= so_long

all:			$(NAME)

$(NAME):		$(OBJS)
					@make -C utils/libft
					@make -C mlx
					@make -C utils/ft_printf
					cc $(OBJS) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 -o $(NAME)-L. ${LIBFT} ${PRINTF} -o $(NAME)

clean:
					make clean -C utils/libft/
					make clean -C utils/ft_printf/
					make clean -C mlx
						$(RM) $(OBJS)

fclean:			clean
					make fclean -C utils/libft/
					make fclean -C utils/ft_printf/
						$(RM) $(NAME)
re:						fclean $(NAME)

.PHONY:			all clean fclean re
