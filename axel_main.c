# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define WIN_W 880
# define WIN_H 880
# define WIN_HH 2000
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


typedef struct s_cam
{
	double 	rayposx;
	double 	rayposy;
	double 	raydirx;
	double 	raydiry;
	int		screen_index;
	int		side;
	double	sidedistx;
	double	sidedisty;
	double planex;
	double planey;
	double walldist;
	int 	stepx;
	int		stepy;
	double	deltadistx;
	double	deltadisty;
	int		hit;
}	t_cam;

typedef struct s_player
{
	double dirx;
	double diry;
	double posx;
	double posy;


}			t_player;

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
	t_cam		cam;
	t_img		*f;
	t_player    p;
	void		*mlx;
	void		*win;
	double		*pos;
	int         color;
	int			mapx;
	int			mapy;
}				t_env;

/*char world[10] =  "111111111\
1000000001\
1000100001\
1000000001\
1010000001\
1010000001\
1000000001\
1000110001\
1000000001\
1111111111";*/

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/*1111111111
  1000000001
  1000000001
  1000000001
  1000000001
  1000000001
  1111111111";*/

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
	//if (!(e->p = (t_player)malloc(sizeof(t_player))))
	//	return (NULL);
	e->p.dirx = -1;
	e->p.diry = 0;
	e->p.posx = 12.0;
	e->p.posy = 12.0;
	e->cam.hit = 0;
	e->cam.planex = 0.0;
	e->cam.planey = 0.6;
	e->mlx = mlx_init();
    e->f->img_ptr = mlx_new_image(e->mlx, WIN_W, WIN_H);
    e->f->data = (int *)mlx_get_data_addr(e->f->img_ptr, &e->f->bpp\
		, &e->f->size_l, &e->f->endian);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "wolf3d");
	/*e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->size_line\
				, &e->f->endian);*/

	return (e);
}


void	ft_raycast(t_env *e)
{
	//static double	pos[2] = {2.0,2.0};
	double			camX;
	//static double	dir[2] = {0.15,-1.0};
//	double			raydir[2];
//	static double	plane[2] = {0.0,0.66};
//	double			raypos[2];
//	int				x;
//	int				map[2];
//	int				step[2];
	int				hit;
	//int				side;
	double			sidedist[2];
//	double			deltadist[2];
	double			perpwalldist;
	int				lineheight;
	
	ft_bzero(e->f->data, 4 * WIN_H * WIN_W);
	e->cam.screen_index = -1;
	while(++e->cam.screen_index < WIN_W)
	{
		camX = (2 * e->cam.screen_index / (double)WIN_W) - 1;
		e->cam.rayposx = e->p.posx;
		e->cam.rayposy = e->p.posy;
		e->cam.raydirx = e->p.dirx + e->cam.planex * camX;
		e->cam.raydiry = e->p.diry + e->cam.planey * camX;
		e->mapx = (int)e->cam.rayposx;
		e->mapy = (int)e->cam.rayposy;
		e->cam.deltadistx = sqrtf(1.0 + (e->cam.raydiry * e->cam.raydiry) / (e->cam.raydirx * e->cam.raydirx));
		e->cam.deltadisty = sqrtf(1.0 + (e->cam.raydirx * e->cam.raydirx) / (e->cam.raydiry * e->cam.raydiry));
		hit = 0;		
		if (e->cam.raydirx < 0)
		{
			e->cam.stepx = -1;
			e->cam.sidedistx = (e->cam.rayposx - (double)e->mapx) * e->cam.deltadistx;
		}
		else
		{
			e->cam.stepx = 1;
			e->cam.sidedistx = ((double)e->mapx + 1.0 - e->cam.rayposx) * e->cam.deltadistx;
		}
		if (e->cam.raydiry < 0)
		{
			e->cam.stepy = -1;
			e->cam.sidedisty = (e->cam.rayposy - (double)e->mapy) * e->cam.deltadisty;
		}
		else
		{
			e->cam.stepy = 1;
			e->cam.sidedisty = ((double)e->mapy + 1.0 - e->cam.rayposy) * e->cam.deltadisty;
		}
		while (hit == 0) /*wall hit ? */
		{
			//printf("%d, %d\n",e->mapx,e->mapy);
			if(e->cam.sidedistx < e->cam.sidedisty)
			{
				e->cam.sidedistx += e->cam.deltadistx;
				e->mapx += e->cam.stepx;
				e->cam.side = 0;
			}
			else
			{
				e->cam.sidedisty += e->cam.deltadisty;
				e->mapy += e->cam.stepy;
				e->cam.side = 1;
			}
			//printf("%c\n", world[e->mapx + (e->mapy * 5)]);
			if (worldMap[e->mapx][e->mapy] != 0)//[e->mapx + (e->mapy * 10)] == '1')
			{
				hit = 1;
			}
		}
		if (e->cam.side == 0)
		{
			perpwalldist = fabs(((double)e->mapx - e->cam.rayposx + (1 - e->cam.stepx) / 2) / e->cam.raydirx);
		}
		else
		{
			perpwalldist = fabs(((double)e->mapy - e->cam.rayposy + (1 - e->cam.stepy) / 2) / e->cam.raydiry);
		}
		lineheight = (int)((double)WIN_HH/perpwalldist);
		
		point_to_point_image(e->cam.screen_index, (int)(WIN_H/2 - lineheight/2) < 0 ? 0 : (int)(WIN_H/2 - lineheight/2), (int)(lineheight/2 + WIN_H/2) >= WIN_H ? WIN_H - 1 : (int)(lineheight/2 + WIN_H/2),e->cam.side ? (e->cam.stepy >= 0 ? ROUGE : BLEU) : (e->cam.stepx >= 0 ? JAUNE : MARRON), e->f->data);
		
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img_ptr, 0, 0);
}
int		key_hook(int keycode, t_env *e)
{
	double temp;
	double tmp;

	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT)
	{
		/*temp = e->p.dirx;
		e->p.dirx = e->p.dirx * cos(-0.01*0.0174533) - e->p.diry + sin(-0.01*0.0174533);
		e->p.diry = temp * sin(-0.01*0.0174533) + e->p.diry + cos(-0.01)*0.0174533;
		temp = e->p.planex;
		e->p.planex = e->p.planex * cos(-0.01*0.0174533) - e->p.planey + sin(-0.01*0.0174533);
		e->p.planey = temp * sin(-0.01*0.0174533) + e->p.planey + cos(-0.01*0.0174533);
		ft_raycast(e);
		double oldDirX = e->p.dirx;
		rot++;
		e->p.dirx = cos(rot*0.0174533);// e->p.dirx * cos(-0.01) - e->p.diry * sin(-0.01);
		e->p.diry = sin(rot*0.0174533);//oldDirX * sin(-0.01) + e->p.diry * cos(-0.01);
		double oldPlaneX = e->p.planex;
		e->p.planex = e->p.planex * cos(-0.01) - e->p.planey * sin(-0.01);
		e->p.planey = oldPlaneX * sin(-0.01) + e->p.planey * cos(-0.01);*/
		e->p.dirx= e->p.dirx * cos(-0.05) - e->p.diry * sin(-0.05);
		temp = e->p.dirx;
		tmp = e->cam.planex;
		e->p.diry= temp * sin(-0.05) + e->p.diry * cos(-0.05);
		e->cam.planex = e->cam.planex * cos(-0.05) - e->cam.planey * sin(-0.05);
		e->cam.planey = tmp * sin(-0.05) + e->cam.planey * cos(-0.05);
	}
	if (keycode == LEFT)
	{	
		temp = e->p.dirx;
		tmp = e->cam.planex;
		e->p.dirx = e->p.dirx * cos(0.05) - e->p.diry * sin(0.05);
		e->p.diry = temp * sin(0.05) + e->p.diry * cos(0.05);
		e->cam.planex = e->cam.planex * cos(0.05) - e->cam.planey * sin(0.05);
		e->cam.planey = tmp * sin(0.05) + e->cam.planey * cos(0.05);
	}
	if (keycode == UP)
	{	
		if(worldMap[(int)(e->p.posx + e->p.dirx * 1)][(int)(e->p.posy)] == 0)
			e->p.posx += e->p.dirx * 1;
		if(worldMap[(int)(e->p.posx)][(int)(e->p.posy + e->p.dirx * 1)] == 0)
			e->p.posy += e->p.diry * 1;
		//ft_raycast(e);
	
	}
	if (keycode == DOWN)
	{	
		if(worldMap[(int)(e->p.posx - e->p.dirx * 1)][(int)(e->p.posy)] == 0)
			e->p.posx -= e->p.dirx * 1;
		if(worldMap[(int)(e->p.posx)][(int)(e->p.posy - e->p.dirx * 1)] == 0)
			e->p.posy -= e->p.diry * 1;

		//e->p.posx -= (e->p.dirx * 0.01);
		//ft_raycast(e);
	
	}
	ft_raycast(e);
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
	t_env			*e;
	
	if ((e = init_env(argv[1])) != NULL)
	{
		//mlx_hook(e->win, 17, (1L << 17), close_prog, e);
		//mlx_hook(e->win, 2, (1L << 0), key_press, e);
	}
	ft_raycast(e);
	mlx_hook(e->win, 17, (1L << 17), close_prog, e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
	return(0);
}