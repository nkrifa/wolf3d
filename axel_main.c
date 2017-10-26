# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define WIN_W 880
# define WIN_H 880

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define ROUGE 0xFF0000
# define BLEU 0x0000FF
# define JAUNE 0xFFFF00
# define MARRON 0x663300
# define CYAN 0x00CCFF



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

char world[25] = "1111110001100011000111111";

void	point_to_point_image(int x, int start, int end, int color, int *scene)
{
//printf(" %d , %d\n", start, end);
	while (start <= end)
	{
		scene[x + (start * WIN_W)] = color;
		++start;
	}
}

t_env	*init_env(char *s)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(e->f = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	e->mlx = mlx_init();
    e->f->img_ptr = mlx_new_image(e->mlx, WIN_W, WIN_H);
    e->f->data = (int *)mlx_get_data_addr(e->f->img_ptr, &e->f->bpp\
		, &e->f->size_l, &e->f->endian);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "wolf3d");
	/*e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->size_line\
				, &e->f->endian);*/

	return (e);
}

int		key_hook(int keycode, t_env *e)
{

	if (keycode == ESC)
		exit(0);
	return (0);
}

int		close_prog(t_env *e)
{
	exit(0);
	free(e);
	return(0);
}

int main(int argc, char **argv)
{
	static double	pos[2] = {2.0,2.0};
	double			camX;
	static double	dir[2] = {0.0,-1.0};
	double			raydir[2];
	static double	plane[2] = {0.0,0.66};
	double			raypos[2];
	int				x;
	int				map[2];
	int				step[2];
	int				hit;
	int				side;
	double			sidedist[2];
	double			deltadist[2];
	double			perpwalldist;
	int				lineheight;
	t_env			*e;

	if ((e = init_env(argv[1])) != NULL)
	{
		//mlx_hook(e->win, 17, (1L << 17), close_prog, e);
		//mlx_hook(e->win, 2, (1L << 0), key_press, e);
	}
	x = -1;
	while(++x < WIN_W)
	{
		camX = (2 * x / (double)WIN_W) - 1;
		raypos[0] = pos[0];
		raypos[1] = pos[1];
		raydir[0] = dir[0] + plane[0] + camX;
		raydir[1] = dir[1] + plane[1] + camX;
		map[0] = (int)raypos[0];
		map[1] = (int)raypos[1];
		deltadist[0] = sqrtf(1.0 + (raydir[1] * raydir[1]) / (raydir[0] * raydir[0]));
		deltadist[1] = sqrtf(1.0 + (raydir[0] * raydir[0]) / (raydir[1] * raydir[1]));
		hit = 0;		
		if (raydir[0] < 0)
		{
			step[0] = -1;
			sidedist[0] = (raypos[0] - map[0]) * deltadist[0];
		}
		else
		{
			step[0] = 1;
			sidedist[0] = (map[0] + 1.0 - raypos[0]) * deltadist[0];
		}
		if (raydir[1] < 0)
		{
			step[1] = -1;
			sidedist[1] = (raypos[1] - map[1]) * deltadist[1];
		}
		else
		{
			step[1] = -1;
			sidedist[1] = (map[1] + 1.0 - raypos[1]) * deltadist[1];
		}
		while (hit == 0) /*wall hit ? */
		{
			if(sidedist[0] < sidedist[1])
			{
				sidedist[0] += deltadist[0];
				map[0] += step[0];
				side = 0;
			}
			else
			{
				sidedist[1] += deltadist[1];
				map[1] += step[1];
				side = 1;
			}
			printf("%c\n", world[map[0] + (map[1] * 5)]);
			if (world[map[0] + (map[1] * 5)] != '0')
				hit = 1;
		}
		if (side)
		{
			perpwalldist = ((double)map[1] - raypos[1] + (1 - (double)step[1]) / 2) / raydir[1];
		}
		else
		{
			perpwalldist = ((double)map[0] - raypos[0] + (1 - (double)step[0]) / 2) / raydir[0];
		}
		lineheight = (int)((double)WIN_H/perpwalldist);
		
		point_to_point_image(x, (int)(WIN_H/2 - lineheight/2) < 0 ? 0 : (int)(WIN_H/2 - lineheight/2), (int)(lineheight/2 + WIN_H/2), ROUGE, e->f->data);
		
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img_ptr, 0, 0);
	mlx_hook(e->win, 17, (1L << 17), close_prog, e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
	return(0);
}