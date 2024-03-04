/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 06:57:37 by rfontes-          #+#    #+#             */
/*   Updated: 2024/03/04 11:28:31 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(void)
{
	int	a;
	char *s1;
	char *s2;

	data()->image = malloc(5 * sizeof(void *));
	if (!data()->image)
		return ;
	s1=ft_strjoin("img/lvl", ft_itoa(data()->lvl));
	s2=ft_strjoin(s1, "/floor.xpm");
	(data()->image[0]) = mlx_xpm_file_to_image((data()->mlx), s2,
			&a, &a);
	s2=ft_strjoin(s1, "/wall.xpm");
	(data()->image[1]) = mlx_xpm_file_to_image(data()->mlx, s2, &a, \
												&a);
	s2=ft_strjoin(s1, "/exit.xpm");
	(data()->image[3]) = mlx_xpm_file_to_image(data()->mlx, s2, &a, \
												&a);
	s2=ft_strjoin(s1, "/collectible.xpm");
	(data()->image[4]) = mlx_xpm_file_to_image(data()->mlx, \
			s2, &a, &a);
	/*(data()->image[5]) = mlx_xpm_file_to_image(data()->mlx, \
			"img/enemy.xpm", &a, &a);*/
	s1=ft_strjoin("img/player/", ft_itoa(data()->player));
	s1=ft_strjoin(s1,".xpm");
	(data()->image[2]) = mlx_xpm_file_to_image(data()->mlx, s1,
			&a, &a);
}

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
