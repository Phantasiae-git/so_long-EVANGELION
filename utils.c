/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:01:27 by phanta            #+#    #+#             */
/*   Updated: 2024/03/14 18:07:42 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (++i < nmemb * size)
		ptr[i] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
	{
		return (0);
	}
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		len;

	len = ft_strlen(str) + 1;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, str, len);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = (char *)malloc(len1 + len2 + 1);
	if (!newstr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[len1 + len2] = '\0';
	return (newstr);
}

int	closewin(void)
{
	int i;
	if(data()->image)
	{
		mlx_destroy_image(data()->mlx, data()->image[0]);
		mlx_destroy_image(data()->mlx, data()->image[1]);
		mlx_destroy_image(data()->mlx, data()->image[2]);
		mlx_destroy_image(data()->mlx, data()->image[3]);
		mlx_destroy_image(data()->mlx, data()->image[5]);
		free(data()->image);	
	}
	if(data()->col)
	{
		i=-1;
		while(++i<3)
		{
			mlx_destroy_image(data()->mlx, data()->col[i]->img);
			free(data()->col[i]);
		}
		free(data()->col);
	}
	end_loadscreen();
	freearr();
	mlx_destroy_window(data()->mlx, data()->win);
	mlx_destroy_display(data()->mlx);
	free(data()->mlx);
	exit(0);
	return (0);
}

void	end_loadscreen(void)
{
	int i;

	i=-1;
	if(data()->loadscreen)
	{
		while(++i<(data()->ldscrn_len))
			mlx_destroy_image(data()->mlx, data()->loadscreen[i]);
		free(data()->loadscreen);
	}
	data()->ldscrn_len=0;
}

void	freearr(void)
{
	int	j;

	j = -1;
	if (mapdata()->tmp)
	{
		while (++j < mapdata()->height)
			free(mapdata()->tmp[j]);
		free(mapdata()->tmp);
	}
	j = -1;
	if (mapdata()->map)
	{
		while (++j < mapdata()->height)
			free(mapdata()->map[j]);
		free(mapdata()->map);
	}
}


int	timern(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (0);
	return ((int)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	ft_usleep(int time)
{
	int	rn;

	rn = timern();
	while ((timern() - rn) < time)
	{
		usleep(time / 10);
	}
}
