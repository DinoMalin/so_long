/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:29:03 by jcario            #+#    #+#             */
/*   Updated: 2023/11/14 23:30:39 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char ***map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			free(map[i][j++]);
		free(map[i++]);
	}
	free(map);
}

static void	free_cinematics(t_env *env)
{
	mlx_destroy_image(env->mlx, env->cinematics[0]);
	mlx_destroy_image(env->mlx, env->cinematics[1]);
	mlx_destroy_image(env->mlx, env->cinematics[2]);
}

static void	free_sprites(t_env *env)
{
	int	i;

	i = 0;
	while (i < 3)
		mlx_destroy_image(env->mlx, env->sprites.dino_right[i++]);
	i = 0;
	while (i < 3)
		mlx_destroy_image(env->mlx, env->sprites.dino_left[i++]);
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

int	exit_game(t_env *env, int win)
{
	if (win)
		ft_printf("%sLES OEUFS SONT SAUVÉS !%s\n", GREEN, WHITE);
	else
	{
		ft_printf("%sGAME OVER - TES ENFANTS ", RED);
		ft_printf("SERVIRONT LES PTERAS MOUAHAHAHA !!%s\n", WHITE);
	}
	if (env->current_cinematic == 3)
	{
		free_sprites(env);
		free(env->pteras);
	}
	free_map(env->map);
	if (env->current_cinematic == -1)
		exit(0);
	free_cinematics(env);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(0);
	return (0);
}

void	error(char *str, t_env *env)
{
	ft_printf("Error\n%s.\n", str);
	free_map(env->map);
	exit(0);
}
