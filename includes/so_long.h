/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:16:55 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/03 12:00:02 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "printf/include/ft_printf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

#define COMPOSEE_MAP "01CEP"

typedef struct s_list_maps
{
	int	P;
	int	C;
	int	E;
	int	len;
}	t_list_maps;

/* main.c */
void	free_tab_map(char **tab_map);
void	affichetab(char **tab);
/* ------ */

/* add_file_tab */
char	**generated_tab_for_map(char **argv);
char	*on_a_line(int fd);
/*--------------*/

/* get_next_line */
char	*get_next_line(int fd);
/* ------------- */

/* error */
// chr_elem.c
bool	composee_caract(char **str_map, char *composee);
bool	first_fast_line_maps(char *tab_map, char composee);
bool	medum_tab_map(char *tab_map, char *composee);
bool	verif_map(char **tab_map, char *composee, t_list_maps *info_map);
bool	verif_composee(char **tab_map, char *composee, t_list_maps *info_map);
//////////////
// print_error_comp.c
bool	print_error_comp(t_list_maps *info_map);
/////////////////////
// chr_output_valid.c
bool	chr_output_valid(char **tab_map);
char	**dup_tab(char **tab_src);
/////////////////////
/* ----- */

#endif