/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:21 by enzo              #+#    #+#             */
/*   Updated: 2024/09/21 23:12:44 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	start_fractal(t_fractal *fractal_void, char *name)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE_1)
	{
		while (fractal->y < SIZE_2)
		{
			if (ft_strncmp(name, "julia", 6) == 0)
				julia(fractal);
			else if (ft_strncmp(name, "mandel", 7) == 0)
				mandel(fractal);
			else if (ft_strncmp(name, "phoenix", 8) == 0)
				phoenix(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
}
