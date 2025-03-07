NAME = so_long

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAG = -L$(LIBFT_PATH) -lft

MLX_PATH = mlx
MLX = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAG = -L$(MLX_PATH) -lm -lmlx_Linux -lXext -lX11

#GNL_PATH = libft
#GNL_FILES = $(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c
#GNL_OBJECTS = $(GNL_FILES:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -v -Wall -Werror -Wextra -I. -I$(LIBFT_PATH) -I$(MLX_PATH) -I$(GNL_PATH) -O3 -g -gdwarf-4

SOURCES = check_map.c\
		  check_map_2.c\
		  errors.c\
		  init_img.c\
		  utils.c\
		  window.c\
		  $(GNL_FILES)

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAG) $(MLX_FLAG)
	@echo "$(NAME) OK!"

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) --no-print-directory -C $(MLX_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@  

bonus: all

all: $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean
	@$(MAKE) --no-print-directory -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME) 
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: all re clean fclean bonus

