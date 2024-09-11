/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:57:38 by enzo              #+#    #+#             */
/*   Updated: 2024/09/11 11:23:11 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("Error.\nSelect a fractal: ./fractol <fractal>", 1);
		ft_putendl_fd("Fractals: julia, mandel", 1);
		return (0);
	}
	fractal = mlx_init();
	fractal->window = mlx_new_window(fractal, 960, 540, "test");
	mlx_loop(fractal);
}

// void jsp(char *fractal_type)
// {
// 	if (ft_strncmp(fractal_type, "julia", 6) == 0)
// 		blabla_julia();
// 	if (ft_strncmp(fractal_type, "mandel", 7) == 0)
// 		blabla_mandel();
// 	else
// 		ft_putendl_fd("Fractals: julia, mandel", 1);
// }