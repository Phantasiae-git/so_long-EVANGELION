/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:28:33 by phanta            #+#    #+#             */
/*   Updated: 2024/03/08 20:08:30 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int levels(void)
{
    int fd;
    char *s;
    
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
}