/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:57:38 by enzo              #+#    #+#             */
/*   Updated: 2024/10/21 15:44:41 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	write_error_and_exit(void)
{
	ft_putendl_fd("-----------------------------------------", 1);
	ft_putendl_fd("\x1B[31mError:\x1B[37m", 1);
	ft_putendl_fd("Select a fractal: ./fractol <fractal>", 1);
	ft_putendl_fd("fractals: julia, mandel, phoenix, animate_julia", 1);
	ft_putendl_fd("julia and phoenix need two floats as parameters.", 1);
	ft_putendl_fd("example: ./fractol julia 0.355 0.355", 1);
	ft_putendl_fd("\t ./fractol_bonus phoenix 0.56667 -0.5", 1);
	exit(1);
}

void	fractal_name(t_fractal *fractal, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal->name = "julia";
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else if (ft_strncmp(argv[1], "phoenix", 8) == 0)
	{
		fractal->name = "phoenix";
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else if (ft_strncmp(argv[1], "animate_julia", 14) == 0)
	{
		fractal->name = "julia";
		fractal->animate = true;
		fractal->x_tmp = ft_atof(argv[2]);
		fractal->y_tmp = ft_atof(argv[3]);
		fractal->cx = (ft_atof(argv[2]) - 0);
		fractal->cy = (ft_atof(argv[3]) - 0);
	}
	else
		fractal->name = "mandel";
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2 || !parsing(argc, argv))
		write_error_and_exit();
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	init_fractal(fractal);
	fractal_name(fractal, argv);
	init_mlx(fractal);
	if (!fractal->mlx)
		return (1);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_loop_hook(fractal->mlx, loop_hook, fractal);
	mlx_hook(fractal->window, 17, 0, mouse_hook, fractal);
	mlx_hook(fractal->window, 2, 1L << 0, key_press, fractal);
	mlx_hook(fractal->window, 3, 1L << 1, key_release, fractal);
	mlx_hook(fractal->window, 17, 1L << 17, exit_fractal, fractal);
	start_fractal(fractal, fractal->name);
	mlx_loop(fractal->mlx);
}
