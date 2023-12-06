/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:56:49 by jcario            #+#    #+#             */
/*   Updated: 2023/11/14 16:51:36 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path(int x, int y, char **map)
{
	if (ft_strchr("0EC", map[y][x]))
		map[y][x] |= 0b10000000;
	if (ft_strchr("0EC", map[y][x + 1]))
		path(x + 1, y, map);
	if (ft_strchr("0EC", map[y][x - 1]))
		path(x - 1, y, map);
	if (ft_strchr("0EC", map[y + 1][x]))
		path(x, y + 1, map);
	if (ft_strchr("0EC", map[y - 1][x]))
		path(x, y - 1, map);
}

int	check_resolvable(char **map)
{
	t_coords	coos;

	coos.y = 0;
	while (map[coos.y])
	{
		coos.x = 0;
		while (map[coos.y][coos.x])
		{
			if (map[coos.y][coos.x] == 'E' || map[coos.y][coos.x] == 'C')
				return (0);
			coos.x++;
		}
		coos.y++;
	}
	return (1);
}

int	map_is_resolvable(int x, int y, char **map)
{
	t_coords	coos;
	int			is_resolvable;

	path(x, y, map);
	is_resolvable = check_resolvable(map);
	coos.y = 0;
	while (map[coos.y])
	{
		coos.x = 0;
		while (map[coos.y][coos.x])
			map[coos.y][coos.x++] &= 0b01111111;
		coos.y++;
	}
	return (is_resolvable);
}
