/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 01:48:18 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/29 02:42:09 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_endraycast(t_env *e)
{
	e->cam.lh = (int)((double)WIN_HH / e->cam.wh);
	draw(e->cam.screen_index, (int)(WIN_H / 2 - e->cam.lh / 2) < 0 ? 0 : \
		(int)(WIN_H / 2 - e->cam.lh / 2), (int)(e->cam.lh / 2 + WIN_H / 2) \
			>= WIN_H ? WIN_H - 1 : (int)(e->cam.lh / 2 + WIN_H / 2), e);
}

void	ft_init_raycast(t_env *e)
{
	ft_bg_set(e->f->data, CYAN, WIN_H * WIN_W / 2);
	ft_bg_set(&(e->f->data[WIN_H * WIN_W / 2]), VERT, WIN_H * WIN_W / 2);
	e->cam.screen_index = -1;
}

void	ft_raycast(t_env *e)
{
	ft_init_raycast(e);
	while (++e->cam.screen_index < WIN_W && !(e->cam.hit = 0))
	{
		ft_init_cam(e);
		if (e->cam.raydirx < 0 && (e->cam.stepx = -1))
			e->cam.sidx = (e->cam.rayposx - (double)e->mapx) * e->cam.ddx;
		else
		{
			e->cam.stepx = 1;
			e->cam.sidx = ((double)e->mapx + 1.0 - e->cam.rayposx) * e->cam.ddx;
		}
		if (e->cam.raydiry < 0 && (e->cam.stepy = -1))
			e->cam.sidy = (e->cam.rayposy - (double)e->mapy) * e->cam.ddy;
		else
		{
			e->cam.stepy = 1;
			e->cam.sidy = ((double)e->mapy + 1.0 - e->cam.rayposy) * e->cam.ddy;
		}
		ft_raycast2(e);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img_ptr, 0, 0);
}

void	ft_bg_set(int *s, int c, size_t n)
{
	while (n)
	{
		s[n] = c;
		--n;
	}
}
