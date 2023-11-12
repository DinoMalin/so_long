/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:56:49 by jcario            #+#    #+#             */
/*   Updated: 2023/11/10 07:14:02 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copy(char **map)
{
	char	**result;
	int		len;
	int		i;

	i = 0;
	len = len_double_dim(map);
	result = malloc((len + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[len] = NULL;
	while (i < len)
	{
		result[i] = ft_strdup(map[i]);
		if (!result[i])
		{
			while (i > 0)
				free(result[i--]);
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}

void	path(int x, int y, char **map)
{
	if (map[y][x] == '0')
		map[y][x] = 2;
	else if (map[y][x] == 'C')
		map[y][x] = 3;
	else if (map[y][x] == 'E')
		map[y][x] = 4;
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
		path(x + 1, y, map);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
		path(x - 1, y, map);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
		path(x, y + 1, map);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
		path(x, y - 1, map);
}

int	is_resolvable(int x, int y, char **map_copy)
{
	int	i;
	int	is_resolvable;

	i = 0;
	is_resolvable = 0;
	if (map_copy[y][x + 1] == 2)
		is_resolvable = 1;
	if (map_copy[y][x - 1] == 2)
		is_resolvable = 1;
	if (map_copy[y + 1][x] == 2)
		is_resolvable = 1;
	if (map_copy[y - 1][x] == 2)
		is_resolvable = 1;
	return (is_resolvable);
}

int	map_is_resolvable(char **map)
{
	t_coords cos;

	cos.y = 0;
	while (map[cos.y])
	{
		cos.x = 0;
		while (map[cos.y][cos.x])
		{
			if (map[cos.y][cos.x] == 'C' || map[cos.y][cos.x] == 'E')
				return (0);
			cos.x++;
		}
		cos.y++;
	}
	return (1);
}