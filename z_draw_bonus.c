/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_draw_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:18:37 by yabad             #+#    #+#             */
/*   Updated: 2023/01/10 15:17:02 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_ft_fractol_bonus.h"

void	burning_ship_check(t_data *e)
{
	int		iter;
	double	a;
	double	b;
	double	tmp;

	a = e->plan.px;
	b = e->plan.py;
	iter = -1;
	while (++iter < e->plan.max_iter)
	{
		tmp = a;
		a = a * a - b * b + e->plan.px;
		b = 2.0 * fabs(tmp * b) + e->plan.py;
		if (fabs(a * a + b * b) > 4)
			break ;
	}
	e->plan.iter = iter;
}

void	fractal_drawer(t_data *e)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIDE)
	{
		x = -1;
		while (++x < SIDE)
		{
			mapping(x, y, e);
			if (e->args.fractype == 3)
				burning_ship_check(e);
			else
				if_point_belongs(e);
			my_mlx_pixel_put(e, x, y, log10(e->plan.iter) * e->img.color);
		}
	}
}

void	start_draw(t_data *e)
{
	fractal_drawer(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
}
