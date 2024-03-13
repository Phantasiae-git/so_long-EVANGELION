/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 06:57:37 by rfontes-          #+#    #+#             */
/*   Updated: 2024/03/13 23:10:29 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(void)
{
	int	a;
	char *s1;
	char *s2;

	data()->image = malloc(6 * sizeof(void *));
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
	s2=ft_strjoin(s1, "/BG.xpm");
	(data()->image[5]) = mlx_xpm_file_to_image(data()->mlx, s2,
			&a, &a);
	/*(data()->image[5]) = mlx_xpm_file_to_image(data()->mlx, \
			"img/enemy.xpm", &a, &a);*/
	s1=ft_strjoin("img/player/", ft_itoa(data()->player));
	s1=ft_strjoin(s1,".xpm");
	(data()->image[2]) = mlx_xpm_file_to_image(data()->mlx, s1,
			&(img()->width), &(img()->height));
	img()->img=data()->image[2];
	img()->addr = mlx_get_data_addr(img()->img, &(img()->bits_per_pixel), &(img()->sizeline), &(img()->endian));
}

unsigned int	get_color(int x, int y)
{
	return(*(unsigned int*)(img()->addr + (y * img()->sizeline + x * (img()->bits_per_pixel / 8))));
}

void	put_player()
{
	int i;
	int j;
	unsigned int color;
	t_img	*holder;

	i=-1;
	
/* 	holder = malloc(sizeof(t_img));
	holder->img=mlx_new_image(data()->mlx, 64, 64);
	holder->addr = mlx_get_data_addr(holder->img, &(holder->bits_per_pixel), &(holder->sizeline), &(holder->endian)); */
	while(++i<img()->height)//64
	{
		j=-1;
		while (++j<img()->width)//64
		{
			color=get_color(j, i);
			if(color!= 0xFF000000)
				mlx_pixel_put(data()->mlx, data()->win, (mapdata()->playerx+j), (mapdata()->playery+i), color);
		}
	}
} 

void	render(int i, int ft)
{
	int	j;
	int a;
	int b;

	if(ft)
		images();
	
	mlx_put_image_to_window(data()->mlx, data()->win, data()->image[5], 0, 0);//bg
/* 	while (++i < mapdata()->height)
	{
		j = -1;
		while (++j < mapdata()->length)
		{
			if (mapdata()->map[i][j] == '0')
			{
				a=-1;
				while(++a<img()->height)//64
				{
					b=-1;
					while (++b<img()->width)//64
					{
						mlx_pixel_put(data()->mlx, data()->win, j*64+b, i*64+a, 0xFFFFFFFF);
					}
				}
			}
			if (mapdata()->map[i][j] == '1');
		}
	} //check 0s and 1s */
	i=-1;
	//mlx_put_image_to_window(data()->mlx, data()->win, data()->image[2], mapdata()->playerx, mapdata()->playery);//player
	while (++i < mapdata()->height)
	{
		j = -1;
		while (++j < mapdata()->length)
		{
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
	put_player();
}
