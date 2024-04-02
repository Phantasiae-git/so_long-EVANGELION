/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:03:49 by phanta            #+#    #+#             */
/*   Updated: 2024/04/02 21:46:23 by phanta           ###   ########.fr       */
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
# include <pthread.h>

# define SPEED 4

typedef struct s_mapdata
{
	char		**map;
	char		**tmp;
	int			height;
	int			length;
	int			collectibles;
	int			playerx;
	int			playery;
	int			yval;
	int			xval;
}				t_mapdata;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		sizeline;
	int		endian;
	char	*addr;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			moves;
	void		**image;
    void		**loadscreen;
	t_mapdata	*map;
	int			level;
	int			state;
	int			frames;
	int			flag;
	int			i;
	int			flag_menu;
	int			lvl;
	int			player;
	int			sleep;
	int			ldscrn_len;
	t_img		**col;
	int			coln;
	int			newgame;
	int			xmove;
	int			ymove;
	int			xenemy;
	int			yenemy;
	int			last_frame;
	t_img		*enemy;
}				t_data;

t_mapdata		*mapdata(void);
t_data			*data(void);
t_img			*img(void);

void			flood_fill(char **map, int i, int j);
void			put_img_pbp(t_img *image, int x, int y);
char	        *ft_itoa(int n);
int				timern(void);
char	        *ft_strdup(const char *str);
char	        *ft_strjoin(char *s1, char *s2);
int				reset(int keycode);
size_t          ft_strlen(const char *str);
void	        render(int i, int ft);
void            render_intro(char *path, int frames, int flag);
int             key_hook(int keycode, t_data *data);
int	            closewin(void);
void	        *ft_calloc(size_t nmemb, size_t size);
void	        images(void);
void	        freearr(void);
void			ft_usleep(int time);
int				megahook(int keycode);
void    		render_menu(void);
char			**getmap(char **map, int fd, int i);
int				chkvalidmap(void);
int				change_menu(int keycode, t_data *data);
void			render_player_sel(void);
int				levels(void);
void			evil_render_intro(char *path, int frames);
void			end_loadscreen(void);
void			move_check(void);

#endif