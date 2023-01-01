/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:51:23 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/06 15:42:25 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

typedef struct s_cmd
{
	char			cmd_path[1024];
	char			**cmd_split;
	char			**envp;
	pid_t			pid;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	int				in_fd;
	int				out_fd;
//		 type
}	t_cmd;

bool	pp_check_argc(int argc);
bool	pp_check_argc(int argc);
t_cmd	*pp_args_to_cmdlst(int argc, char *argv[], char **envp);
bool	pp_cmd_add_back(t_cmd **cmd_lst, char *cmd_str, \
						char *envp[], char **env_split);
void	pp_clear_cmdlst(t_cmd *cmd_lst, int free_size);
void	pp_file_open(int argc, char *argv[], t_cmd *cmd);
void	pp_file_close(t_cmd *cmd);

#endif