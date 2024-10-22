/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:25:07 by enzo              #+#    #+#             */
/*   Updated: 2024/10/19 18:55:05 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		show_pixel(fractal, fractal->x, fractal->y, fractal->color * (i
				% 255));
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
		show_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
					% 255)));
}
