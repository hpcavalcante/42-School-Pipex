/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:48:22 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/12 17:46:40 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**find_cmd(char *cmd)
{
	char	**temp;
	int		i;

	i = 0;
	if (strchr_count(cmd, '\'') % 2 == 0)
	{
		while (cmd[i] && cmd[i] != '\'')
			i++;
		if (cmd[i] && cmd [i + 1])
			i++;
		while (cmd[i] && cmd[i] != '\'')
		{
			if (cmd[i] == ' ')
				cmd[i] = 1;
			i++;
		}
	}
	else
		write(2, "Error: ", 7);
	temp = space_split(cmd);
	return (temp);
}

char	*find_path(char *cmd, char **envp)
{
	char	**path_matrix;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_matrix = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_matrix[i])
	{
		path = path_join(path_matrix[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_matrix(path_matrix);
			return (path);
		}
		free(path);
		i++;
	}
	perror("Error: Command not found");
	free_matrix(path_matrix);
	exit(127);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = find_cmd(argv);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free(cmd);
		perror("Error: Command not found");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
		perror("Error: ");
}
