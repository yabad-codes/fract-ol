/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:41:46 by yabad             #+#    #+#             */
/*   Updated: 2023/01/12 00:00:29 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	plan_init(t_data *e)
{
	e->plan.max_iter = 120;
	e->plan.minx = -2;
	e->plan.maxx = 4 - fabs(e->plan.minx);
	e->plan.miny = -2;
	e->plan.maxy = 4 - fabs(e->plan.miny);
	e->plan.x_o = 0;
	e->plan.y_o = 0;
	e->img.color = 0xFFF000;
}

void	minilibx_init(t_data *e)
{
	e->mlx = mlx_init();
	if (!e->mlx)
		safe_exit(e);
	e->win = mlx_new_window(e->mlx, SIDE, SIDE, "fract'ol yabad 1337MED");
	e->img.img = mlx_new_image(e->mlx, SIDE, SIDE);
	if (!e->win || !e->img.img)
		safe_exit(e);
	e->img.d_img = mlx_get_data_addr(e->img.img, \
		&e->img.bpp, &e->img.size_l, &e->img.endian);
	if (!(e->mlx && e->win && e->img.img))
		safe_exit(e);
}

void	arguments_init(t_data *e)
{
	if (e->args.fractype == 1)
	{
		e->args.j1 = 0;
		e->args.j2 = 0;
	}
	else if (e->args.fractype == 2)
	{
		e->plan.px = 0;
		e->plan.py = 0;
	}
}

void	init(t_data *e)
{
	minilibx_init(e);
	arguments_init(e);
	plan_init(e);
}
