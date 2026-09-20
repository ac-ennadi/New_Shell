/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:07:21 by acennadi          #+#    #+#             */
/*   Updated: 2026/09/17 19:15:04 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.hpp"

int	env_builtin(t_data *data, char **args)
{
	int	i;

	if (args && args[1])
		return (errmsg_cmd("env", nullptr, "too many arguments", 2));
	i = 0;
	if (!data->env)
		return (EXIT_FAILURE);
	while (data->env[i])
		ft_putendl_fd(data->env[i++], STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
