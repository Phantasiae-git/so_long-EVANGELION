/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:02:33 by rfontes-          #+#    #+#             */
/*   Updated: 2024/02/21 21:00:00 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}

char	*readfile(char *string, int fd, int i)
{
	char	*content;
	int		readb;

	content = (char *)malloc(BUFFER_SIZE + 1);
	if (!content)
		return (NULL);
	while (++i <= BUFFER_SIZE)
		content[i] = '\0';
	readb = 4;
	while (!ft_strchr(string, '\n') && readb != 0)
	{
		readb = read(fd, content, BUFFER_SIZE);
		if (readb < 0)
		{
			if (string)
				free(string);
			free(content);
			return (NULL);
		}
		content[readb] = '\0';
		string = ft_strjoin_gnl(string, content);
	}
	free(content);
	return (string);
}

char	*getlinefromstring(char *string)
{
	char	*line;
	int		i;

	i = 0;
	while (string[i] != '\n' && string[i])
		i++;
	if (i == 0 && string[i] != '\n')
		return (NULL);
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i])
	{
		line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*advancestring(char *string)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i++])
	{
		free(string);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(string) - i) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (string[i])
		str[j++] = string[i++];
	str[j] = '\0';
	free(string);
	return (str);
}
