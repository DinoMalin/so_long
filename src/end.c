/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:29:03 by jcario            #+#    #+#             */
/*   Updated: 2023/11/12 23:30:46 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	free_sprites(t_env *env)
{
	int	i;

	i = 0;
	while (i < 3)
		mlx_destroy_image(env->mlx, env->sprites.dino_left[i++]);
	i = 0;
	while (i < 3)
		mlx_destroy_image(env->mlx, env->sprites.dino_right[i++]);
	i = 0;
	while (i < 4)
		mlx_destroy_image(env->mlx, env->sprites.egg[i++]);
	i = 0;
	while (i < 6)
		mlx_destroy_image(env->mlx, env->sprites.portal[i++]);
	i = 0;
	while (i < 4)
		mlx_destroy_image(env->mlx, env->sprites.water[i++]);
	i = 0;
	while (i < 3)
		mlx_destroy_image(env->mlx, env->sprites.ptera_left[i++]);
	i = 0;
	while (i < 3)
		mlx_destroy_image(env->mlx, env->sprites.ptera_right[i++]);
	mlx_destroy_image(env->mlx, env->sprites.tile);
}

void	exit_game(t_env *env, int win)
{
	if (win)
		ft_printf("%sLES OEUFS SONT SAUVÉS À PRÉSENT !%s\n", GREEN, WHITE);
	else
	{
		ft_printf("%sGAME OVER - TES ENFANTS ", RED);
		ft_printf("SERVIRONT LES PTERAS MOUAHAHAHA !!%s\n", WHITE);
	}
	free_map(env->map);
	free_sprites(env);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	free(env->pteras);
	exit(0);
}

void	error(char *str, t_env *env)
{
	ft_printf("Error\n%s.\n", str);
	free_map(env->map);
	exit(0);
}