NAME     = pipex

BUILD    = build
INCLUDE  = -I./include -I./libft
CC       = cc
CFLAGS   = -Wall -Wextra -Werror $(INCLUDE) -fsanitize=address -g
LIB      = -Llibft -lft

SRC_DIRS  = src
SRC_FILES = main.c pipex_utils.c check.c
OBJS      = $(patsubst %.c, $(BUILD)/%.o, $(SRC_FILES))

RESET			= \033[0m
BLUE			= \033[34m
YELLOW			= \033[38;2;255;239;0m
APPLE_GREEN		= \033[38;2;141;182;0m
PINK			= \033[38;2;255;105;180m
RED				= \033[31m
CYAN			= \033[38;2;0;255;255m
VIOLET			= \033[38;2;138;43;226m
GOLD			= \033[38;2;255;215;0m
MAGENTA			= \033[38;2;255;0;255m

all: build lib $(NAME)

lib:
	@make -C libft

build:
	@mkdir -p $(BUILD)

$(NAME): $(OBJS)
	@echo "${PINK}💻 Compiling${RESET}"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "${YELLOW}✨ Executable Created 🥑 ${RESET}"

$(BUILD)/%.o: $(SRC_DIRS)/%.c
	@echo "${CYAN}🔨  Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}🧹 Removing Object Files...${RESET}"
	@make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@echo "${RED}🔥 Removing Executable Files...${RESET}"
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "${GOLD}✨ All Executables Removed! Everything is Clean! ✅ ${RESET}"

re: fclean all

.PHONY: all clean fclean re lib build
