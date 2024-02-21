/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 06:57:37 by rfontes-          #+#    #+#             */
/*   Updated: 2024/02/20 17:09:53 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(int i)
{
	int	j;

	images();
	while (++i < mapdata()->height)
	{
		j = -1;
		while (++j < mapdata()->length)
		{
			if (mapdata()->map[i][j] == '0')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[0], j * 64, i * 64);
			if (mapdata()->map[i][j] == '1')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[1], j * 64, i * 64);
			if (mapdata()->map[i][j] == 'P')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[2], j * 64, i * 64);
			if (mapdata()->map[i][j] == 'E')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[3], j * 64, i * 64);
			if (mapdata()->map[i][j] == 'C')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[4], j * 64, i * 64);
			/*if (mapdata()->map[i][j] == 'X')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[5], j * 64, i * 64);*/
		}
	}
}
