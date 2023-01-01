/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:33:24 by t.fuji            #+#    #+#             */
/*   Updated: 2022/12/06 15:20:41 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool			pp_cmd_add_back(t_cmd **cmd_lst, char *cmd_str, \
									char *envp[], char **env_split);
void			pp_clear_cmdlst(t_cmd *cmd_lst, int free_size);
static t_cmd	*pp_create_cmd(char *cmd_str, char *envp[], char **env_split);
static bool		pp_find_cmd_path(char *cmd_path, char *cmd_name, \
									char **env_split);


bool	pp_cmd_add_back(t_cmd **cmd_lst, char *cmd_str, \
						char *envp[], char *env_split[])
{
	t_cmd	*new;
	t_cmd	*now_cmd;

	if (*cmd_lst == NULL)
	{
		*cmd_lst = pp_create_cmd(cmd_str, envp, env_split);
		return (cmd_lst != NULL);
	}
	new = pp_create_cmd(cmd_str, envp, env_split);
	if (new == NULL)
		return (false);
	now_cmd = *cmd_lst;
	while (now_cmd->next != NULL)
		now_cmd = now_cmd->next;
	now_cmd->next = new;
	new->prev = now_cmd;
	return (true);
}

void	pp_clear_cmdlst(t_cmd *cmd_lst, int free_size)
{
	int		i;
	t_cmd	*tmp_cmd;
	t_cmd	*now_cmd;

	i = 0;
	now_cmd = cmd_lst;
	while (i < free_size)
	{
		free(now_cmd->cmd_split);
		tmp_cmd = now_cmd->next;
		free(now_cmd);
		now_cmd = tmp_cmd;
		i++;
	}
}

static t_cmd	*pp_create_cmd(char *cmd_str, char *envp[], char **env_split)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->cmd_split = ft_split(cmd_str, ' ');
	if (cmd->cmd_split == NULL)
	{
		free(cmd);
		return (NULL);
	}
	cmd->envp = envp;
	cmd->next = NULL;
	cmd->prev = NULL;
	cmd->in_fd = -1;
	cmd->out_fd = -1;
	if (pp_find_cmd_path(cmd->cmd_path, \
						cmd->cmd_split[0], env_split) == false)
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

static bool	pp_find_cmd_path(char *cmd_path, char *cmd_name, char **env_split)
{
	if (access(cmd_name, X_OK) == 0)
	{
		ft_strlcpy(cmd_path, cmd_name, 1024);
		return (true);
	}
	while (*env_split)
	{
		ft_strlcpy(cmd_path, *env_split, 1024);
		// todo: over 1024 case
		// todo: continue when return NULL
		ft_strlcat(cmd_path, "/", 1024);
		ft_strlcat(cmd_path, cmd_name, 1024);
		if (access(cmd_path, X_OK) == 0)
			return (true);
		env_split++;
	}
	return (false);
}
