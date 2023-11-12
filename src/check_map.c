/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:22:05 by jcario            #+#    #+#             */
/*   Updated: 2023/11/10 16:26:02 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rect(char **map)
{
	int	y;
	int len;

	y = 1;
	len = ft_strlen(map[0]);
	while (map[y])
	{
		if (ft_strlen(map[y]) != len)
			return (0);
		len = ft_strlen(map[y++]);
	}
	return (1);
}

static int	closed(char **map)
{
	t_coords coos;
	int	width;
	int	height;

	coos.y = 0;
	coos.x = 0;
	width = ft_strlen(map[0]);
	height = len_double_dim(map);
	while (map[0][coos.x])
	{
		if (map[0][coos.x] != '1' && map[height - 1][coos.x] != '1')
			return (0);
		coos.x++;
	}
	while (map[coos.y])
	{
		if (map[coos.y][0] != '1' && map[coos.y++][width - 1] != '1')
			return (0);
		coos.y++;
	}
	return (1);
}

static int contains_required(char **map)
{
	t_coords coo;
	int	exit;
	int	collectible;
	int	starting_position;

	coo.y = -1;
	exit = 0;
	collectible = 0;
	starting_position = 0;
	while (map[++coo.y])
	{
		coo.x = -1;
		while (map[coo.y][++coo.x])
		{
			if (map[coo.y][coo.x] == 'E')
				exit++;
			if (map[coo.y][coo.x] == 'C')
				collectible++;
			if (map[coo.y][coo.x] == 'P')
				starting_position++;
		}
	}
	return (exit == 1 && collectible && starting_position == 1);
}

int	map_is_valid(char **map, t_env *env)
{
	t_coords	coos;
	t_coords	starting_pos;

	coos.y = -1;
	while (map[++coos.y])
	{
		coos.x = -1;
		while (map[coos.y][++coos.x])
			if (!ft_strchr("ECP10", map[coos.y][coos.x]))
				error("Unexpected characters in the map", env, map);
	}
	get_coords(&starting_pos, env->map);
	if (starting_pos.x == -1)
		error("The map does not have a starting point", env, map);
	if (!rect(map))
		error("The map is not rectangular", env, map);
	else if (!closed(map))
		error("The map is not surrounded by walls", env, map);
	else if (!contains_required(map))
		error("The map has a problem with the requirement", env, map);
	path(starting_pos.x, starting_pos.y, map);
	if (!map_is_resolvable(map))
		error("There is not any valid path", env, map);
	return (1);
}
