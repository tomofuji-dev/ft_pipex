/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:47:24 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/04 15:46:01 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "constant.h"

bool		pp_check_argc(int argc);
t_cmd		*pp_args_to_cmdlst(int argc, char *argv[], char *envp[]);
static char	**pp_split_path(char *envp[]);

bool	pp_check_argc(int argc)
{
	return (argc >= 5);
}

t_cmd	*pp_args_to_cmdlst(int argc, char *argv[], char *envp[])
{
	char	**env_split;
	t_cmd	*cmd_lst;
	int		i;

	env_split = pp_split_path(envp);
	if (env_split == NULL)
		exit (ENV_SPLIT_MALLOC_ERR);
	cmd_lst = NULL;
	i = 2 + !ft_strncmp(argv[1], "here_doc", HEREDOC_LEN);
	while (i < argc - 1)
	{
		if (pp_cmd_add_back(&cmd_lst, argv[i], envp, env_split) == false)
		{
			pp_clear_cmdlst(cmd_lst, i - 2);
			exit (CMD_MALLOC_ERR);
		}
		i++;
	}
	free(env_split);
	return (cmd_lst);
}

static char	**pp_split_path(char *envp[])
{
	char	*save;

	while (*envp != NULL)
	{
		save = *envp;
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (ft_split(&(save[5]), ':'));
		envp++;
	}
	return (NULL);
}
