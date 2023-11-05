#include "mlx.h"
#include "mlx_int.h"
#include "../ft_printf/include/ft_printf.h"

typedef struct s_env {
	int	width;
	int	height;
	void *mlx;
    void *win;
} t_env;

typedef struct s_character {
	int x;
	int y;
} t_character;

int close_window(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}

int key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		close_window(env);
	return (0);
}

int main()
{
	t_env env;
	
	ft_printf("test");

	env.mlx = mlx_init();
	env.width = 800;
	env.height = 600;
	env.win = mlx_new_window(env.mlx, env.width, env.height, "dinosaure");

	mlx_key_hook(env.win, key_hook, &env);
	mlx_hook(env.win, 17, 0, close_window, &env);
	mlx_loop(env.mlx);
}