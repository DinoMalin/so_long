/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:53:54 by jcario            #+#    #+#             */
/*   Updated: 2023/11/14 23:20:04 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_env *env)
{
	exit_game(env, 0);
	return (0);
}

int	key_hook(int keycode, t_env *env)
{
	int	i;

	if (keycode == ESCAPE)
		close_window(env);
	if (keycode == NEXT && env->current_cinematic == 2)
	{
		env->current_cinematic = 3;
		init_env(env);
	}
	else if (keycode == NEXT && env->current_cinematic < 2)
	{
		env->current_cinematic++;
		i = env->current_cinematic;
		mlx_put_image_to_window(env->mlx, env->win, env->cinematics[i], 0, 0);
	}
	if (ft_strchr("zqsdRQTSwasd", keycode) && env->current_cinematic == 3)
		move(keycode, env);
	return (0);
}

int	main(int ac, char **av)
{
	t_env		env;
	int			i;

	env.god = 0;
	if (!ft_strncmp(av[ac - 1], "julian=goat", 12))
		env.god = 1;
	if (ac == 1 || (ac == 2 && env.god))
		env.map = get_default("maps/dino.ber", &env);
	else
		env.map = get_maps(av, ac - env.god, &env);
	env.lv = 0;
	i = 0;
	while (i < ac - 1 - env.god)
		map_is_valid(&env, env.map[i++]);
	env.current_cinematic = -1;
	init_lore(&env);
}
