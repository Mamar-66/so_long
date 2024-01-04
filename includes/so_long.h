/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:16:55 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/04 14:16:21 by omfelk           ###   ########.fr       */
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
#include <X11/keysym.h>

#define COMPOSEE_MAP "01CEP"

typedef struct s_list_maps
{
	int	P;
	int	C;
	int	E;
	int	len;
	int	lenght;
}	t_list_maps;

typedef struct s_list_x_y
{
	int	x_p;
	int	y_p;
	int	x_e;
	int	y_e;
}	t_list_x_y;

typedef struct s_list_minilx
{
	char	**map_tab;
	int		lenght;
	int		width;
	int		mult;
	void 	*ptr_mlx;
	void 	*win_mlx;
}	t_list_mlx;


/* main.c */
void	free_tab_map(char **tab_map);
void	affichetab(char **tab);
/* ------ */

/* add_file_tab */
char	**generated_tab_for_map(char **argv, t_list_mlx *lst_mlx);
char	*on_a_line(int fd);
/*--------------*/

/* get_next_line */
char	*get_next_line(int fd);
/* ------------- */

/* error */
// chr_elem.c
bool	composee_caract(char **str_map, char *composee, t_list_mlx *lst_mlx);
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
bool	find_way(char **tab_map, int x, int y, char *composee);
void	chr_pos(char **tab_map, t_list_x_y *x_y,char *composee);
/////////////////////
/* ----- */
/* utile */
// dup_tab.c
char	**dup_tab(char **tab_src);
///////////
/* graphique */
void	add_graphe(char **argv, t_list_mlx *lst_mlx);
/* --------- */
/* ----- */
#endif