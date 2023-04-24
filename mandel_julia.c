/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:31:01 by yabad             #+#    #+#             */
/*   Updated: 2023/01/10 10:43:52 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	if_point_belongs(t_data *e)
{
	int		iter;
	double	a;
	double	b;
	double	tmp;

	a = e->plan.px;
	b = e->plan.py;
	if (e->args.fractype == 2)
	{
		e->plan.px = 0;
		e->plan.py = 0;
	}
	iter = 1;
	while (++iter < e->plan.max_iter)
	{
		tmp = a;
		a = a * a - b * b + e->plan.px + e->args.j1;
		b = 2 * tmp * b + e->plan.py + e->args.j2;
		if (fabs(a * a + b * b) > 4)
			break ;
	}
	e->plan.iter = iter;
}
