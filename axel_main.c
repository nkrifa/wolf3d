# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
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

int main(int argc, char **argv)
{
	static double	pos[2] = {2,1};
	double			camX;
	static double	dir[2] = {0,0};
	double			raydir[2];
	static double	plane[2] = {0,0.66};
	double			raypos[2];
	int				x;
	int				map[2];
	char			step[2];
	char			hit;
	char			side;
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
	x = 0;
	while(++x < WIN_W)
	{
		camX = 2 * x / (double)WIN_W - 1;
		*raypos = *pos;
		raypos[1] = pos[1];
		*raydir = *dir + *plane + camX;
		raydir[1] = dir[1] + plane[1] + camX;
		*map = (int)*raypos;
		map[1] = (int)raypos[1];
		*deltadist = sqrtf(1 + (raydir[1] * raydir[1]) / (*raydir * *raydir));
		deltadist[1] = sqrtf(1 + (*raydir * *raydir) / (raydir[1] * raydir[1]));
		hit = 0;
		if (*raydir < 0)
		{
			*step = -1;
			*sidedist = (*raypos - *map) * *deltadist;
		}
		else
		{
			*step = 1;
			*sidedist = (*map + 1.0 - *raypos) * *deltadist;
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
			if(*sidedist < sidedist[1])
			{
				*sidedist += *deltadist;
				*map += (int)*step;
				side = 0;
			}
			else
			{
				sidedist[1] += deltadist[1];
				map[1] += (int)step[1];
				side = 1;
			}
			if (world[*map + (map[1] * 5)] > 0)
				hit = 1;
		}
		if (side)
			perpwalldist = (map[1] - raypos[1] + (1 - step[1]) / 2) / raydir[1];
		else
			perpwalldist = (*map - *raypos + (1 - *step) / 2) / *raydir;
		lineheight = (int)(WIN_H/perpwalldist);
		point_to_point_image(x, (-lineheight/2 + WIN_H/2), (lineheight/2 + WIN_H/2), ROUGE, e->f->data);
		
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
	return(0);
}