NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_isascii.c ft_isprint.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o)

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

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${YELLOW}Libft compiled ✨ ${RESET}"
	@$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	@echo "${APPLE_GREEN}🔨 Compiling $<${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}🧹 Removing Object Files...${RESET}"
	@$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
	@echo "${RED}🧹 Removing ${NAME} ${RESET}"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
