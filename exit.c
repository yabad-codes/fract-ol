/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:14:10 by yabad             #+#    #+#             */
/*   Updated: 2023/01/11 23:42:23 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	safe_exit(t_data *e)
{
	if (e->img.img)
		mlx_destroy_image(e->mlx, e->img.img);
	if (e->win)
		mlx_destroy_window(e->mlx, e->win);
	if (e->mlx)
		free(e->mlx);
	free(e);
	exit(EXIT_SUCCESS);
}

void	help(void)
{
	ft_putstr_fd("\033[1;37m", 1);
	ft_putstr_fd("\t\t\t┬ ┬┌─┐┌┐ ┌─┐┌┬┐  ┌─┐┬─┐┌─┐┌─┐┌┬┐┌─┐┬  \n", 1);
	ft_putstr_fd("\t\t\t└┬┘├─┤├┴┐├─┤ ││  ├┤ ├┬┘├─┤│   │ │ ││  \n", 1);
	ft_putstr_fd("\t\t\t ┴ ┴ ┴└─┘┴ ┴─┴┘  └  ┴└─┴ ┴└─┘ ┴ └─┘┴─┘\n", 1);
	ft_putstr_fd("\t\t\t--------------------------------------\n\n", 1);
	ft_putstr_fd("\t\033[1;31m*----------*\n", 1);
	ft_putstr_fd("\t\033[1;31m|  Syntax  | \t\033[0;37m: ./fractol\
	\033[1;33mFRACTAL_TYPE JULIA_X JULIA_Y\n", 1);
	ft_putstr_fd("\t\033[1;31m*----------*\n\n", 1);
	ft_putstr_fd("\t\t\033[1;33mFRACTAL_TYPE \t: \t", 1);
	ft_putstr_fd("\033[1;32m(\033[1;35m1\033[1;32m) Mande", 1);
	ft_putstr_fd("lbrot, (\033[1;35m2\033[1;32m) ", 1);
	ft_putstr_fd("Julia, (\033[1;35m3\033[1;32m) Bonus\n", 1);
	ft_putstr_fd("\t\t\033[1;33mJULIA_X \t: \
	\033[1;32mP(\033[1;35mX\033[1;32m, Y)\n", 1);
	ft_putstr_fd("\t\t\033[1;33mJULIA_Y \t: \
	\033[1;32mP(X, \033[1;35mY\033[1;32m)\n", 1);
	exit(-1);
}
