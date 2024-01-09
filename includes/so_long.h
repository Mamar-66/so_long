/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:16:55 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/09 22:40:50 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "printf/include/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

# define COMPOSEE_MAP "01CEPX"
# define MUL_WIN	64
# define TEMPS	10000

typedef struct s_list_maps
{
	int	p;
	int	c;
	int	e;
	int	len;
	int	lenght;
}	t_list_maps;

typedef struct s_list_x_y
{
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
	int		x_n;
	int		y_n;
	int		mov;
	int		temp;
}	t_list_x_y;

typedef struct s_list_minilx
{
	char		**map_tab;
	int			lenght;
	int			width;
	void		*ptr_mlx;
	void		*win_mlx;
	void		*img_player_profil;
	void		*img_player_right;
	void		*img_player_left;
	void		*img_player_back;
	void		*img_enemi_profil;
	void		*img_enemi_right;
	void		*img_enemi_left;
	void		*img_enemi_back;
	void		*img_mur;
	void		*img_floor;
	void		*img_item;
	void		*img_door[2];
	t_list_maps	lst_map;
	t_list_x_y	lst_x_y;
}	t_list_mlx;

/* main.c */
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
bool	chr_output_valid(char **tab_map, t_list_mlx *lst_mlx);
bool	find_way(char **tab_map, int x, int y, t_list_mlx *lst_mlx);
void	chr_pos(char **tab_map, t_list_x_y *x_y, char *composee);
/////////////////////
/* ----- */

/* utile */
// dup_tab.c
char	**dup_tab(char **tab_src);
///////////
// my_functiom_free.c
void	free_tab_map(char **tab_map);
void	my_free_img(t_list_mlx *lst_mlx);
void	my_free_img_enemi(t_list_mlx *lst_mlx);
int		stop(t_list_mlx *my_params);
/////////////////////
/*-------*/
/* graphique */
// creat_graph.c
bool	gen_img_player(t_list_mlx *lst_mlx);
bool	gen_img(t_list_mlx *lst_mlx);
void	put_img(t_list_mlx *lst_mlx);
void	put_img_2(t_list_mlx *lst_mlx);
bool	gen_img_enemi(t_list_mlx *lst_mlx);
////////////////
// add_graph.c
void	add_graphe(t_list_mlx *lst_mlx);
int		my_function(int keycode, void *param);
//////////////
// mov_player.c
void	mov_player(int keycode, t_list_mlx *lst_mlx);
///////////////
// gest_enemie.c
int		gest_mov_enemi(t_list_mlx *lst_mlx);
void	mov_enemi(int keycode, t_list_mlx *lst_mlx);
void	enemi_animation(t_list_mlx *lst_mlx);
////////////////
// mov_enemi.c
bool	enemi_mov_up(t_list_mlx *lst_mlx);
bool	enemi_mov_right(t_list_mlx *lst_mlx);
bool	enemi_mov_left(t_list_mlx *lst_mlx);
bool	enemi_mov_down(t_list_mlx *lst_mlx);
///////////////
/* --------- */
/* ----- */
#endif