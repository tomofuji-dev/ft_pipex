/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:17:50 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/07 11:09:42 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "constant.h"

int		pp_exec(t_cmd *cmd_lst);
void	pp_exec_a_cmd(t_cmd *cmd, int prev_pipe[2], int now_pipe[2]);
void	close_pipe(int fd[2]);
void	copy_pipe(int dest[2], int src[2]);
int		wait_all(t_cmd *cmd_lst);

int	pp_exec(t_cmd *cmd_lst)
{
	int		prev_pipe[2];
	int		now_pipe[2];
	t_cmd	*now_cmd;

	prev_pipe[0] = 0;
	prev_pipe[1] = 1;
	now_cmd = cmd_lst;
	while (now_cmd != NULL)
	{
		pipe(now_pipe);
		pp_exec_a_cmd(now_cmd, prev_pipe, now_pipe);
		close_pipe(prev_pipe);
		copy_pipe(prev_pipe, now_pipe);
		now_cmd = now_cmd->next;
	}
	return (wait_all(cmd_lst));
}

void	pp_exec_a_cmd(t_cmd *cmd, int prev_pipe[2], int now_pipe[2])
{
	int		fd[2];

	fd[0] = prev_pipe[0];
	fd[1] = now_pipe[1];
	if (cmd->in_fd >= 0)
		fd[0] = cmd->in_fd;
	if (cmd->out_fd >= 0)
		fd[1] = cmd->out_fd;
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		close_pipe(fd);
		close_pipe(prev_pipe);
		close_pipe(now_pipe);
		execve(cmd->cmd_path, cmd->cmd_split, cmd->envp);
	}
	else
		return ;
}

void	close_pipe(int fd[2])
{
	if (fd[0] != 0)
		close(fd[0]);
	if (fd[1] != 1)
		close(fd[1]);
}

void	copy_pipe(int dest[2], int src[2])
{
	dest[0] = src[0];
	dest[1] = src[1];
}

int	wait_all(t_cmd *cmd_lst)
{
	int		status;
	t_cmd	*now_cmd;

	now_cmd = cmd_lst;
	while (now_cmd != NULL)
	{
		waitpid(now_cmd->pid, &status, 1);
		now_cmd = now_cmd->next;
	}
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		errnum;
	t_cmd	*cmd_lst;

	if (pp_check_argc(argc) == false)
		return (ARGC_ERR);
	cmd_lst = pp_args_to_cmdlst(argc, argv, envp);
	pp_file_open(argc, argv, cmd_lst);
	errnum = pp_exec(cmd_lst);
	// pp_clear_cmdlst(cmd_lst, argc - 2);
	// pp_file_close(cmd_lst);
	return (errnum);
}
