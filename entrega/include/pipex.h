/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:42:50 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/12 16:01:56 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

/* Main functions */
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
char	**find_cmd(char *cmd);
/* Utils */
char	*path_join(const char *s1, const char *s2);
void	free_matrix(char **matrix);
int		strchr_count(char *str, int c);
char	**space_split(char *cmd);
#endif