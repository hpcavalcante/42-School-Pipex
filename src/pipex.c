/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:19:40 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/21 11:22:30 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		perror("Error: ");
		close(infile);
		exit(127);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	child2_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("Error: ");
		close(outfile);
		exit(127);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

void	parent(int *fd, int pid1, int pid2)
{
	int	wstatus;
	int	status_code;

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
		exit(status_code);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;
	int		pid2;

	if (argc != 5)
	{
		write(2, "Error: Invalid number of arguments.\n", 37);
		write(1, "Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 43);
		exit(1);
	}
	else
	{
		if (pipe(fd) < 0)
			perror("Error: ");
		pid = fork();
		if (pid == 0)
			child_process(argv, envp, fd);
		pid2 = fork();
		if (pid2 == 0)
			child2_process(argv, envp, fd);
		parent(fd, pid, pid2);
	}
	return (0);
}
