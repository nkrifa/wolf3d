/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 01:05:27 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/29 17:09:02 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
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
# define VERT 0x00FF00

typedef struct	s_cam
{
	double		wh;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			screen_index;
	int			side;
	double		sidx;
	double		sidy;
	double		planex;
	double		planey;
	double		walldist;
	int			stepx;
	int			stepy;
	double		ddx;
	double		ddy;
	int			hit;
	double		camx;
	int			lh;
	int			*worldmap;
}				t_cam;

typedef struct	s_player
{
	double		dirx;
	double		diry;
	double		posx;
	double		posy;
}				t_player;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_env
{
	t_cam		cam;
	t_img		*f;
	t_player	p;
	void		*mlx;
	void		*win;
	double		*pos;
	int			color;
	int			mapx;
	int			mapy;
}				t_env;

typedef	struct	s_map
{
	unsigned int	col;
	unsigned int	line;
	int				**tab;
}				t_map;

void			ft_bg_set(int *s, int c, size_t n);
void			draw(int x, int start, int end, t_env *e);
t_env			*init_env(char *s);
void			ft_init_cam(t_env *e);
void			ft_endraycast(t_env *e);
void			ft_raycast2(t_env *e);
void			ft_init_raycast(t_env*e);
void			ft_raycast(t_env *e);
void			ft_bg_set(int *s, int c, size_t n);
int				key_hook2(int keycode, t_env *e, double tmp, double temp);
int				key_hook(int keycode, t_env *e);
int				close_prog(t_env *e);

#endif
