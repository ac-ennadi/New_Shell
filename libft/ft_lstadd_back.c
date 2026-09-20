/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:59:31 by acennadi          #+#    #+#             */
/*   Updated: 2025/08/26 10:54:58 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *tnew)
{
	t_list	*ptr;

	if (!lst || !tnew)
		return ;
	if (*lst == NULL)
	{
		*lst = tnew;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = tnew;
}
