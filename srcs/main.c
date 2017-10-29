/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 01:45:48 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/29 02:48:12 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		wm[24][24] = \
{\
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},\
{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},\
{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},\
{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,1,1,1,1,1,1,2,1,1,1,1,1,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},\
{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},\
{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},\
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}\
};

void	ft_raycast2(t_env *e)
{
	while (e->cam.hit == 0)
	{
		if (e->cam.sidx < e->cam.sidy)
		{
			e->cam.sidx += e->cam.ddx;
			e->mapx += e->cam.stepx;
			e->cam.side = 0;
		}
		else
		{
			e->cam.sidy += e->cam.ddy;
			e->mapy += e->cam.stepy;
			e->cam.side = 1;
		}
		if (wm[e->mapx][e->mapy] != 0)
			e->cam.hit = 1;
	}
	if (e->cam.side == 0)
		e->cam.wh = fabs(((double)e->mapx - e->cam.rayposx + \
			(1 - e->cam.stepx) / 2) / e->cam.raydirx);
	else
		e->cam.wh = fabs(((double)e->mapy - e->cam.rayposy + \
			(1 - e->cam.stepy) / 2) / e->cam.raydiry);
	ft_endraycast(e);
}

int		key_hook2(int keycode, t_env *e, double tmp, double temp)
{
	if (keycode == UP)
	{
		if (wm[(int)(e->p.posx + e->p.dirx * 0.51)][(int)(e->p.posy)] == 0)
			e->p.posx += e->p.dirx * 0.5;
		if (wm[(int)(e->p.posx)][(int)(e->p.posy + e->p.diry * 0.51)] == 0)
			e->p.posy += e->p.diry * 0.5;
	}
	if (keycode == DOWN)
	{
		if (wm[(int)(e->p.posx - e->p.dirx * 0.5)][(int)(e->p.posy)] == 0)
			e->p.posx -= e->p.dirx * 0.5;
		if (wm[(int)(e->p.posx)][(int)(e->p.posy - e->p.diry * 0.5)] == 0)
			e->p.posy -= e->p.diry * 0.5;
	}
	if (keycode == LEFT)
	{
		e->p.dirx = e->p.dirx * cos(0.05) - e->p.diry * sin(0.05);
		e->p.diry = temp * sin(0.05) + e->p.diry * cos(0.05);
		e->cam.planex = e->cam.planex * cos(0.05) - e->cam.planey * sin(0.05);
		e->cam.planey = tmp * sin(0.05) + e->cam.planey * cos(0.05);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	double temp;
	double tmp;

	if (keycode == ESC)
		exit(0);
	temp = e->p.dirx;
	tmp = e->cam.planex;
	if (keycode == RIGHT)
	{
		e->p.dirx = e->p.dirx * cos(-0.05) - e->p.diry * sin(-0.05);
		e->p.diry = temp * sin(-0.05) + e->p.diry * cos(-0.05);
		e->cam.planex = e->cam.planex * cos(-0.05) - e->cam.planey * sin(-0.05);
		e->cam.planey = tmp * sin(-0.05) + e->cam.planey * cos(-0.05);
	}
	key_hook2(keycode, e, tmp, temp);
	ft_raycast(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env			*e;

	e = init_env(argv[1]);
	ft_raycast(e);
	mlx_hook(e->win, 17, (1L << 17), close_prog, e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
	return (0);
}
