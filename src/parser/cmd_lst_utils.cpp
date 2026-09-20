/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:07:21 by acennadi          #+#    #+#             */
/*   Updated: 2026/09/17 19:14:46 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	initialize_cmd(t_command **cmd)
{
	(*cmd)->command = nullptr;
	(*cmd)->path = nullptr;
	(*cmd)->args = nullptr;
	(*cmd)->pipe_output = false;
	(*cmd)->pipe_fd = 0;
	(*cmd)->prev = nullptr;
	(*cmd)->next = nullptr;
}

t_command	*lst_new_cmd(bool value)
{
	t_command	*new_node;

	new_node = (t_command *)malloc(sizeof(t_command));
	if (!(new_node))
		return (nullptr);
	ft_memset(new_node, 0, sizeof(t_command));
	new_node->pipe_output = value;
	initialize_cmd(&new_node);
	return (new_node);
}

void	lst_add_back_cmd(t_command **alst, t_command *new_node)
{
	t_command	*start;

	start = *alst;
	if (start == nullptr)
	{
		*alst = new_node;
		return ;
	}
	if (alst && *alst && new_node)
	{
		while (start->next != nullptr)
			start = start->next;
		start->next = new_node;
		new_node->prev = start;
	}
}

t_command	*lst_last_cmd(t_command *cmd)
{
	while (cmd->next != nullptr)
		cmd = cmd->next;
	return (cmd);
}
