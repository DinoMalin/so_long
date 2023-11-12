#include "so_long.h"

int close_window(t_env *env)
{
	exit_game(env, 0);
	return (0);
}

int key_hook(int keycode, t_env *env)
{
	if (keycode == ESCAPE)
		close_window(env);
	if (ft_strchr("zqsdRQTSwasd", keycode))
		move(keycode, env);
	return (0);
}

int main(int ac, char **av)
{
	t_env		env;

	if (ac == 1)
		env.map = get_map("maps/dino.ber");
	else
		env.map = get_map(av[1]);
	if (!env.map)
	{
		ft_printf("Error\nMap does not exist!\n");
		exit(0);
	}
	init_env(&env);
	print_score(&env);
	create_map(&env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_hook(env.win, 17, 0, close_window, &env);
	mlx_loop_hook(env.mlx, loop, &env);
	mlx_loop(env.mlx);
}
