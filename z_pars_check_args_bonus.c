/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pars_check_args_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:52:02 by yabad             #+#    #+#             */
/*   Updated: 2023/01/10 15:17:18 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z_ft_fractol_bonus.h"

int	check_julia(int ac, char **av, t_data *e)
{
	double	j1;
	double	j2;

	j1 = str_to_double(av[2]);
	j2 = str_to_double(av[3]);
	if (ac == 4 && j1 >= -2 && j1 <= 2 && j2 >= -2 && j2 <= 2)
	{
		e->args.j1 = j1;
		e->args.j2 = j2;
		return (1);
	}
	return (0);
}

void	check_fract(int ac, char **av, t_data *e)
{
	if (ac == 2 && ft_strncmp(av[1], "1", ft_strlen(av[1])) == 0)
		e->args.fractype = 1;
	else if (ac == 4 && ft_strncmp(av[1], "2", ft_strlen(av[1])) == 0)
	{
		if (check_julia(ac, av, e))
			e->args.fractype = 2;
		else
			help();
	}
	else if (ac == 2 && ft_strncmp(av[1], "3", ft_strlen(av[1])) == 0)
		e->args.fractype = 3;
	else
		help();
}
