/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:25:07 by enzo              #+#    #+#             */
/*   Updated: 2024/10/21 15:38:35 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mandel(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->cy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		show_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		show_pixel(fractal, fractal->x, fractal->y, get_color(fractal, i));
}

void	julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		show_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		show_pixel(fractal, fractal->x, fractal->y, get_color(fractal, i));
}

static void	phoenix_calc(t_fractal *fractal, double *old_x, double *old_y)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = fractal->zx;
	tmp_y = fractal->zy;
	fractal->zx = tmp_x * tmp_x - tmp_y * tmp_y + fractal->cx + fractal->cy
		* *old_x;
	fractal->zy = 2 * tmp_x * tmp_y + fractal->cy * *old_y;
	*old_x = tmp_x;
	*old_y = tmp_y;
}

void	phoenix(t_fractal *fractal)
{
	int		i;
	double	old_x;
	double	old_y;

	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	old_x = 0;
	old_y = 0;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		phoenix_calc(fractal, &old_x, &old_y);
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 16.0)
			break ;
	}
	if (i == fractal->max_iterations)
		show_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		show_pixel(fractal, fractal->x, fractal->y, get_color(fractal, i));
}

int	get_phx_color(t_fractal *f, int iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == f->max_iterations)
		return (0x000000);
	t = (double)iterations / f->max_iterations;
	t = sqrt(t);
	r = (int)(9 * (1 - t) * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * 255);
	return ((r << 16) | (g << 8) | b);
}
