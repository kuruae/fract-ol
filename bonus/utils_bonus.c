/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:51:22 by enzo              #+#    #+#             */
/*   Updated: 2024/09/21 23:13:11 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

bool	is_float_or_int(char *str)
{
	if (ft_is_float(str) || ft_str_isdigit(str))
		return (true);
	return (false);
}

void	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
}

void	show_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	offset;

	offset = (y * fractal->size_line) + (x * (fractal->bits_per_pixel / 8));
	*(unsigned int *)(fractal->img_ptr + offset) = color;
}

void	change_color(t_fractal *fractal)
{
	if (fractal->color == 0xFCBE11)
		fractal->color = 0x8B0000;
	else if (fractal->color == 0x8B0000)
		fractal->color = 0x0bf0fb;
	else if (fractal->color == 0x0bf0fb)
		fractal->color = 0xFF69B4;
	else if (fractal->color == 0xFF69B4)
		fractal->color = 0x008080;
	else if (fractal->color == 0x008080)
		fractal->color = 0x4682B4;
	else if (fractal->color == 0x4682B4)
		fractal->color = 0xFCBE11;
}
