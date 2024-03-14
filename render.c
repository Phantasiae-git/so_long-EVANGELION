/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 06:57:37 by rfontes-          #+#    #+#             */
/*   Updated: 2024/03/14 19:07:17 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(void)
{
	int	a;
	int i;
	char *s1;
	char *s2;
	char *s3;

	data()->image = malloc(7 * sizeof(void *));
	if (!data()->image)
		return ;
	s1=ft_strjoin("img/lvl", ft_itoa(data()->lvl));
	s2=ft_strjoin(s1, "/floor.xpm");
	(data()->image[0]) = mlx_xpm_file_to_image((data()->mlx), s2,
			&a, &a);
	s2=ft_strjoin(s1, "/enemy.xpm");
	data()->enemy=malloc(sizeof(t_img));
	(data()->image[1]) = mlx_xpm_file_to_image(data()->mlx, s2, &(data()->enemy->width), \
												&(data()->enemy->height));
	data()->enemy->img=data()->image[1];
	data()->enemy->addr = mlx_get_data_addr(data()->enemy->img, &(data()->enemy->bits_per_pixel), &(data()->enemy->sizeline), &(data()->enemy->endian));
	s2=ft_strjoin(s1, "/exit.xpm");
	(data()->image[3]) = mlx_xpm_file_to_image(data()->mlx, s2, &a, \
												&a);
	s2=ft_strjoin(s1, "/BG.xpm");
	(data()->image[5]) = mlx_xpm_file_to_image(data()->mlx, s2,
			&a, &a);
	s1=ft_strjoin("img/player/", ft_itoa(data()->player));
	s1=ft_strjoin(s1,".xpm");
	(data()->image[2]) = mlx_xpm_file_to_image(data()->mlx, s1,
			&(img()->width), &(img()->height));
	img()->img=data()->image[2];
	img()->addr = mlx_get_data_addr(img()->img, &(img()->bits_per_pixel), &(img()->sizeline), &(img()->endian));
	data()->col = malloc(3 * sizeof(t_img *));
	if(!data()->col)
		return;
	i=-1;
	s3="img/col/Col";
	while(++i<3)
	{
		data()->col[i]=malloc(sizeof(t_img));
		s2=ft_strjoin(s3, ft_itoa(i+1));
		s2=ft_strjoin(s2, ".xpm");
		printf("%s\n", s2);
		data()->col[i]->img=mlx_xpm_file_to_image(data()->mlx, s2, &(data()->col[i]->width), &(data()->col[i]->height));
		data()->col[i]->addr = mlx_get_data_addr(data()->col[i]->img, &(data()->col[i]->bits_per_pixel), &(data()->col[i]->sizeline), &(data()->col[i]->endian));
	}
	data()->coln=0;
}

unsigned int	get_color(t_img *image, int x, int y)
{
	return(*(unsigned int*)(image->addr + (y * image->sizeline + x * (image->bits_per_pixel / 8))));
}

void my_mlx_pixel_put(t_img *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + (y * image->sizeline + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_img_pbp(t_img *image, int x, int y)
{
	int i;
	int j;
	unsigned int color;
	t_img *holder;

	holder=malloc(sizeof(t_img));
	holder->img=mlx_new_image(data()->mlx, image->width, image->height);
	holder->addr = mlx_get_data_addr(holder->img, &holder->bits_per_pixel, &holder->sizeline, &holder->endian);
	i=-1;
	while(++i<image->height)//64
	{
		j=-1;
		while (++j<image->width)//64
		{
			color=get_color(image, j, i);
			if(color!= 0xFF000000)
				my_mlx_pixel_put(holder, (x+j), (y+i), color);//mlx_pixel_put(data()->mlx, data()->win, (x+j), (y+i), color);
		}
	}
	mlx_put_image_to_window(data()->mlx, data()->win, holder->img, x, y);
	mlx_destroy_image(data()->mlx, holder->img);
	free(holder);
}

void collectible(int y, int x)
{
	put_img_pbp(data()->col[data()->coln], x*64, y*64);
}

void	render(int i, int ft)
{
	int	j;
	int a;
	int b;

	if(ft)
		images();
		if(mapdata()->map[(mapdata()->playery+10)/64] \
			[(mapdata()->playerx+10)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery+10)/64][(mapdata()->playerx+10)/64] == 'E' && mapdata()->collectibles))
	{
		(mapdata()->playery)=(mapdata()->playery)-data()->ymove;
		(mapdata()->playerx)=(mapdata()->playerx)-data()->xmove;
		return;
	}
	if(mapdata()->map[(mapdata()->playery+10)/64] \
			[((mapdata()->playerx)+54)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery+10)/64][((mapdata()->playerx)+54)/64] == 'E' && mapdata()->collectibles))
	{
		(mapdata()->playery)=(mapdata()->playery)-data()->ymove;
		(mapdata()->playerx)=(mapdata()->playerx)-data()->xmove;
		return;
	}	
	if(mapdata()->map[(mapdata()->playery+54)/64] \
			[(mapdata()->playerx+10)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery+54)/64] \
			[(mapdata()->playerx+10)/64] == 'E' && mapdata()->collectibles))
	{
		(mapdata()->playery)=(mapdata()->playery)-data()->ymove;
		(mapdata()->playerx)=(mapdata()->playerx)-data()->xmove;
		return;
	}
	if(mapdata()->map[(mapdata()->playery +54)/64] \
			[(mapdata()->playerx+54)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery+54)/64] \
			[(mapdata()->playerx+54)/64] == 'E' && mapdata()->collectibles))
	{
		(mapdata()->playery)=(mapdata()->playery)-data()->ymove;
		(mapdata()->playerx)=(mapdata()->playerx)-data()->xmove;
		return;
	}
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
				collectible(i, j);
		}
	}
	put_img_pbp(img(), mapdata()->playerx, mapdata()->playery);
	put_img_pbp(data()->enemy, data()->xenemy-64, data()->yenemy-128);
	
}
