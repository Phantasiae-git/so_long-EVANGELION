/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:57:03 by phanta            #+#    #+#             */
/*   Updated: 2024/03/04 17:04:45 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     choose(t_data *data)
{
	if(data->state==1)
		render_intro("img/intro_loop/intro_part2_", 16, 1);
	else if(data->state==2)
		render_menu();
	else if(data->state==3)
		render_player_sel();
	else if(data->state==4)
		levels();
}

int	main(int argc, char **argv)//keep argc and argv for secret commands?
{
	data()->mlx = mlx_init();
	(data()->win) = mlx_new_window((data()->mlx), 1280, 960, "So_long, and it all comes tumbling down");
	data()->state=0;
	data()->flag=1;
	data()->sleep=66;
	data()->ldscrn_len=0;
	render_intro("img/intro/so_long_intro_", 63, 0);
	data()->i=-1;
	data()->flag_menu=0;
	data()->state=1;
	data()->lvl=0;
	mlx_loop_hook(data()->mlx, choose, data());
    mlx_hook(data()->win, 02, 1L << 0, megahook, NULL);	
	mlx_hook(data()->win, 17, 1L << 2, closewin, NULL);
	mlx_loop(data()->mlx);
}