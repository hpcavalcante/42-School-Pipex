/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:07:10 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/13 01:29:41 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	strchr_count(char *str, int c)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str);
	while (i > -1)
	{
		if (str[i] == (unsigned char)c)
			j++;
		i--;
	}
	return (j);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

char	*path_join(const char *s1, const char *s2)
{
	int		i;
	int		size;
	char	*out;

	i = 0;
	size = ft_strlen(s1) + 1;
	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '/';
	i = 0;
	while (s2[i])
	{
		out[size] = s2[i];
		i++;
		size++;
	}
	out[size] = '\0';
	return (out);
}

char	**space_split(char *cmd)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = ft_split(cmd, ' ');
	while (temp[j])
	{	
		i = 0;
		while (temp[j][i] && temp[j][i] != '\'')
			i++;
		if (temp[j][i] && temp[j][i + 1])
			i++;
		while (temp[j][i] && temp[j][i] != '\'')
		{
			if (temp[j][i] == 1)
				temp[j][i] = ' ';
			i++;
		}
		j++;
	}
	return (temp);
}

void	free_exit(char **matrix, int exitcode)
{
	perror("Error: ");
	free_matrix(matrix);
	exit(exitcode);
}
