/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:46 by rfontes-          #+#    #+#             */
/*   Updated: 2024/02/29 19:08:16 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move2(int keycode)
{
	mapdata()->map[mapdata()->playery][mapdata()->playerx] = '0';
	mlx_put_image_to_window(data()->mlx, data()->win, data()->image[0], \
			(mapdata()->playerx) * 64, (mapdata()->playery) * 64);
	if (keycode == 'w')
		(mapdata()->playery)--;
	if (keycode == 's')
		(mapdata()->playery)++;
	if (keycode == 'a')
		(mapdata()->playerx)--;
	if (keycode == 'd')
		(mapdata()->playerx)++;
	if (mapdata()->map[mapdata()->playery][mapdata()->playerx] == 'C')
		(mapdata()->collectibles)--;
	if (mapdata()->map[mapdata()->playery][mapdata()->playerx] == 'E'
		&& write(1, "u win\n", 6))
		closewin();
	mapdata()->map[mapdata()->playery][mapdata()->playerx] = 'P';
	mlx_put_image_to_window(data()->mlx, data()->win, data()->image[2], \
			(mapdata()->playerx) * 64, (mapdata()->playery) * 64);
	(data()->moves)++;
}

void	move(int keycode)
{
	if (keycode == 'w' && (mapdata()->map[mapdata()->playery - 1] \
			[mapdata()->playerx] == '1' \
			|| (mapdata()->map[mapdata()->playery \
				- 1][mapdata()->playerx] == 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 's' && (mapdata()->map[mapdata()->playery + 1] \
			[mapdata()->playerx] == '1' \
			|| (mapdata()->map[mapdata()->playery + 1] \
			[mapdata()->playerx] == 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 'a' && (mapdata()->map[mapdata()->playery] \
			[mapdata()->playerx - 1] == '1'
			|| (mapdata()->map[mapdata()->playery][mapdata()->playerx - 1] \
			== 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 'd' && (mapdata()->map[mapdata()->playery] \
			[mapdata()->playerx + 1] == '1' || \
			(mapdata()->map[mapdata()->playery] \
			[mapdata()->playerx + 1] == 'E' && mapdata()->collectibles)))
		return ;
	move2(keycode);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		closewin();
	(void)data;
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		move(keycode);
	return (0);
}

int	megahook(int keycode)
{
	if(data()->state==1)
		(data()->state)=2;
	else if(data()->state==2)
	{
		if(keycode=='s' || keycode== 65364)
		{
			mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[1], 0, 0);
        	data()->flag_menu=0;
		}
		if(keycode=='w' || keycode== 65362)
		{
			mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[0], 0, 0);
        	data()->flag_menu=1;
		}
		if(keycode==65293 || keycode==32)//spacebar + enter
		{
			if(data()->flag_menu==1)
			{
				printf("play!\n");
				data()->state=4;//CHANGE THIS TO 3, just want to test maps for now
				data()->flag_menu=0;
			}
			else
				closewin();
		}	
	}
	else if(data()->state==3)
	{
		if(keycode=='d' || keycode== 65363)
		{
			if(data()->flag_menu<2)
        		data()->flag_menu++;
		}
		if(keycode=='a' || keycode== 65361)
		{
			if(data()->flag_menu>0)
        		data()->flag_menu--;
		}
		//transition animation in video?
		mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[data()->flag_menu], 0, 0);
		if(keycode==65293 || keycode==32)
		{
			data()->state=4;
			data()->player=data()->flag_menu;
		}
	}
	else if(data()->state==4)
		key_hook(keycode, data());
	printf("STATE CHANGE (%i)\n KEYCODE= %i\n", (data()->state), keycode);
}
