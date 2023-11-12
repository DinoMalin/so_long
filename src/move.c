/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:28:23 by jcario            #+#    #+#             */
/*   Updated: 2023/11/12 23:19:56 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_score(t_env *env)
{
	if (env->count > 0)
		ft_printf("\033[1A");
	ft_printf("Number of moves : \033[31m%d\033[37m", env->count);
	ft_printf("    SCORE : \033[32m%d\033[37m\n", env->score);
}

void	update_coordinates(char ch, t_env *env)
{
	if (ch == 'z' || ch == 'R' || ch == 'w')
		if (!ft_strchr("1", env->map[env->player.y - 1][env->player.x]))
			env->player.y--;
	if (ch == 's' || ch == 'T')
		if (!ft_strchr("1", env->map[env->player.y + 1][env->player.x]))
			env->player.y++;
	if (ch == 'q' || ch == 'Q' || ch == 'a')
	{
		if (!ft_strchr("1", env->map[env->player.y][env->player.x - 1]))
			env->player.x--;
		env->player.looking_left = 1;
	}
	if (ch == 'd' || ch == 'S')
	{
		if (!ft_strchr("1", env->map[env->player.y][env->player.x + 1]))
			env->player.x++;
		env->player.looking_left = 0;
	}
}

static void check_ennemy(t_env *env, t_coords player)
{
	int	i;

	i = 0;
	while (i < env->nb_pterras)
	{
		if (player.x == env->pteras[i].x && player.y == env->pteras[i].y)
			exit_game(env, 0);
		i++;
	}
}

void	move(char ch, t_env *env)
{
	int	old_x;
	int	old_y;

	old_y = env->player.y;
	old_x = env->player.x;
	update_coordinates(ch, env);
	env->count++;
	update_count(env);
	if (env->map[env->player.y][env->player.x] == 'C')
	{
		env->map[env->player.y][env->player.x] = '0';
		env->score++;
	}
	if (env->map[env->player.y][env->player.x] == 'E')
		if (env->eggs == env->score)
			exit_game(env, 1);
	print_score(env);
	check_ennemy(env, env->player);
	update_map(env, old_x, old_y);
	update_map(env, env->player.x, env->player.y);
}
