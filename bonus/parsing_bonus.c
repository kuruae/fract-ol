/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:09:35 by enzo              #+#    #+#             */
/*   Updated: 2024/09/21 15:30:01 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

bool	parsing(int argc, char **argv)
{
	bool	valid;

	valid = false;
	if (ft_strncmp(argv[1], "mandel", 7) == 0 && argc == 2)
		valid = true;
	else if (ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
	{
		if (is_float_or_int(argv[2]) && is_float_or_int(argv[3]))
			valid = true;
	}
	else if (ft_strncmp(argv[1], "animate_julia", 14) == 0 && argc == 4)
	{
		if (is_float_or_int(argv[2]) && is_float_or_int(argv[3]))
			valid = true;
	}
	else if (ft_strncmp(argv[1], "phoenix", 8) == 0 && argc == 4)
	{
		if (is_float_or_int(argv[2]) && is_float_or_int(argv[3]))
			valid = true;
	}
	return (valid);
}
