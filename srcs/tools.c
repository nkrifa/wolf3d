/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 01:49:21 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/29 20:14:11 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw(int x, int start, int end, t_env *e)
{
	int color;

	if (e->cam.side)
		color = (e->cam.stepy >= 0 ? ROUGE : BLEU);
	else
		color = (e->cam.stepx >= 0 ? JAUNE : MARRON);
	while (start <= end)
	{
		e->f->data[x + (start * WIN_W)] = color;
		++start;
	}
}

t_env	*init_env(char *s)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		exit(0);
	if (!(e->f = (t_img *)malloc(sizeof(t_img))))
		exit(0);
	e->p.dirx = -1;
	e->p.diry = 0;
	e->p.posx = 2.0;
	e->p.posy = 2.0;
	e->cam.hit = 0;
	e->cam.screen_index = -1;
	e->cam.planex = 0.0;
	e->cam.planey = 0.6;
	e->mlx = mlx_init();
	e->f->img_ptr = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->f->data = (int *)mlx_get_data_addr(e->f->img_ptr, &e->f->bpp\
			, &e->f->size_l, &e->f->endian);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "wolf3d");
	return (e);
}

void	ft_init_cam(t_env *e)
{
	e->cam.camx = (2 * e->cam.screen_index / (double)WIN_W) - 1;
	e->cam.rayposx = e->p.posx;
	e->cam.rayposy = e->p.posy;
	e->cam.raydirx = e->p.dirx + e->cam.planex * e->cam.camx;
	e->cam.raydiry = e->p.diry + e->cam.planey * e->cam.camx;
	e->mapx = (int)e->cam.rayposx;
	e->mapy = (int)e->cam.rayposy;
	e->cam.ddx = sqrtf(1.0 + (e->cam.raydiry * e->cam.raydiry) \
			/ (e->cam.raydirx * e->cam.raydirx));
	e->cam.ddy = sqrtf(1.0 + (e->cam.raydirx * e->cam.raydirx) \
			/ (e->cam.raydiry * e->cam.raydiry));
}

int		close_prog(t_env *e)
{
	exit(0);
	free(e);
	return (0);
}
