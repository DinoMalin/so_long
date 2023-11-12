/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:33:54 by jcario            #+#    #+#             */
/*   Updated: 2023/11/10 22:17:20 by jcario           ###   ########.fr       */
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

static void	init_sprites(t_env *env, t_sprites *sprites)
{
	init_dino(env);
	init_eggs(env);
	init_water(env);
	init_portal(env);
	sprites->tile = get_image(env, "assets/tile/tile_1.xpm");
}

static void	init_player(t_coords *player, t_env *env)
{
	get_coords(player, env->map);
	player->looking_left = 0;
}

void	init_env(t_env *env)
{
	char		**map_cpy;

	map_cpy = map_copy(env->map);
	if (!env->map || !map_is_valid(map_cpy, env))
		exit_game(env, 0);
	free_map(map_cpy);
	env->score = 0;
	env->count = 0;
	env->eggs = get_nb_eggs(env->map);
	env->width = ft_strlen(env->map[0]) * 32;
	env->height = len_double_dim(env->map) * 32;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "Dinosaure");
	init_player(&env->player, env);
	init_sprites(env, &env->sprites);
	dialogue();
}


// void	init_game(t_env *env)
// {
// 	/*
// 	`````````TO DO```````
// 	*/
// }