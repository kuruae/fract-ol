/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:40:13 by enzo              #+#    #+#             */
/*   Updated: 2024/10/19 18:49:19 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->offset_x = -1.20;
	fractal->offset_y = -1.20;
	fractal->zoom = 300;
	fractal->color = 0xFCBE11;
	fractal->max_iterations = 80;
}

int	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		return (-1);
	fractal->window = mlx_new_window(fractal->mlx, SIZE_1, SIZE_2, "fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE_1, SIZE_2);
	fractal->img_ptr = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	return (0);
}
