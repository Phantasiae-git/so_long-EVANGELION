/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:00:45 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/15 23:43:43 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*string[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (0);
	string[fd] = readfile(string[fd], fd, -1);
	if (!string[fd])
		return (NULL);
	line = getlinefromstring(string[fd]);
	string[fd] = advancestring(string[fd]);
	return (line);
}
