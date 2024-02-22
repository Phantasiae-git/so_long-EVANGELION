/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:11:34 by phanta            #+#    #+#             */
/*   Updated: 2024/02/22 06:44:30 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     check(t_data *data)
{
    static int i=-1;
    if(i>14)
        i=-1;
    mlx_put_image_to_window(data->mlx, data->win, data->loadscreen[++i], 0, 0);
    ft_usleep(66);
}

int     change_menu(int keycode, t_data *data)
{
    static int flag_menu;
    
    printf("hello?\n");
    flag_menu=1;
    if(keycode==126 || keycode==125 || keycode=='w' || keycode=='s')
    {
        if(flag_menu)
            mlx_put_image_to_window(data->mlx, data->win, data->loadscreen[1], 0, 0);
        else
            mlx_put_image_to_window(data->mlx, data->win, data->loadscreen[0], 0, 0);
    }
    return(0);
}

void    render_menu(void)
{
    int a;
    data()->loadscreen = malloc(2 * sizeof(void *));
	if (!data()->loadscreen)
		return ;
    (data()->loadscreen[0]) = mlx_xpm_file_to_image((data()->mlx), "img/menu/menu_play.xpm", &a, &a);
    (data()->loadscreen[1]) = mlx_xpm_file_to_image((data()->mlx), "img/menu/menu_exit.xpm", &a, &a);
    mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[0], 0, 0);
    mlx_hook(data()->win, 02, 1L << 0, change_menu, data());
    mlx_loop(data()->mlx);
}

void render_intro(char *path, int frames, int flag)
{
    int	a;
    int i;
    char *s;
    int len;
    int j;

	data()->loadscreen = malloc(frames * sizeof(void *));
	if (!data()->loadscreen)
		return ;
    i=-1;
    while(++i<frames)
    {
        j=-1;
        s=ft_strdup(path);
        len=ft_strlen(ft_itoa(i));
        while(++j<5-len)
            s=ft_strjoin(s, "0");
        s=ft_strjoin(s,ft_itoa(i));
        s=ft_strjoin(s,".xpm");
        (data()->loadscreen[i]) = mlx_xpm_file_to_image((data()->mlx), s, &a, &a);
    }
    i=-1;
    if(flag==0)
    {
        while(++i<frames)
        {
            mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[i], 0, 0);
            ft_usleep(66);
        }
        i=-1;
        while(++i<frames)
            mlx_destroy_image(data()->mlx, data()->loadscreen[i]);
        free(data()->loadscreen);
    }
    else
    {
        mlx_hook(data()->win, 02, 1L << 0, menu, data());
	    mlx_hook(data()->win, 17, 1L << 2, closewin, data());
        mlx_loop_hook(data()->mlx, check, data());
        mlx_loop(data()->mlx);
        i=-1;
        while(++i<frames)
            mlx_destroy_image(data()->mlx, data()->loadscreen[i]);
        free(data()->loadscreen);
        mlx_destroy_window(data()->mlx, data()->win);
	    mlx_destroy_display(data()->mlx);
    }
}

