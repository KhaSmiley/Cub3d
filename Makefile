NAME			=	cub3D

NAME_BONUS		=	cub3D_bonus

LIBFT			=	libft/libft.a

MLX				=	mlx/libmlx_Linux.a

DIR_SRCS		=	srcs

DIR_SUBDIRS		=	parsing \
					utils \
					rays \
					game \

DIR_OBJS		=	.objs

SRCS_NAMES		=	parsing/parsing.c \
					parsing/parsing_utils.c \
					parsing/parsing_utils_map.c \
					parsing/parsing_utils_colors.c \
					parsing/parsing_map_spaces.c \
					parsing/parsing_info.c \
					parsing/parsing_colors.c \
					parsing/init.c \
					parsing/init_utils.c \
					utils/utils.c \
					utils/clean.c\
					graphics/pixels.c \
					graphics/maths.c \
					graphics/raycasting.c \
					graphics/textures.c \
					graphics/textures_utils.c \
					game/keys.c \
					game/moves.c \
					game/game.c \
					main.c \

SRCS_NAMES_BONUS =	parsing/parsing.c \
					parsing/parsing_utils.c \
					parsing/parsing_utils_map.c \
					parsing/parsing_utils_colors.c \
					parsing/parsing_map_spaces.c \
					parsing/parsing_info.c \
					parsing/parsing_colors.c \
					parsing/init.c \
					parsing/init_utils.c \
					utils/utils.c \
					utils/clean.c\
					graphics/pixels.c \
					graphics/maths.c \
					graphics/raycasting.c \
					graphics/textures.c \
					graphics/textures_utils.c \
					game/keys.c \
					game/moves.c \
					game/game_bonus.c \
					main.c \

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_BONUS =	${SRCS_NAMES_BONUS:.c=.o}

DEPS			=	${SRCS_NAMES:%.c=$(DIR_OBJS)/%.d}

DEPS_BONUS		=	${SRCS_NAMES_BONUS:%.c=$(DIR_OBJS)/%.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

SRCS_BONUS		=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES_BONUS))

OBJS_BONUS		=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES_BONUS))

INC				=	-Iinclude -Ilibft/include -Imlx -I/usr/include

MFLAGS			=	-lmlx_Linux -lXext -lX11 -lm -lz -Lmlx -L/usr/lib

LIB				=	-Llibft -lft

CC				=	cc

CDFLAGS 		= 	-MMD -MP

CFLAGS			=	-g3 -Wall -Werror -Wextra

all:	${NAME}

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(INC) $(OBJS) $(MFLAGS) $(CDFLAGS) $(LIB) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	@ echo "cub3D : Khalau World"  | toilet -f future -F border --gay

bonus:	${NAME_BONUS}

$(NAME_BONUS): $(DIR_OBJS) $(OBJS_BONUS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(INC) $(OBJS_BONUS) $(MFLAGS) $(CDFLAGS) $(LIB) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	rm -rf $(NAME)
	@ echo "bonus"  | toilet -f future -F border --gay

$(LIBFT):
		make -C libft

$(MLX):
		make -C mlx

$(OBJS): | $(DIR_OBJS)

$(OBJS_BONUS): | $(DIR_OBJS)

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
	rm -rf ${NAME_BONUS}

re:	fclean all

.PHONY:	all clean fclean re
