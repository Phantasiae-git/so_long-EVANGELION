/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:30:37 by rfontes-          #+#    #+#             */
/*   Updated: 2024/03/08 20:18:50 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**getmap(char **map, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		map = getmap(map, fd, i + 1);
	else if (i == 0 && map == NULL)
		return (NULL);
	else
	{
		map = (char **)ft_calloc((i + 2), sizeof(char *));
		mapdata()->height = i;
	}
	map[i] = line;
	if (map[i + 1] == NULL)
		mapdata()->length = ft_strlen(line);
	return (map);
}

char	**maptmp(char **map)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = (char **)ft_calloc(mapdata()->height, sizeof(char *));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < mapdata()->height)
	{
		j = -1;
		tmp[i] = (char *)ft_calloc((mapdata()->length) + 1, 1);
		if (!tmp)
			return (NULL);
		while (++j < mapdata()->length)
			tmp[i][j] = map[i][j];
	}
	return (tmp);
}

int	flood_fill2(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mapdata()->height)
	{
		j = -1;
		if (i + 1 < mapdata()->height)
			if ((int)ft_strlen(mapdata()->map[i]) != (mapdata()->length + 1))
				return (0);
		while (++j < mapdata()->length)
		{
			if (mapdata()->tmp[i][j] == 'C')
				return (0);
			if (mapdata()->tmp[i][j] == 'E' && !(mapdata()->tmp[i + 1][j] == 'P'
					|| mapdata()->tmp[i][j + 1] == 'P' || mapdata()->tmp[i
					- 1][j] == 'P' || mapdata()->tmp[i][j - 1] == 'P'))
				return (0);
		}
	}
	return (1);
}

void	flood_fill(char **map, int i, int j)
{
	map[i][j] = 'P';
	if (map[i][j - 1] == 'C' || map[i][j - 1] == '0')
		flood_fill(map, i, j - 1);
	if (map[i - 1][j] == 'C' || map[i - 1][j] == '0')
		flood_fill(map, i - 1, j);
	if (map[i][j + 1] == 'C' || map[i][j + 1] == '0')
		flood_fill(map, i, j + 1);
	if (map[i + 1][j] == 'C' || map[i + 1][j] == '0')
		flood_fill(map, i + 1, j);
	return ;
}

int	aaaaaa(int i, int j, int *player, int *exit)
{
	if (i == 0 || i == ((mapdata()->height) - 1) || j == 0
		|| j == ((mapdata()->length) - 1))
	{
		if (mapdata()->map[i][j] != '1')
			return (0);
	}
	else if (mapdata()->map[i][j] != '0' && mapdata()->map[i][j] != '1'
			&& mapdata()->map[i][j] != 'P' && mapdata()->map[i][j] != 'E'
			&& mapdata()->map[i][j] != 'C')
		return (0);
	if (mapdata()->map[i][j] == 'C')
		mapdata()->collectibles++;
	if (mapdata()->map[i][j] == 'P')
	{
		mapdata()->playery = i*64;
		mapdata()->playerx = j*64;
		(*player)++;
	}
	if (mapdata()->map[i][j] == 'E')
		(*exit)++;
	return (1);
}

int	chkvalidmap(void)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	i = -1;
	mapdata()->collectibles = 0;
	player = 0;
	exit = 0;
	while (++i < mapdata()->height)
	{
		j = -1;
		while (++j < mapdata()->length)
		{
			if (!aaaaaa(i, j, &player, &exit))
			{
				printf("c\n");
				return (0);
				
			}
		}
	}
	if (mapdata()->collectibles < 1 || player != 1 || exit != 1)
	{
		printf("a\n");
		return (0);
	}
	mapdata()->tmp = maptmp(mapdata()->map);
	flood_fill(mapdata()->tmp, (mapdata()->playery/64), (mapdata()->playerx/64));
	if (!flood_fill2())
	{
		printf("b\n");
		return(0);
	}
	return (1);
}
