/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:57:03 by phanta            #+#    #+#             */
/*   Updated: 2024/02/22 06:44:54 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)//keep argc and argv for secret commands?
{
	int	fd;

	data()->mlx = mlx_init();
	(data()->win) = mlx_new_window((data()->mlx), 1280, 960, "So_long, and it all comes tumbling down");
    render_intro("img/intro/so_long_intro_", 63, 0);
	render_intro("img/intro_loop/intro_part2_", 16, 1);
	data()->mlx = mlx_init();
	(data()->win) = mlx_new_window((data()->mlx), 1280, 960, "So_long, and it all comes tumbling down");
	render_menu();
	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	data()->map = mapdata();
	(mapdata()->map) = getmap((mapdata()->map), fd, 0);
	close(fd);
	if (!mapdata()->map)
		return (0);
	if (!chkvalidmap())
		return (0);
	render(-1);
	mlx_hook(data()->win, 02, 1L << 0, key_hook, data());
	mlx_hook(data()->win, 17, 1L << 2, closewin, data());
	mlx_loop(data()->mlx);
}