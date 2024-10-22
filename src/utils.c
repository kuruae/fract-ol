/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:51:22 by enzo              #+#    #+#             */
/*   Updated: 2024/10/19 17:42:53 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	is_float_or_int(char *str)
{
	if (ft_is_float(str) || ft_str_isdigit(str))
		return (true);
	return (false);
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

void	show_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	offset;

	offset = (y * fractal->size_line) + (x * (fractal->bits_per_pixel / 8));
	*(unsigned int *)(fractal->img_ptr + offset) = color;
}
