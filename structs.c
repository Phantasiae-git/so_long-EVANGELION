/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:31:39 by rfontes-          #+#    #+#             */
/*   Updated: 2024/02/22 06:20:03 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_mapdata	*mapdata(void)
{
	static t_mapdata	mapdata;

	return (&mapdata);
}

void	images(void)
{
	int	a;

	data()->image = malloc(5 * sizeof(void *));
	if (!data()->image)
		return ;
	(data()->image[0]) = mlx_xpm_file_to_image((data()->mlx), "img/floor.xpm",
			&a, &a);
	(data()->image[1]) = mlx_xpm_file_to_image(data()->mlx, "img/wall.xpm", &a, \
												&a);
	(data()->image[2]) = mlx_xpm_file_to_image(data()->mlx, "img/player/player.xpm",
			&a, &a);
	(data()->image[3]) = mlx_xpm_file_to_image(data()->mlx, "img/exit.xpm", &a, \
												&a);
	(data()->image[4]) = mlx_xpm_file_to_image(data()->mlx, \
			"img/collectible.xpm", &a, &a);
	/*(data()->image[5]) = mlx_xpm_file_to_image(data()->mlx, \
			"img/collectible.xpm", &a, &a);*/
}

