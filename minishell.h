/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:55:32 by twinters          #+#    #+#             */
/*   Updated: 2022/10/06 16:07:29 by mcochin          ###   ########.fr       */
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
# include <sys/ressource.h>
# include <dirent.h>
# include <errno.h>

// --------------------------------- DEFINES -----------------------------------

# define CHILD 0
# define PIPE_OUT 0
# define PIPE_IN 1

// --------------------------------- STRUCTURES --------------------------------

// --------------------------------- FUNCTIONS ---------------------------------

// access.c
char	*get_cmd_path(char *cmd, char **envp);

// main.c
void	ft_str_free(char **str);
void	exec_cmd(char *cmd, char **args, char **envp);

#endif
