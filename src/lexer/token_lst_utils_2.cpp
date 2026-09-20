/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils_2.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:07:21 by acennadi          #+#    #+#             */
/*   Updated: 2026/09/17 19:15:15 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	link_extremities(t_token *to_del, t_token *temp, t_token *insert)
{
	while (temp != to_del)
		temp = temp->next;
	insert->prev = temp->prev;
	temp->prev->next = insert;
	while (insert->next)
		insert = insert->next;
	temp->next->prev = insert;
	insert->next = temp->next;
}

t_token	*insert_lst_between(t_token **head, t_token *to_del, t_token *insert)
{
	t_token	*temp;

	temp = *head;
	if (temp == nullptr)
		*head = insert;
	else if (temp == to_del)
	{
		*head = insert;
		insert->next = temp->next;
		if (temp->next != nullptr)
			temp->next->prev = insert;
	}
	else
		link_extremities(to_del, temp, insert);
	free_ptr(to_del->str);
	free_ptr(to_del);
	return (insert);
}
