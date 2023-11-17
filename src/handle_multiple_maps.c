/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_multiple_maps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:27:27 by jcario            #+#    #+#             */
/*   Updated: 2023/11/15 13:41:09 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	***get_maps(char **av, int ac, t_env *env)
{
	int		i;
	char	***result;

	i = 0;
	result = malloc((ac + 1) * sizeof(char **));
	while (i < ac - 1)
	{
		result[i] = get_map(av[i + 1]);
		i++;
	}
	result[i] = NULL;
	env->nb_lv = ac - 1;
	return (result);
}

char	***get_default(char *def, t_env *env)
{
	char	***result;

	result = malloc(2 * sizeof(char **));
	result[0] = get_map(def);
	result[1] = NULL;
	env->nb_lv = 1;
	return (result);
}

void	next_level(t_env *env)
{
	env->lv++;
	if (env->lv == env->nb_lv)
		exit_game(env, 1);
	else
	{
		free(env->pteras);
		init_env(env);
	}
}
