/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:01:27 by rfontes-          #+#    #+#             */
/*   Updated: 2024/02/21 20:59:44 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*readfile(char *string, int fd, int i);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *left_str, char *buff);
size_t	ft_strlen(const char *s);
char	*getlinefromstring(char *string);
char	*advancestring(char *string);

#endif