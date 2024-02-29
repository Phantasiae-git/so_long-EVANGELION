/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:11:34 by phanta            #+#    #+#             */
/*   Updated: 2024/02/29 18:20:42 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     check(t_data *data)
{
    static int i=-1;
    if(i>(data->frames))
        i=-1;
    mlx_put_image_to_window(data->mlx, data->win, data->loadscreen[++i], 0, 0);
    ft_usleep(66);
    printf("intro frame: %i\n", i);
}

int     check2(t_data *data)
{
    if((data->i)>(data->frames))
        (data->i)=-1;
    mlx_put_image_to_window(data->mlx, data->win, data->loadscreen[++(data->i)], 0, 0);
    ft_usleep(10);
    printf("loop intro frame: %i\n", (data->i));
}

int     change_menu(int keycode, t_data *data)
{
    if(data->flag_menu && (keycode=='s' || keycode== 65364))
    {
        mlx_put_image_to_window(data->mlx, data->win, data->loadscreen[1], 0, 0);
        data->flag_menu=0;
    }
    else if(!data->flag_menu && (keycode=='w' || keycode== 65362))
    {
        mlx_put_image_to_window(data->mlx, data->win, data->loadscreen[0], 0, 0);
        data->flag_menu=1;
    }
    return(0);
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
        printf("storing image nr: %i\n", i);
        mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[i], 0, 0);
        ft_usleep(66);
        free(s);
    }
    i=-1;
    if(flag==0)
    {
        /*data()->frames=frames;
        while (++i<frames)
            check(data());*/
    }
    else
    {
        data()->frames=14;
        check2(data());
    }
}

void    render_menu(void)
{

    int a;
    if(data()->flag==1)
    {
        render_intro("img/menu/menu_start/menu_start_", 25, 0);
        data()->flag=0;
        if(data()->loadscreen)
            free(data()->loadscreen);
        data()->loadscreen = malloc(2 * sizeof(void *));
	    if (!data()->loadscreen)
		    return ;
        (data()->loadscreen[0]) = mlx_xpm_file_to_image((data()->mlx), "img/menu/menu_play.xpm", &a, &a);
        (data()->loadscreen[1]) = mlx_xpm_file_to_image((data()->mlx), "img/menu/menu_exit.xpm", &a, &a);
        data()->frames=2;
        mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[0], 0, 0);
        data()->flag=0;
    }
}

void    render_player_sel(void)
{
    
}
