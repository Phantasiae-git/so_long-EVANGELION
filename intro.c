/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:11:34 by phanta            #+#    #+#             */
/*   Updated: 2024/02/21 21:56:31 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_intro(void)
{
    int	a;
    int i;
    char *s;
    int len;
    int j;

	data()->loadscreen = malloc(63 * sizeof(void *));
	if (!data()->loadscreen)
		return ;
    i=-1;
    while(++i<63)
    {
        j=-1;
        s=ft_strdup("img/intro/so_long_intro_");
        len=ft_strlen(ft_itoa(i));
        while(++j<5-len)
            s=ft_strjoin(s, "0");
        s=ft_strjoin(s,ft_itoa(i));
        s=ft_strjoin(s,".xpm");
        (data()->loadscreen[i]) = mlx_xpm_file_to_image((data()->mlx), s, &a, &a);
    }
    i=-1;
    while(++i<63)
    {
        if(data()->loadscreen[i])
            printf("image %i\n", i);
        mlx_put_image_to_window(data()->mlx, data()->win, data()->loadscreen[i], 0, 0);
        ft_usleep(66);
    }
    
}

