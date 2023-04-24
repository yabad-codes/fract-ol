/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_ft_fractol_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:12:52 by yabad             #+#    #+#             */
/*   Updated: 2023/01/11 12:10:27 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_FT_FRACTOL_BONUS_H
# define Z_FT_FRACTOL_BONUS_H
/* PREPROC DEFS */
# define SIDE 1000
/* HEADER FILES DEFINITION */
# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"
/* STRUCT DEFINITION */

enum {
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_ESC = 53,
	ON_DESTROY = 17,
	ON_RIGHT = 126,
	ON_LEFT = 125,
	ON_UP = 123,
	ON_DOWN = 124,
	ON_SHIFT = 258,
};

typedef struct s_args
{
	int				fractype;
	double			j1;
	double			j2;
}	t_args;

typedef struct s_plan
{
	double			maxx;
	double			minx;
	double			maxy;
	double			miny;
	double			x_o;
	double			y_o;
	double			coef;
	double			px;
	double			py;
	int				max_iter;
	int				iter;
}	t_plan;

typedef struct s_img
{
	void			*img;
	char			*d_img;
	int				endian;
	int				bpp;
	int				size_l;
	unsigned int	color;
}	t_img;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_args			args;
	t_plan			plan;
}	t_data;
/* FUNCTION PROTOTYPES */
int				check_julia(int ac, char **av, t_data *e);
void			check_fract(int ac, char **av, t_data *e);

void			start_draw(t_data *e);

double			after_comma(char *str);
double			calc(char *str, int point);
void			vars_initializer(int *i, int *sign, int *point, char *str);
double			str_to_double(char *str);

void			help(void);

void			init(t_data *e);

int				safe_exit(t_data *e);
int				key_check(int keycode, void *param);
int				mouse_check(int keycode, int x, int y, void *param);
void			ft_input(t_data *e);

void			if_point_belongs(t_data *e);
void			fractal_drawer(t_data *e);

void			begin(t_data *e);

void			mapping(int pixx, int pixy, t_data *e);

void			zoom(int keycode, int x, int y, t_data *e);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif