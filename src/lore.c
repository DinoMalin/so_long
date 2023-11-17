/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:39:53 by jcario            #+#    #+#             */
/*   Updated: 2023/11/14 16:49:12 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_lore(t_env *env)
{
	env->width = 1300;
	env->height = 900;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "Dinosaure");
	env->cinematics[0] = get_image(env, "assets/cinematic/1.xpm");
	env->cinematics[1] = get_image(env, "assets/cinematic/2.xpm");
	env->cinematics[2] = get_image(env, "assets/cinematic/3.xpm");
	env->current_cinematic = 0;
	mlx_put_image_to_window(env->mlx, env->win, env->cinematics[0], 0, 0);
	mlx_key_hook(env->win, key_hook, env);
	mlx_hook(env->win, 17, 0, close_window, env);
	mlx_loop(env->mlx);
}
