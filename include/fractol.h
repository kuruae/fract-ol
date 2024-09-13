/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:44:37 by enzo              #+#    #+#             */
/*   Updated: 2024/09/13 14:53:19 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../../circle1/libft/includes/libft.h"
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian; // ???
	int		color;
	int		max_iterations;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
	char	*name;
}			t_fractal;

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


#endif

/*
c = complex (imaginary numbers)
z = integers set (real numbers)
x = real axis
y = imaginary axis
*/