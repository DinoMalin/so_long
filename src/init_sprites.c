/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:03:47 by jcario            #+#    #+#             */
/*   Updated: 2023/11/12 23:27:52 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_dino(t_env *env)
{
	env->sprites.dino_left[0] = get_image(env, "assets/dino/dino_l_1.xpm");
	env->sprites.dino_left[1] = get_image(env, "assets/dino/dino_l_2.xpm");
	env->sprites.dino_left[2] = get_image(env, "assets/dino/dino_l_3.xpm");
	env->sprites.dino_right[0] = get_image(env, "assets/dino/dino_r_1.xpm");
	env->sprites.dino_right[1] = get_image(env, "assets/dino/dino_r_2.xpm");
	env->sprites.dino_right[2] = get_image(env, "assets/dino/dino_r_3.xpm");
	env->sprites.dino_index = 0;
}

void	init_eggs(t_env *env)
{
	env->sprites.egg[0] = get_image(env, "assets/egg/egg_1.xpm");
	env->sprites.egg[1] = get_image(env, "assets/egg/egg_2.xpm");
	env->sprites.egg[2] = get_image(env, "assets/egg/egg_3.xpm");
	env->sprites.egg[3] = get_image(env, "assets/egg/egg_4.xpm");
	env->sprites.egg_index = 0;
}

void	init_portal(t_env *env)
{
	env->sprites.portal[0] = get_image(env, "assets/portal/portal_1.xpm");
	env->sprites.portal[1] = get_image(env, "assets/portal/portal_2.xpm");
	env->sprites.portal[2] = get_image(env, "assets/portal/portal_3.xpm");
	env->sprites.portal[3] = get_image(env, "assets/portal/portal_4.xpm");
	env->sprites.portal[4] = get_image(env, "assets/portal/portal_5.xpm");
	env->sprites.portal[5] = get_image(env, "assets/portal/portal_6.xpm");
	env->sprites.portal_index = 0;
}

void	init_water(t_env *env)
{
	env->sprites.water[0] = get_image(env, "assets/water/water_1.xpm");
	env->sprites.water[1] = get_image(env, "assets/water/water_2.xpm");
	env->sprites.water[2] = get_image(env, "assets/water/water_3.xpm");
	env->sprites.water[3] = get_image(env, "assets/water/water_4.xpm");
	env->sprites.water_index = 0;
}

void	init_ptera(t_env *env)
{
	env->sprites.ptera_right[0] = get_image(env, "assets/ptera/ptera_right_1.xpm");
	env->sprites.ptera_right[1] = get_image(env, "assets/ptera/ptera_right_2.xpm");
	env->sprites.ptera_right[2] = get_image(env, "assets/ptera/ptera_right_3.xpm");
	env->sprites.ptera_left[0] = get_image(env, "assets/ptera/ptera_left_1.xpm");
	env->sprites.ptera_left[1] = get_image(env, "assets/ptera/ptera_left_2.xpm");
	env->sprites.ptera_left[2] = get_image(env, "assets/ptera/ptera_left_3.xpm");
	env->sprites.ptera_index = 0;
}