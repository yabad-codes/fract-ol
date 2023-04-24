/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:19:41 by yabad             #+#    #+#             */
/*   Updated: 2023/01/05 17:06:20 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

// void	zoom(int keycode, int x, int y, t_data *e)
// {
// 	double	zoom_factor;
// 	double	x_offset;
// 	double	y_offset;

// 	zoom_factor = 0.1;
// 	x_offset = ((e->plan.maxx - e->plan.minx) / SIDE) * (x - SIDE / 2);
// 	y_offset = ((e->plan.maxx - e->plan.minx) / SIDE) * (y - SIDE / 2);
// 	if (keycode == ON_MOUSEUP)
// 	{
// 		e->plan.maxx -= (e->plan.maxx * zoom_factor) + x_offset;
// 		e->plan.minx -= (e->plan.minx * zoom_factor) + x_offset;
// 		e->plan.maxy -= (e->plan.maxy * zoom_factor) + y_offset;
// 		e->plan.miny -= (e->plan.miny * zoom_factor) + y_offset;
// 	}
// 	else
// 	{
// 		e->plan.maxx += (e->plan.maxx * zoom_factor) + x_offset;
// 		e->plan.minx += (e->plan.minx * zoom_factor) + x_offset;
// 		e->plan.maxy += (e->plan.maxy * zoom_factor) + y_offset;
// 		e->plan.miny += (e->plan.miny * zoom_factor) + y_offset;
// 	}
// }

void	zoom(int keycode, int x, int y, t_data *e)
{
	double	x_offset;
	double	y_offset;

	x_offset = (e->plan.minx + (double)x * (e->plan.maxx - e->plan.minx) / SIDE) * (-1);
	y_offset = e->plan.miny + (double)y * (e->plan.maxx - e->plan.minx) / SIDE;
	if (keycode == ON_MOUSEUP)
	{
		e->plan.minx /= 1.2;
		e->plan.miny /= 1.2;
		e->plan.maxx /= 1.2;
		e->plan.maxy /= 1.2;
		e->plan.x_o -= x_offset * 0.17;
		e->plan.y_o += y_offset * 0.17;
	}
	else
	{
		e->plan.minx *= 1.2;
		e->plan.miny *= 1.2;
		e->plan.maxx *= 1.2;
		e->plan.maxy *= 1.2;
		e->plan.x_o += x_offset * 0.17;
		e->plan.y_o -= y_offset * 0.17;
	}
}
