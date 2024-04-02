/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:28:33 by phanta            #+#    #+#             */
/*   Updated: 2024/04/02 13:46:50 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int levels(void)
{
    int fd;
    char *s;
    
	//put loop animations here
	if(!data()->newgame)
	{
		if((timern()-data()->last_frame)>15)
		{
			//if difference between last frame timestamp and timern bigger than time between frames (15ms?)
			(mapdata()->playery)=(mapdata()->playery)+data()->ymove;
			(mapdata()->playerx)=(mapdata()->playerx)+data()->xmove;
			printf("timern=%i\n", timern()-data()->last_frame);
			render(-1, 0);
			data()->last_frame=timern();
		}
		return(0);
	}
    data()->lvl++;
    s=ft_strjoin("maps/lvl",ft_itoa(data()->lvl));
    s=ft_strjoin(s,".ber");
    fd = open(s, O_RDONLY);
	free(s);
	if (fd < 0)
		return (0);
	data()->map = mapdata();
	(mapdata()->map) = getmap((mapdata()->map), fd, 0);
	close(fd);
	if (!mapdata()->map)
		return (0);
	if (!chkvalidmap())
		return (0);
	render(-1, 1);
	data()->last_frame=timern();
	data()->newgame=0;
}