/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 06:49:39 by yabad             #+#    #+#             */
/*   Updated: 2023/01/05 12:36:05 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

double	after_comma(char *str)
{
	int	i;
	int	res;

	i = ft_strlen(str);
	res = 1;
	while (i--)
		res = res * 10;
	return ((double)ft_atoi(str) / (double)res);
}

double	calc(char *str, int point)
{
	char	**tab;
	double	a;
	double	b;
	int		sign;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	if (point == 0)
		return (sign * (double)ft_atoi(str));
	tab = ft_split(str, '.');
	a = ft_atoi(tab[0]);
	b = after_comma(tab[1]);
	return (sign * (a + b));
}

void	vars_initializer(int *i, int *sign, int *point, char *str)
{
	*i = 0;
	*point = 0;
	*sign = 1;
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
}

double	str_to_double(char *str)
{
	int	i;
	int	sign;
	int	point;

	vars_initializer(&i, &sign, &point, str);
	while (str[i])
	{
		if (((str[i] == '.') || ft_isdigit(str[i])) && point < 2)
		{
			if (str[i] == '.')
			{
				if ((str[i + 1] && str[i - 1]) && (ft_isdigit(str[i + 1]) \
				&& ft_isdigit(str[i - 1])))
					point++;
				else
					return (-100);
			}
			i++;
		}
		else
			return (-100);
	}
	return (calc(str, point));
}
