/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:44:37 by enzo              #+#    #+#             */
/*   Updated: 2024/09/19 19:55:07 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE_1 700
# define SIZE_2 700

# include "../../../circle1/libft/includes/libft.h"
# include <math.h>
# include "../mlx/mlx.h"

# ifdef __APPLE__
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define UP 126
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define ESC 53
#  define R 15
#  define Q 12
#  define W 13
# else
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define UP 65362
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define ESC 65307
#  define R 27
#  define Q 113
#  define W 119
# endif

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		color;
	int		max_iterations;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
}			t_fractal;

bool	parsing(int argc, char **argv);
void	fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
bool	is_float_or_int(char *str);
void	exit_fractal(t_fractal *fractal);
int		key_hook(int key, t_fractal *fractal);
int		mouse_hook(int key, int x, int y, t_fractal *fractal);
void	zoom(t_fractal *fractal, int x, int y, int zoom);
void	write_error_and_exit(void);
void	start_fractal(t_fractal *fractal_void, char *name);
void	mandel(t_fractal *fractal);
void	julia(t_fractal *fractal);
void	show_pixel(t_fractal *fractal, int x, int y, int color);

#endif

/*
c = complex (imaginary numbers)
z = integers set (real numbers)
x = real axis
y = imaginary axis
endianness is the order by which bytes are stored in memory
*/