/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_input_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:58:36 by yabad             #+#    #+#             */
/*   Updated: 2023/01/10 15:16:57 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_ft_fractol_bonus.h"

void	arrow(int keycode, t_data *e)
{
	double	factor;

	factor = 0.5;
	if (keycode == ON_RIGHT)
	{
		e->plan.miny += factor;
		e->plan.maxy += factor;
	}
	else if (keycode == ON_LEFT)
	{
		e->plan.miny -= factor;
		e->plan.maxy -= factor;
	}
	else if (keycode == ON_UP)
	{
		e->plan.maxx += factor;
		e->plan.minx += factor;
	}
	else if (keycode == ON_DOWN)
	{
		e->plan.maxx -= factor;
		e->plan.minx -= factor;
	}
}

void	key_input(int keycode, t_data *e)
{
	arrow(keycode, e);
	if (keycode == ON_SHIFT)
		e->img.color += 20;
	start_draw(e);
}

int	key_check(int keycode, void *param)
{
	t_data	*e;

	e = param;
	if (keycode == ON_ESC)
		safe_exit(e);
	else
		key_input(keycode, e);
	return (1);
}

int	mouse_check(int keycode, int x, int y, void *param)
{
	t_data	*e;

	e = param;
	if (keycode == ON_MOUSEUP || keycode == ON_MOUSEDOWN)
	{
		zoom(keycode, x, y, e);
		start_draw(e);
	}
	return (0);
}

void	ft_input(t_data *e)
{
	mlx_key_hook(e->win, &key_check, e);
	mlx_mouse_hook(e->win, &mouse_check, e);
	mlx_hook(e->win, ON_DESTROY, 0, safe_exit, e);
}
