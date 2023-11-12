/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:17 by jcario            #+#    #+#             */
/*   Updated: 2023/11/10 17:42:35 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_count(t_env *env)
{
	char	*count;

	count = ft_itoa(env->count);
	update_map(env, 0, 0);
	mlx_string_put(env->mlx, env->win, 15, 15, COUNT_COLOR, count);
	free(count);
}

char *dino_direction(t_env *env)
{
	if (env->player.looking_left)
		return env->sprites.dino_left[env->sprites.dino_index];
	return env->sprites.dino_right[env->sprites.dino_index];
}

char	*image(t_env *env, int x, int y)
{
	if (env->map[y][x] == '1')
		return (env->sprites.water[env->sprites.water_index]);
	if (env->player.x == x && env->player.y == y)
		return (dino_direction(env));
	if (env->map[y][x] == 'P' && env->player.x == x && env->player.y == y)
		return (dino_direction(env));
	if (env->map[y][x] == 'C')
		return (env->sprites.egg[env->sprites.egg_index]);
	if (env->map[y][x] == 'E')
		return (env->sprites.portal[env->sprites.portal_index]);
	else
		return (env->sprites.tile);
}

void	update_map(t_env *env, int x, int y)
{
	t_coords co;

	co.x = x * 32;
	co.y = y * 32;
	mlx_put_image_to_window(env->mlx, env->win, image(env, x, y), co.x, co.y);
}

void	create_map(t_env *env)
{
	t_coords	coo;

	coo.y = 0;
	while (env->map[coo.y])
	{
		coo.x = 0;
		while (env->map[coo.y][coo.x])
		{
			update_map(env, coo.x, coo.y);
			coo.x++;
		}
		coo.y++;
	}
}
