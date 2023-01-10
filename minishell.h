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

// --------------------------------- STRUCTURES --------------------------------

typedef struct s_vars
{
	struct s_vars	*next;
	struct s_vars	*prev;
	char			*var;
	char			*value;
}t_vars;

typedef struct s_arg
{
	struct s_arg	*next;
	struct s_arg	*prev;
	int				id;
	char			*data;
}t_arg;

typedef struct s_envp
{
	struct s_vars	*head;
	struct s_vars	*tail;
	int				length;
}t_envp;

typedef struct s_line
{
	struct s_envp	*envp;
	struct s_arg	*head;
	struct s_arg	*tail;
	int				length;
}t_line;

// --------------------------------- FUNCTIONS ---------------------------------

// access.c
char		*get_cmd_path(char *cmd, char **envp);
int			is_cmd(char *cmd, char **envp);
char		*add_path(char *path, char *cmd);

// main.c
void		ft_str_free(char **str);
int			exec_cmd(char *cmd, char **args, char **envp);

//parsing.c
void		prompt(t_envp *envp);
// int			get_quotes(t_line *line, char *str, int i, char c);
void		lit_parse(t_line *line, char **envp);
void		parse(t_line *line, char *str);
int			get_literal(t_line *line, char *str, int i);
void		main_exec(char *str, t_envp *envp);
void		debug(t_line *chibre);
char		**get_full_cmd(t_arg *cmd);

//line_managing.c
t_line		*lst_new(t_envp *envp);
t_line		*add_arg_tail(t_line *list, char *str, int id);
void		lst_free(t_line **lst);

//envp_managing.c
t_envp		*lst_env_new(void);
t_envp		*add_arg_tail_env(t_envp *envp, char *var, char *value);
void		lst_env_free(t_envp **envp);
void		ft_delone_envp(t_vars **head, t_vars *del);

//envp_utils.c
t_envp		*arr_to_lst(t_envp *lst, char **arr);
char		**lst_to_arr(t_envp *envp_lst);

//variables
char		*change_variable(char *str, int i, char **envp);
void		check_variables(t_line *line, char **envp);
char		*ft_strjoinjoin(char *start, char *mid, char *end);

//DEBUG.c
void		debug(t_line *chibre);

//get_full_cmd.c
char		**get_full_cmd(t_arg *cmd);

//ft_exec.c
void		ft_exec(t_line *lst, char **envp);

//quotes.c
int			get_quotes(char *data);
char		*remove_quotes(char *data);

//env.c
int			ft_env(char **cmd, t_envp *envp);

//pwd.c
int			ft_pwd(char **cmd);

//export.c
int			ft_export(char **cmd, t_envp *envp);

//ft_export_utils.c
void		print_env_alpha(t_envp *envp);

//unset.c
int			ft_unset(char **cmd, t_envp *envp);

//cd.c
int			ft_cd(char **cmd);

//exit.c
int			ft_exit(t_line *lst, char **cmd, char **envp);

//echo.c
int			ft_echo(char **cmd);

#endif
