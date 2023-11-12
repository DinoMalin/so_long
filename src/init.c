/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:33:54 by jcario            #+#    #+#             */
/*   Updated: 2023/11/12 23:36:24 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_image(t_env *env, char *img)
{
	int		w;
	int		h;
	void	*result;

	result = mlx_xpm_file_to_image(env->mlx, img, &w, &h);
	return (result);
}

static void	init_sprites(t_env *env)
{
	init_dino(env);
	init_eggs(env);
	init_water(env);
	init_portal(env);
	init_ptera(env);
	env->sprites.tile = get_image(env, "assets/tile/tile_1.xpm");
}

static void	init_player(t_env *env)
{
	get_coords(&env->player, env->map);
	env->player.looking_left = 0;
}

void	init_env(t_env *env)
{

	if (!env->map || !map_is_valid(env))
		exit_game(env, 0);
	env->score = 0;
	env->count = 0;
	env->eggs = get_nb_eggs(env->map);
	env->width = ft_strlen(env->map[0]) * 32;
	env->height = len_double_dim(env->map) * 32;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "Dinosaure");
	init_player(env);
	init_sprites(env);
	init_pteras_cos(env);
	dialogue();
}


// void	init_game(t_env *env)
// {
// 	/*
// 	`````````TO DO```````
// 	*/
// }