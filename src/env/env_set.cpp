/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:07:21 by acennadi          #+#    #+#             */
/*   Updated: 2026/09/17 19:34:46 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.hpp"

static char	**realloc_env_vars(t_data *data, int size)
{
	char	**new_env;
	int		i;

	new_env = static_cast<char **>(ft_calloc(size + 1, sizeof *new_env));
	if (!new_env)
		return (nullptr);
	i = 0;
	while (data->env[i] && i < size)
	{
		new_env[i] = ft_strdup(data->env[i]);
		free_ptr(data->env[i]);
		i++;
	}
	free(data->env);
	return (new_env);
}

bool	set_env_var(t_data *data, char *key, char *value)
{
	int		idx;
	char	*tmp;
	char	empty_value[] = "";

	idx = get_env_var_index(data->env, key);
	if (value == nullptr)
		value = empty_value;
	tmp = ft_strjoin("=", value);
	if (!tmp)
		return (false);
	if (idx != -1 && data->env[idx] != nullptr)
	{
		free_ptr(data->env[idx]);
		data->env[idx] = ft_strjoin(key, tmp);
	}
	else
	{
		idx = env_var_count(data->env);
		data->env = realloc_env_vars(data, idx + 1);
		if (data->env == nullptr)
			return (false);
		data->env[idx] = ft_strjoin(key, tmp);
	}
	free_ptr(tmp);
	return (true);
}

bool	remove_env_var(t_data *data, int idx)
{
	int	i;
	int	count;

	if (idx < 0 || idx >= env_var_count(data->env))
		return (false);
	free_ptr(data->env[idx]);
	i = idx;
	count = idx;
	while (data->env[i + 1] != nullptr)
	{
		data->env[i] = ft_strdup(data->env[i + 1]);
		free_ptr(data->env[i + 1]);
		count++;
		i++;
	}
	data->env = realloc_env_vars(data, count);
	if (data->env == nullptr)
		return (false);
	return (true);
}
