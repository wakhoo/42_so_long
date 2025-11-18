NAME = so_long
BOUNS = so_long_bonus
LIBFT = ./libft/libft.a
MLXLIB = ./MLX42/build/libmlx42.a
INCLUDE_DIR = -I ./libft/lib -I ./include/ -I ./MLX42/include
LIBMLX = ./MLX42/
SRCS_DIR = ./srcs/
SRCS_NAME = \
		file_check.c \
		get_map.c \
		handle_error.c \
		map_check.c \
		flood_fill.c \
		set_images.c \
		draw_map.c \
		key.c \
		move.c \
		redraw.c \
		free_memory.c \
		main.c

BASIC = \
	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS = $(BASIC:.c=.o)

# Options =================================================

CC = cc
# -fsanitize=address
RM = rm -f
CFLAGS = -Werror -Wextra -Wall -g3
LIBS = $(LIBFT) $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm 
# =========================================================

all : $(NAME) $(BONUS)

$(BONUS) : $(NAME)

$(NAME): $(OBJS) $(MLXLIB) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE_DIR) $(LIBS) -o $(NAME)

$(LIBFT):
	@make -C ./libft

$(MLXLIB):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean :
	@make clean -C "./libft" 
	@$(RM) $(OBJS)

fclean : clean
	@make fclean -C "./libft" 
	@$(RM) $(NAME)

re :
	@make fclean
	@make all

.PHONY: all, clean, fclean, re, libmlx
