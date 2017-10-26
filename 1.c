
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WIN_W 880
# define WIN_H 880

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define ROUGE 0xFF0000;
# define BLEU 0x0000FF;
# define JAUNE 0xFFFF00;
# define MARRON 0x663300;
# define CYAN 0x00CCFF;



typedef struct  s_img
{
    void *img_ptr;
    int *data;
    int size_l;
    int bpp;
    int endian;
}   t_img;

typedef struct	s_env
{
	t_img		*f;
	void		*mlx;
    void		*win;
    int         color;
}				t_env;

int *world = [11111,10001,10001,10001,11111];

void	draw_pixel(t_env *e, int x, int y, int color)
{
	if (x < WIN_H && y < WIN_W && x > 0 && y > 0)
		e->img->data[x + (y * WIN_W)] = color;
}

t_env	*init_env(char *s)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(e->f = init_img(s)))
		return (NULL);
	e->mlx = mlx_init();
    e->f->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
    e->img->data = (int *)mlx_get_data_addr(e->f->img_ptr, &e->f->bpp\
		, &e->f->size_l, &e->f->endian);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "wolf3d");
	e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->size_line\
				, &e->f->endian);

	return (e);
}

int		key_hook(int keycode, t_env *e)
{

	if (keycode == ESC)
		exit(0);
	if (keycode == LEFT)
	{
	
	}
	else if (keycode == RIGHT)
	{
		
	}
	else if (keycode == DOWN)
	{
		
	}
	else if (keycode == UP)
	{
		
	}
		return (0);
}

int		close_prog(t_mlx *mlx)
{
	exit(0);
	free(mlx);
	return(0);
}

int main (int ac, char **av)
{
    
    if (argc != 2 || !argv[1])
	{
		ft_putendl("Error");
		return (0);
	}
	if ((e = init_env(argv[1])) != NULL)
	{
		mlx_hook(e->win, 17, (1L << 17), close_prog, e);
		mlx_hook(e->win, 2, (1L << 0), key_press, e);
		mlx_loop(e->mlx);
		mlx_destroy_window(e->e, e->win);
	}
	return (0);
}
