/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:37:41 by emagnani          #+#    #+#             */
/*   Updated: 2024/10/20 19:38:05 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	update_animation(t_fractal *fractal)
{
	double	dx;
	double	dy;

	if (fractal->animate && fractal->key_pressed)
	{
		dx = fractal->anim_radius * cos(fractal->anim_angle);
		dy = fractal->anim_radius * sin(fractal->anim_angle);
		fractal->cx = fractal->x_tmp + dx;
		fractal->cy = fractal->y_tmp + dy;
		fractal->anim_angle += fractal->anim_speed;
		if (fractal->anim_angle > 2 * M_PI)
			fractal->anim_angle -= 2 * M_PI;
		fractal->color_shift += 0.01;
		if (fractal->color_shift > 1.0)
			fractal->color_shift -= 1.0;
		start_fractal(fractal, fractal->name);
	}
}

static int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static double	normalize_iterations(int iterations, int max_iterations,
				double color_shift)
{
	double	t;

	t = (double)iterations / max_iterations + color_shift;
	return (fmod(t, 1.0));
}

int	get_color(t_fractal *fractal, int iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == fractal->max_iterations)
		return (0x000000);
	t = normalize_iterations(iterations, fractal->max_iterations,
			fractal->color_shift);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (create_rgb(r, g, b));
}

int	loop_hook(t_fractal *fractal)
{
	update_animation(fractal);
	return (0);
}
