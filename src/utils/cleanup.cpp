/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:07:21 by acennadi          #+#    #+#             */
/*   Updated: 2026/09/17 19:14:56 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.hpp"

void	free_data(t_data *data, bool clear_history)
{
	if (data && data->user_input)
	{
		free_ptr(data->user_input);
		data->user_input = nullptr;
	}
	if (data && data->token)
		lstclear_token(&data->token, &free_ptr);
	if (data && data->cmd)
		lst_clear_cmd(&data->cmd, &free_ptr);
	if (clear_history == true)
	{
		if (data && data->working_dir)
			free_ptr(data->working_dir);
		if (data && data->old_working_dir)
			free_ptr(data->old_working_dir);
		if (data && data->env)
			free_str_tab(data->env);
		rl_clear_history();
	}
}

void	close_fds(t_command *cmds, bool close_backups)
{
	if (cmds->io_fds)
	{
		if (cmds->io_fds->fd_in != -1)
			close(cmds->io_fds->fd_in);
		if (cmds->io_fds->fd_out != -1)
			close(cmds->io_fds->fd_out);
		if (close_backups)
			restore_io(cmds->io_fds);
	}
	close_pipe_fds(cmds, nullptr);
}

void	free_io(t_io_fds *io)
{
	if (!io)
		return ;
	restore_io(io);
	if (io->heredoc_delimiter)
	{
		unlink(io->infile);
		free_ptr(io->heredoc_delimiter);
	}
	if (io->infile)
		free_ptr(io->infile);
	if (io->outfile)
		free_ptr(io->outfile);
	if (io)
		free_ptr(io);
}

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = nullptr;
			}
			i++;
		}
		free(tab);
		tab = nullptr;
	}
}

void	free_ptr(void *ptr)
{
	if (ptr != nullptr)
	{
		free(ptr);
		ptr = nullptr;
	}
}
