/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:59:59 by jcario            #+#    #+#             */
/*   Updated: 2023/11/10 06:13:58 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**join_double_dim(char **s1, char *s2)
{
	char	**result;
	int		len;
	int		i;

	len = len_double_dim(s1);
	i = 0;
	result = malloc((len + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = ft_strdup(s1[i]);
		free(s1[i]);
		i++;
	}
	result[i++] = ft_strdup(s2);
	result[i] = NULL;
	free(s1);
	return (result);
}

int	len_double_dim(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

char	**get_map(char *file_name)
{
	int		file;
	char	**result;
	char 	*line;

	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (NULL);
	result = malloc(sizeof(char *));
	result[0] = NULL;
	line = get_next_line(file);
	while (line)
	{
		line = ft_strtrim(line, "\n");
		result = join_double_dim(result, line);
		free(line);
		line = get_next_line(file);
	}
	close(file);
	free(line);
	return (result);
}


void	get_coords(t_coords *player, char **map)
{
	t_coords	coo;

	coo.y = 0;
	while (map[coo.y])
	{
		coo.x = 0;
		while (map[coo.y][coo.x])
		{
			if (map[coo.y][coo.x] == 'P')
			{
				player->x = coo.x;
				player->y = coo.y;
				return ;
			}
			coo.x++;
		}
		coo.y++;
	}
	player->x = -1;
	player->y = -1;
}

int	get_nb_eggs(char **map)
{
	int	x;
	int	y;
	int	result;
	
	y = 0;
	result = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				result++;
			x++;
		}
		y++;
	}
	return (result);
}