/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:58:36 by yabad             #+#    #+#             */
/*   Updated: 2023/01/10 12:34:42 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	key_check(int keycode, void *param)
{
	t_data	*e;

	e = param;
	if (keycode == ON_ESC)
		safe_exit(e);
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
