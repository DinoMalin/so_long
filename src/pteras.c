/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pteras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:50:02 by jcario            #+#    #+#             */
/*   Updated: 2023/11/14 22:02:50 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	nb_pteras(t_env *env)
{
	t_coords	coos;
	int			result;

	coos.y = -1;
	result = 0;
	while (env->map[env->lv][++coos.y])
	{
		coos.x = -1;
		while (env->map[env->lv][coos.y][++coos.x])
		{
			if (env->map[env->lv][coos.y][coos.x] == 'V')
				result++;
		}
	}
	return (result);
}

void	init_pteras_cos(t_env *env)
{
	t_coords	coos;
	int			i;

	env->nb_pterras = nb_pteras(env);
	env->pteras = malloc(env->nb_pterras * sizeof(t_coords));
	if (!env->pteras)
		error("Error during allocation", env);
	i = 0;
	coos.y = -1;
	while (env->map[env->lv][++coos.y])
	{
		coos.x = -1;
		while (env->map[env->lv][coos.y][++coos.x])
		{
			if (env->map[env->lv][coos.y][coos.x] == 'V')
			{
				env->pteras[i].looking_left = 0;
				env->pteras[i].x = coos.x;
				env->pteras[i++].y = coos.y;
			}
		}
	}
}

static int	get_random(int max)
{
	int		file;
	char	buff[1];
	int		result;

	file = open("/dev/random", O_RDONLY);
	if (!file)
		return (-1);
	read(file, buff, 1);
	result = buff[0] % max;
	if (result < 0)
		result *= -1;
	return (result);
}

static void	update_pteras_map(t_env *env, int new_dir, t_coords cos, int index)
{
	update_map(env, cos.x, cos.y);
	if (new_dir == 0)
		if (!ft_strchr("1EC", env->map[env->lv][cos.y + 1][cos.x]))
			update_map(env, cos.x, cos.y + 1);
	if (new_dir == 1)
		if (!ft_strchr("1EC", env->map[env->lv][cos.y - 1][cos.x]))
			update_map(env, cos.x, cos.y - 1);
	if (new_dir == 2)
	{
		if (!ft_strchr("1EC", env->map[env->lv][cos.y][cos.x + 1]))
		{
			update_map(env, cos.x + 1, cos.y);
			env->pteras[index].looking_left = 0;
		}
	}
	if (new_dir == 3)
	{
		if (!ft_strchr("1EC", env->map[env->lv][cos.y][cos.x - 1]))
		{
			update_map(env, cos.x - 1, cos.y);
			env->pteras[index].looking_left = 1;
		}
	}
}

void	update_pteras(t_env *env, t_coords pl)
{
	int			i;
	int			new_dir;
	t_coords	old_cos;

	i = -1;
	while (++i < env->nb_pterras)
	{
		new_dir = get_random(6);
		old_cos = env->pteras[i];
		if (new_dir == 0)
			if (!ft_strchr("1EC", env->map[env->lv][old_cos.y + 1][old_cos.x]))
				env->pteras[i].y++;
		if (new_dir == 1)
			if (!ft_strchr("1EC", env->map[env->lv][old_cos.y - 1][old_cos.x]))
				env->pteras[i].y--;
		if (new_dir == 2)
			if (!ft_strchr("1EC", env->map[env->lv][old_cos.y][old_cos.x + 1]))
				env->pteras[i].x++;
		if (new_dir == 3)
			if (!ft_strchr("1EC", env->map[env->lv][old_cos.y][old_cos.x - 1]))
				env->pteras[i].x--;
		if (env->pteras[i].x == pl.x && env->pteras[i].y == pl.y && !env->god)
			exit_game(env, 0);
		update_pteras_map(env, new_dir, old_cos, i);
	}
}
