NAME			=	cub3d

LIBFT			=	libft.a

MLX				=	mlx/libmlx_Linux.a

DIR_SRCS		=	srcs

DIR_SUBDIRS		=	parsing

DIR_OBJS		=	.objs

SRCS_NAMES		=	parsing/parsing.c \
					parsing/parsing_utils.c \
					parsing/init.c \
					utils.c \
					main.c \

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

DEPS			=	${SRCS_NAMES:%.c=$(DIR_OBJS)/%.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

INC				=	-Iinclude -Ilibft/include -Imlx #-I/usr/include -I.

LIB				=	-Llibft -lft

CC				=	cc

CDFLAGS 		= 	-MMD -MP

MFLAGS			=	-lmlx_Linux -lXext -lX11 -lm -lz -Lmlx -L/usr/lib

CFLAGS			=	-g3 -Wall -Werror -Wextra

all:	${NAME}

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) ${INC} $(CDFLAGS) $(MFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@ echo "EYUP MATE YALRIGHT?"  | toilet -f future -F border --gay

$(LIBFT):
		make -C libft

$(MLX):
		make -C mlx

$(OBJS): | $(DIR_OBJS)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CDFLAGS) $(INC) -c $< -o $@

$(DIR_OBJS)/%.d: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MM -MT '$(DIR_OBJS)/$*.o' -MF $@ $(INC) $<

-include $(DEPS)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	make clean -C libft
	make clean -C mlx
	rm -rf ${DIR_OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
# .SILENT:
