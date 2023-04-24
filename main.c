/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:42:39 by yabad             #+#    #+#             */
/*   Updated: 2023/01/11 11:55:38 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	begin(t_data *e)
{
	init(e);
	start_draw(e);
	ft_input(e);
	mlx_loop(e->mlx);
}

int	main(int ac, char **av)
{
	t_data	*e;

	e = (t_data *)malloc(sizeof(t_data));
	if (!e)
		return (0);
	check_fract(ac, av, e);
	begin(e);
	return (0);
}
