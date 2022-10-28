CC = gcc
NAME = minishell
SRC = src/access.c \
	src/parsing.c \
	src/main.c \
	src/get_full_cmd.c \
	src/variables.c \
	src/DEBUG.c \
	src/ft_exec.c \
	src/quotes.c \
	list_managing/lst_managing.c \
	src/builtins/ft_cd.c \
	src/builtins/ft_pwd.c \
	src/builtins/ft_unset.c \
	src/builtins/ft_export.c \
	src/builtins/ft_exit.c \
	src/builtins/ft_echo.c \
	src/builtins/ft_env.c
OBJ=$(SRC:.c=.o)
LFT = libft
INCL = -I/src/ -I/list_managing/
CFLAGS = -Werror -Wall -Wextra -g
LFLAGS = -L $(LFT) -lft -lreadline

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(LFLAGS) $(INCL) -c $< -o $@

$(NAME) : $(OBJ)
	@make -C $(LFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

re : fclean all

clean :
	@rm -rf $(OBJ)
	@make fclean -C $(LFT)
	@echo Done

fclean : clean
	@rm -rf $(NAME)

f : fclean

.PHONY : clean re fclean all
