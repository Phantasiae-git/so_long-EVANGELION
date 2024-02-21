/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:03:49 by phanta            #+#    #+#             */
/*   Updated: 2024/02/21 21:55:53 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_mapdata
{
	char		**map;
	char		**tmp;
	int			height;
	int			length;
	int			collectibles;
	int			playerx;
	int			playery;
}				t_mapdata;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			moves;
	void		**image;
    void		**loadscreen;
	t_mapdata	*map;
}				t_data;

t_mapdata		*mapdata(void);
t_data			*data(void);

void			flood_fill(char **map, int i, int j);
char	        *ft_itoa(int n);
char	        *ft_strdup(const char *str);
char	        *ft_strjoin(char const *s1, char const *s2);
size_t          ft_strlen(const char *str);
void	        render(int i);
void            render_intro(void);
int             key_hook(int keycode, t_data *data);
int	            closewin(void);
void	        *ft_calloc(size_t nmemb, size_t size);
void	        images(void);
void	        freearr(void);
void			ft_usleep(int time);

#endif