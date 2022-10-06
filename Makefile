CC = gcc
NAME = minishell
SRC = $(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
LFT = libft
CFLAGS = -Werror -Wall -Wextra
LFLAGS = -L $(LFT) -lft -lreadline 

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(LFLAGS) -I/src/ -c $< -o $@

$(NAME) : $(OBJ)
	@make -C $(LFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

re : fclean all

clean :
	@rm -rf src/*.o
	@make fclean -C $(LFT)
	@echo Done

fclean : clean
	@rm -rf $(NAME)
