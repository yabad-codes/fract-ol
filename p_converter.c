/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:29:09 by yabad             #+#    #+#             */
/*   Updated: 2023/01/05 16:58:21 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	mapping(int pixx, int pixy, t_data *e)
{
	e->plan.coef = (e->plan.maxx - e->plan.minx) / SIDE;
	e->plan.px = e->plan.x_o + (e->plan.minx + (double)pixx * e->plan.coef);
	e->plan.py = e->plan.y_o + (e->plan.miny + (double)pixy * e->plan.coef);
}
