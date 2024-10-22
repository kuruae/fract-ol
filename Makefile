######### COLORS ########

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

######### FLAGS ########

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = libft
MLX_PATH = mlx

######### DIRECTORIES ########

SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = objs
INCLUDE_DIR = include
# Add all include directories here
INCLUDE_DIRS = -I$(INCLUDE_DIR) -I$(LIBFT_PATH)/includes -I$(MLX_PATH)

######### FILES ########

SRC_FILES = $(SRC_DIR)/fractal.c \
			$(SRC_DIR)/hooks.c \
			$(SRC_DIR)/init.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/parsing.c \
			$(SRC_DIR)/sets.c \
			$(SRC_DIR)/utils.c

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

BONUS_SRC_FILES = $(BONUS_DIR)/anim_bonus.c \
                  $(BONUS_DIR)/fractal_bonus.c \
                  $(BONUS_DIR)/hooks_bonus.c \
                  $(BONUS_DIR)/init_bonus.c \
                  $(BONUS_DIR)/main_bonus.c \
                  $(BONUS_DIR)/parsing_bonus.c \
                  $(BONUS_DIR)/sets_bonus.c \
                  $(BONUS_DIR)/utils_bonus.c

BONUS_OBJ_FILES = $(patsubst $(BONUS_DIR)/%.c,$(OBJ_DIR)/%.o,$(BONUS_SRC_FILES))

######### LIBRARIES ########

LIBFT = $(LIBFT_PATH)/libft.a
UNAME_S := $(shell uname -s)
MLX = $(MLX_PATH)/libmlx.a
######### MLX FLAGS ########s

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	MLX_ARGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
else
	MLX_ARGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm
endif

######### NAME ########

NAME = fractol
BONUS_NAME = fractol_bonus

######### COMMANDS ########

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_ARGS)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(BONUS_NAME): $(BONUS_OBJ_FILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_ARGS)
	@echo "$(BONUS_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(BONUS_NAME): $(GREEN)$(BONUS_NAME) was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c -o $@ $<
	@echo "$(NAME): $(GREEN)$@ was created$(RESET)"

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c -o $@ $<
	@echo "$(BONUS_NAME): $(GREEN)$@ was created$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(NAME): $(GREEN)$(LIBFT) was created$(RESET)"

$(MLX):
	@$(MAKE) -C $(MLX_PATH)
	@echo "$(NAME): $(GREEN)$(MLX) was created$(RESET)"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@echo "$(BONUS_NAME): $(RED)$(BONUS_NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re