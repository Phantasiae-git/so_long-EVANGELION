/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:31:39 by rfontes-          #+#    #+#             */
/*   Updated: 2024/02/29 18:40:33 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_mapdata	*mapdata(void)
{
	static t_mapdata	mapdata;

	return (&mapdata);
}

