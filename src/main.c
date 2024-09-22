/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:57:38 by enzo              #+#    #+#             */
/*   Updated: 2024/09/21 23:19:54 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	write_error_and_exit(void)
{
	ft_putendl_fd("-----------------------------------------", 1);
	ft_putendl_fd("\x1B[31mError:\x1B[37m", 1);
	ft_putendl_fd("Select a fractal: ./fractol <fractal>", 1);
	ft_putendl_fd("fractals: julia, mandel", 1);
	ft_putendl_fd("julia needs two floats as parameters.", 1);
	ft_putendl_fd("example: ./fractol julia 0.355 0.355", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2 || !parsing(argc, argv))
		write_error_and_exit();
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal->name = "julia";
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else
		fractal->name = "mandel";
	init_mlx(fractal);
	mlx_hook(fractal->window, 17, 0, mouse_hook, fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	start_fractal(fractal, fractal->name);
	mlx_loop(fractal);
}
