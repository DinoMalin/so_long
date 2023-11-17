/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:33:54 by jcario            #+#    #+#             */
/*   Updated: 2023/11/15 16:44:14 by jcario           ###   ########.fr       */
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
	get_coords(&env->player, env->map[env->lv]);
	env->player.looking_left = 0;
}

void	init_env(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	ft_printf("\nLEVEL - %d\n", env->lv + 1);
	env->score = 0;
	env->count = 0;
	env->eggs = get_nb_eggs(env->map[env->lv]);
	env->width = ft_strlen(env->map[env->lv][0]) * 32;
	env->height = len_double_dim(env->map[env->lv]) * 32;
	env->sprites.portal_index = 0;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "Dinosaure");
	if (env->lv == 0)
		init_sprites(env);
	init_player(env);
	init_pteras_cos(env);
	create_map(env);
	print_score(env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_hook(env->win, 17, 0, close_window, env);
	mlx_loop_hook(env->mlx, loop, env);
	mlx_loop(env->mlx);
}
