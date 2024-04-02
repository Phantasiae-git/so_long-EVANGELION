/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:46 by rfontes-          #+#    #+#             */
/*   Updated: 2024/03/18 19:19:23 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move2(int keycode)
{
	//mapdata()->map[(mapdata()->playery)/64][(mapdata()->playerx)/64] = '0';
	if (keycode == 'w')
		(mapdata()->playery)=(mapdata()->playery)-SPEED;
	if (keycode == 's')
		(mapdata()->playery)=(mapdata()->playery)+SPEED;
	if (keycode == 'a')
		(mapdata()->playerx)=(mapdata()->playerx)-SPEED;
	if (keycode == 'd')
		(mapdata()->playerx)=(mapdata()->playerx)+SPEED;
	if (mapdata()->map[(mapdata()->playery)/64][(mapdata()->playerx)/64] == 'C')
	{
		(mapdata()->collectibles)--;
		mapdata()->map[(mapdata()->playery)/64][(mapdata()->playerx)/64] = '0';
	}
	if (mapdata()->map[(mapdata()->playery+10)/64][(mapdata()->playerx+10)/64] == 'E' && !mapdata()->collectibles
		&& write(1, "u win\n", 6))
	{
		data()->newgame=1;
		closewin();
	}
	//mapdata()->map[(mapdata()->playery)/64][(mapdata()->playerx/64)] = 'P';
	if(data()->coln<2)
		data()->coln++;
	else
		data()->coln=0;
	render(-1, 0);
	(data()->moves)++;
}

void	movenew(int keycode)
{
	if (keycode == 65307)
		closewin();
	if(keycode== 'w' || keycode ==65362)
		data()->ymove--;
	if(keycode== 'a' || keycode ==65361)
		data()->xmove--;
	if(keycode== 's' || keycode ==65364)
		data()->ymove++;
	if(keycode== 'd' || keycode ==65363)
		data()->xmove++;
	printf("move x=%i, move y=%i, collec=%i\n", mapdata()->playerx+data()->xmove,mapdata()->playery+data()->ymove, mapdata()->collectibles);
	if(mapdata()->map[(mapdata()->playery+data()->ymove+10)/64] \
			[(mapdata()->playerx+data()->xmove+10)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery+data()->ymove+10)/64][(mapdata()->playerx+data()->xmove+10)/64] == 'E' && mapdata()->collectibles))
	{
		return;
	}
	if(mapdata()->map[(mapdata()->playery+data()->ymove+10)/64] \
			[((mapdata()->playerx)+data()->xmove+54)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery+data()->ymove+10)/64][((mapdata()->playerx)+data()->xmove+54)/64] == 'E' && mapdata()->collectibles))
	{
		return;
	}	
	if(mapdata()->map[(mapdata()->playery +data()->ymove+54)/64] \
			[(mapdata()->playerx+data()->xmove+10)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery +data()->ymove+54)/64] \
			[(mapdata()->playerx+data()->xmove+10)/64] == 'E' && mapdata()->collectibles))
	{
		return;
	}
	if(mapdata()->map[(mapdata()->playery +data()->ymove+54)/64] \
			[(mapdata()->playerx+data()->xmove+54)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery +data()->ymove+54)/64] \
			[(mapdata()->playerx+data()->xmove+54)/64] == 'E' && mapdata()->collectibles))
	{
		return;
	}
	if (mapdata()->map[(mapdata()->playery+10)/64][(mapdata()->playerx+10)/64] == 'C')
	{
		(mapdata()->collectibles)--;
		mapdata()->map[(mapdata()->playery+10)/64][(mapdata()->playerx+10)/64] = '0';
	}
	if (mapdata()->map[(mapdata()->playery+10)/64][(mapdata()->playerx+10)/64] == 'E' && !mapdata()->collectibles
		&& write(1, "u win\n", 6))
	{
		data()->newgame=1;
		closewin();
	}
	if(data()->coln<2)
		data()->coln++;
	else
		data()->coln=0;
	(data()->moves)++;
}
int	reset(int keycode)
{
	if(data()->state==4)
	{
		if(keycode== 'w' || keycode ==65362 || keycode== 's' || keycode ==65364)
			data()->ymove=0;
		if(keycode== 'a' || keycode ==65361 || keycode== 'd' || keycode ==65363)
			data()->xmove=0;
	}
}
	
void	move(int keycode)
{
	if (keycode == 'w' && (mapdata()->map[(mapdata()->playery - SPEED+10)/64] \
			[(mapdata()->playerx+10)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery - SPEED+10)/64][(mapdata()->playerx+10)/64] == 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 'w' && (mapdata()->map[(mapdata()->playery - SPEED+10)/64] \
			[((mapdata()->playerx)+54)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery - SPEED+10)/64][((mapdata()->playerx)+54)/64] == 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 's' && (mapdata()->map[(mapdata()->playery + SPEED+54)/64] \
			[(mapdata()->playerx+10)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery + SPEED+54)/64] \
			[(mapdata()->playerx+10)/64] == 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 's' && (mapdata()->map[(mapdata()->playery + SPEED+54)/64] \
			[(mapdata()->playerx+54)/64] == '1' \
			|| (mapdata()->map[(mapdata()->playery + SPEED+54)/64] \
			[(mapdata()->playerx+54)/64] == 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 'a' && (mapdata()->map[(mapdata()->playery+10)/64] \
			[(mapdata()->playerx - SPEED+10)/64] == '1'
			|| (mapdata()->map[(mapdata()->playery+10)/64][(mapdata()->playerx - SPEED+10)/64] \
			== 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 'a' && (mapdata()->map[(mapdata()->playery+54)/64] \
			[(mapdata()->playerx - SPEED+10)/64] == '1'
			|| (mapdata()->map[(mapdata()->playery+54)/64][(mapdata()->playerx - SPEED+10)/64] \
			== 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 'd' && (mapdata()->map[(mapdata()->playery+10)/64] \
			[(mapdata()->playerx + SPEED+54)/64] == '1' || \
			(mapdata()->map[(mapdata()->playery+10)/64] \
			[(mapdata()->playerx + SPEED+54)/64] == 'E' && mapdata()->collectibles)))
		return ;
	if (keycode == 'd' && (mapdata()->map[(mapdata()->playery+54)/64] \
			[(mapdata()->playerx + SPEED+54)/64] == '1' || \
			(mapdata()->map[(mapdata()->playery+54)/64] \
			[(mapdata()->playerx + SPEED+54)/64] == 'E' && mapdata()->collectibles)))
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
	int i;
	int a;
	char *s;
	
	if(keycode==65288)
		if(data()->state>1)
		{
			data()->state--;
			data()->flag=1;
			data()->lvl=0;
			data()->flag_menu=0;
			printf("STATE CHANGE (%i)\n KEYCODE= %i\n", (data()->state), keycode);
			return(0);
		}
	if(data()->state==1)
		(data()->state)=2;
	else if(data()->state==2)
	{
		if(keycode=='s' || keycode== 65364)
		{
			mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[1], 0, 0);
        	data()->flag_menu=1;
		}
		if(keycode=='w' || keycode== 65362)
		{
			mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[0], 0, 0);
        	data()->flag_menu=0;
		}
		if(keycode==65293 || keycode==32)//spacebar + enter
		{
			if(data()->flag_menu==0)
			{
				printf("play!\n");
				data()->state=3;
				data()->flag=1;
				data()->flag_menu=0;
				data()->sleep=30;
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
			{
				if(data()->flag_menu==0)
					render_intro("img/shinji-rei/shinji-rei_", 7, 0);
				else if(data()->flag_menu==1)
					render_intro("img/rei-asuka/rei-asuka_", 7, 0);
        		data()->flag_menu++;
			}
		}
		if(keycode=='a' || keycode== 65361)
		{
			if(data()->flag_menu>0)
			{
				if(data()->flag_menu==1)
					evil_render_intro("img/shinji-rei/shinji-rei_", 7);
				else if(data()->flag_menu==2)
					evil_render_intro("img/rei-asuka/rei-asuka_", 7);
        		data()->flag_menu--;
			}
		}
		i=-1;
		end_loadscreen();
		data()->loadscreen = malloc(3 * sizeof(void *));
		if (!data()->loadscreen)
			return(1);
		while (++i<3)
        {
            s="img/player sel intro/player_sel_";
            s=ft_strjoin(s,ft_itoa(i));
            s=ft_strjoin(s,".xpm");
            data()->loadscreen[i]=  mlx_xpm_file_to_image((data()->mlx), s, &a, &a);
			data()->ldscrn_len++;
        }
		mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[data()->flag_menu], 0, 0);
		if(keycode==65293 || keycode==32)
		{
			data()->state=4;
			data()->player=data()->flag_menu;
		}
	}
	else if(data()->state==4)
		movenew(keycode);
	printf("STATE CHANGE (%i)\n KEYCODE= %i\n", (data()->state), keycode);
}
