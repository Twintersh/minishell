/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:55:32 by twinters          #+#    #+#             */
/*   Updated: 2022/10/06 11:19:05 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// --------------------------------- INCLUDES ----------------------------------

// miscellaneous
# include "libft/libft.h"
# include <stdio.h>

// waitpid
# include <sys/types.h>
# include <sys/wait.h>

// readline
# include <readline/readline.h>
# include <readline/history.h>

// --------------------------------- DEFINES -----------------------------------

# define CHILD 0

// --------------------------------- STRUCTURES --------------------------------

// --------------------------------- FUNCTIONS ---------------------------------

// access.c
char	*get_cmd_path(char *cmd, char **envp);

// main.c
void	ft_str_free(char **str);
void	exec_cmd(char *cmd, char **args, char **envp);

#endif