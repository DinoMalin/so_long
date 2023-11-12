/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:44 by jcario            #+#    #+#             */
/*   Updated: 2023/11/12 23:21:14 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_anim(t_env *env)
{
	t_coords	co;
	int			i;

	co.y = 0;
	i = -1;
	while (env->map[co.y])
	{
		co.x = 0;
		while(env->map[co.y][co.x])
		{
			if (co.x == env->player.x && co.y == env->player.y)
				update_map(env, co.x, co.y);
			else if (ft_strchr("1EC", env->map[co.y][co.x]))
				update_map(env, co.x, co.y);
			co.x++;
		}
		co.y++;
	}
	update_count(env);
}

static void	update_sprite(t_env *env)
{
	if (env->score == env->eggs)
		env->sprites.portal_index += 1;
	env->sprites.dino_index++;
	env->sprites.egg_index++;
	env->sprites.ptera_index++;
	if (env->sprites.ptera_index == 3)
		env->sprites.ptera_index = 0;
	if (env->sprites.dino_index == 3)
		env->sprites.dino_index = 0;
	if (env->sprites.portal_index == 6)
		env->sprites.portal_index = 0;
	if (env->sprites.egg_index == 4)
		env->sprites.egg_index = 0;
	update_pteras(env, env->player);
	update_anim(env);
}

int		loop(t_env *env)
{
	static int	frame = 0;

	if (frame == 25000)
		env->sprites.water_index++;
	if (env->sprites.water_index == 4)
		env->sprites.water_index = 0;
	if (frame == 30000)
		update_sprite(env);
	if (frame > 50000)
		frame = 0;
	frame++;
	return (0);
}

//
// eau : 25 000
// dino : 