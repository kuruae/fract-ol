/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:39:06 by enzo              #+#    #+#             */
/*   Updated: 2024/09/21 18:05:59 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	loop_hook(t_fractal *fractal)
{
	if (fractal->animate)
	{
		if (fractal->key_pressed && fractal->cy < (fractal->tmp + 20))
		{
			if (fractal->cx > (fractal->tmp - 1))
			{
				fractal->cx += 0.005;
				fractal->cy += 0.005;
			}
			fractal->cx += 0.05;
			fractal->cy += 0.05;
			start_fractal(fractal, fractal->name);
		}
	}
	return (0);
}

int	key_press(int key, t_fractal *fractal)
{
	if (key == Q)
		fractal->key_pressed = 1;
	if (key == ESC)
		exit_fractal(fractal);
	else if (key == R)
		init_fractal(fractal);
	else if (key == UP)
		fractal->offset_y -= 65 / fractal->zoom;
	else if (key == DOWN)
		fractal->offset_y += 65 / fractal->zoom;
	else if (key == RIGHT)
		fractal->offset_x += 65 / fractal->zoom;
	else if (key == LEFT)
		fractal->offset_x -= 65 / fractal->zoom;
	else if (key == C)
		change_color(fractal);
	if (key != Q)
		start_fractal(fractal, fractal->name);
	return (0);
}

int	key_release(int keycode, t_fractal *fractal)
{
	if (keycode == Q)
		fractal->key_pressed = 0;
	return (0);
}

int	mouse_hook(int key, int x, int y, t_fractal *fractal)
{
	if (key == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	if (key == SCROLL_UP)
		zoom(fractal, x, y, 1);
	start_fractal(fractal, fractal->name);
	return (0);
}

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.5;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
}
