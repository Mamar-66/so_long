/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:16:55 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/29 16:07:56 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "printf/include/ft_printf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

/* add_file_tab */
char	**generated_tab_for_map(char **argv);
char	*on_a_line(int fd);
/*--------------*/

/* get_next_line */
char	*get_next_line(int fd);
/* ------------- */
#endif