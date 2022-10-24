/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< Updated upstream
/*   Created: 2022/10/21 15:40:45 by twinters          #+#    #+#             */
/*   Updated: 2022/10/24 12:25:30 by twinters         ###   ########.fr       */
=======
/*   Created: 2022/10/06 09:55:32 by twinters          #+#    #+#             */
/*   Updated: 2022/10/21 17:54:46 by mcochin          ###   ########.fr       */
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// --------------------------------- INCLUDES ----------------------------------

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <dirent.h>
# include <errno.h>

// --------------------------------- DEFINES -----------------------------------

# define CHILD 0
# define PIPE_OUT 0
# define PIPE_IN 1

# define ARG 1
# define CMD 2
# define PIPE 3
# define REDIR 4
# define LITERAL 5
# define DQUOTE 10

// --------------------------------- STRUCTURES --------------------------------

typedef struct s_arg
{
	struct s_arg	*next;
	struct s_arg	*prev;
	int				id;
	char			*data;
}t_arg;

typedef struct s_line
{
	struct s_arg	*head;
	struct s_arg	*tail;
	int				length;
	char			**envp;
}t_line;

// --------------------------------- FUNCTIONS ---------------------------------

// access.c
char		*get_cmd_path(char *cmd, char **envp);
int			is_cmd(char *cmd, char **envp);
char		*add_path(char *path, char *cmd);

// main.c
void		ft_str_free(char **str);
void		exec_cmd(char *cmd, char **args, char **envp);

//parsing.c
void		prompt(char **envp);
int			get_quotes(t_line *line, char *str, int i, char c);
void		lit_parse(t_line *line);
void		parse(t_line *line, char *str);
int			get_literal(t_line *line, char *str, int i);
void		main_exec(char *str, char **envp);
void		debug(t_line *chibre);
char		**get_full_cmd(t_arg *cmd);

//lst_managing.c
t_line		*lst_new(char **envp);
t_line		*add_arg_tail(t_line *list, char *str, int id);
// t_line		*add_arg_head(t_line *lst, int data);
void		lst_free(t_line **lst);

//variables
char		*change_variable(char *str, int i, char **envp);
void		check_variables(t_line *line);

//DEBUG.c
void		debug(t_line *chibre);

//get_full_cmd.c
char		**get_full_cmd(t_arg *cmd);

#endif
