/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:25:49 by enzo              #+#    #+#             */
/*   Updated: 2024/09/22 19:25:44 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_animation(t_fractal *fractal)
{
	fractal->anim_angle = 0.0;
	fractal->anim_radius = 0.1;
	fractal->anim_speed = 0.02;
	fractal->color_shift = 0.0;
}

void update_animation(t_fractal *fractal)
{
	if (fractal->animate && fractal->key_pressed)
	{
		// Ensure initial parameters are set correctly
		if (fractal->anim_angle == 0.0)
		{
			fractal->x_tmp = fractal->cx;
			fractal->y_tmp = fractal->cy;
		}

		// Circular path for Julia set parameters
		fractal->cx = fractal->x_tmp + fractal->anim_radius * cos(fractal->anim_angle);
		fractal->cy = fractal->y_tmp + fractal->anim_radius * sin(fractal->anim_angle);

		// Update angle for next frame
		fractal->anim_angle += fractal->anim_speed;
		if (fractal->anim_angle > 2 * M_PI)
			fractal->anim_angle -= 2 * M_PI;

		// Shift colors
		fractal->color_shift += 0.01;
		if (fractal->color_shift > 1.0)
			fractal->color_shift -= 1.0;

		start_fractal(fractal, fractal->name);
	}
}

int	get_color(t_fractal *fractal, int iterations)
{
	if (iterations == fractal->max_iterations)
		return (0x000000);  // Black for points in the set

	double t = (double)iterations / fractal->max_iterations + fractal->color_shift;
	t = fmod(t, 1.0);  // Keep t in the range [0, 1)

	// Adjust polynomial coefficients for a wider range of colors
	int r = (int)(9 * (1 - t) * t * t * t * 255);
	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	return	((r << 16) | (g << 8) | b);
}

int	loop_hook(t_fractal *fractal)
{
	update_animation(fractal);
	return (0);
}
