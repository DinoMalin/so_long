/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:00:19 by jcario            #+#    #+#             */
/*   Updated: 2023/11/12 23:26:20 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include "libft.h"
#include <fcntl.h>

#define ESCAPE 65307
#define COUNT_COLOR 0x000000

#define RED "\033[31m"
#define WHITE "\033[37m"
#define GREEN "\033[32m"

typedef struct s_coordinates {
	int x;
	int y;
	int	looking_left;
} t_coords;

typedef struct s_sprites {
	void	*tile;
	void	*water[4];
	void	*egg[4];
	void	*portal[6];
	void	*dino_left[3];
	void	*dino_right[3];
	void	*ptera_right[3];
	void	*ptera_left[3];
	int		ptera_index;
	int		dino_index;
	int		egg_index;
	int		water_index;
	int		portal_index;
} t_sprites;

typedef struct s_env {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		**map;
	int			count;
	int			score;
	int			eggs;
	int			nb_pterras;
	t_coords	player;
	t_coords	*pteras;
	t_sprites	sprites;
} t_env;


char		**get_map(char *file_name);
void		create_map(t_env *env);
int			len_double_dim(char **arr);
int			map_is_valid(t_env *env);
void		move(char ch, t_env *env);
void		get_coords(t_coords *player, char **map);
int			get_nb_eggs(char **map);
void		print_score(t_env *env);
void		exit_game(t_env *env, int win);
void		update_map(t_env *env, int x, int y);
char		*image(t_env *env, int x, int y);
void		path(int x, int y, char **map);
void		free_map(char **map);
void		init_env(t_env *env);
int			map_is_resolvable(int x, int y, char **map);
void		error(char *str, t_env *env);

void		init_dino(t_env *env);
void		init_eggs(t_env *env);
void		init_portal(t_env *env);
void		init_water(t_env *env);
void		init_ptera(t_env *env);

void		*get_image(t_env *env, char *img);
void		update_count(t_env *env);
int			loop(t_env *env);

void	init_pteras_cos(t_env *env);
void	update_pteras(t_env *env, t_coords player);

void	dialogue();

#endif
