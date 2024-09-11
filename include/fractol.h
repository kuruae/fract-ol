/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:44:37 by enzo              #+#    #+#             */
/*   Updated: 2024/09/11 10:31:11 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../../circle1/libft/includes/libft.h"
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
}	t_fractal;

#endif