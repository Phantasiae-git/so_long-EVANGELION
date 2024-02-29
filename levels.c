/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:28:33 by phanta            #+#    #+#             */
/*   Updated: 2024/02/29 18:33:01 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void levels(void)
{
    int fd;
    
    data()->lvl++;
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
}