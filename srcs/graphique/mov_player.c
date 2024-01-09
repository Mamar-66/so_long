/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:56:00 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/09 20:41:33 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	mov_up(t_list_mlx *lst_mlx)
{
	int	y;

	y = lst_mlx->lst_x_y.y_p;
	if (lst_mlx->map_tab[--y][lst_mlx->lst_x_y.x_p] != COMPOSEE_MAP[1])
	{
		lst_mlx->lst_x_y.mov++;
		lst_mlx->lst_x_y.y_p = y;
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_floor,
			lst_mlx->lst_x_y.x_p * MUL_WIN, ++lst_mlx->lst_x_y.y_p * MUL_WIN);
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_player_back,
			lst_mlx->lst_x_y.x_p * MUL_WIN, --lst_mlx->lst_x_y.y_p * MUL_WIN);
	}
	else
	{
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_player_back,
			lst_mlx->lst_x_y.x_p * MUL_WIN, lst_mlx->lst_x_y.y_p * MUL_WIN);
	}
}

static void	mov_right(t_list_mlx *lst_mlx)
{
	int	x;

	x = lst_mlx->lst_x_y.x_p;
	if (lst_mlx->map_tab[lst_mlx->lst_x_y.y_p][++x] != COMPOSEE_MAP[1])
	{
		lst_mlx->lst_x_y.mov++;
		lst_mlx->lst_x_y.x_p = x;
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_floor,
			--lst_mlx->lst_x_y.x_p * MUL_WIN, lst_mlx->lst_x_y.y_p * MUL_WIN);
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_player_right,
			++lst_mlx->lst_x_y.x_p * MUL_WIN, lst_mlx->lst_x_y.y_p * MUL_WIN);
	}
	else
	{
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_player_right,
			lst_mlx->lst_x_y.x_p * MUL_WIN, lst_mlx->lst_x_y.y_p * MUL_WIN);
	}
}

static void	mov_left(t_list_mlx *lst_mlx)
{
	int	x;

	x = lst_mlx->lst_x_y.x_p;
	if (lst_mlx->map_tab[lst_mlx->lst_x_y.y_p][--x] != COMPOSEE_MAP[1])
	{
		lst_mlx->lst_x_y.mov++;
		lst_mlx->lst_x_y.x_p = x;
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_floor,
			++lst_mlx->lst_x_y.x_p * MUL_WIN, lst_mlx->lst_x_y.y_p * MUL_WIN);
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_player_left,
			--lst_mlx->lst_x_y.x_p * MUL_WIN, lst_mlx->lst_x_y.y_p * MUL_WIN);
	}
	else
	{
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_player_left,
			lst_mlx->lst_x_y.x_p * MUL_WIN, lst_mlx->lst_x_y.y_p * MUL_WIN);
	}
}

static void	mov_down(t_list_mlx *lst_mlx)
{
	int	y;

	y = lst_mlx->lst_x_y.y_p;
	if (lst_mlx->map_tab[++y][lst_mlx->lst_x_y.x_p] != COMPOSEE_MAP[1])
	{
		lst_mlx->lst_x_y.mov++;
		lst_mlx->lst_x_y.y_p = y;
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_floor,
			lst_mlx->lst_x_y.x_p * MUL_WIN, --lst_mlx->lst_x_y.y_p * MUL_WIN);
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_player_profil,
			lst_mlx->lst_x_y.x_p * MUL_WIN, ++lst_mlx->lst_x_y.y_p * MUL_WIN);
	}
	else
	{
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_player_profil,
			lst_mlx->lst_x_y.x_p * MUL_WIN, lst_mlx->lst_x_y.y_p * MUL_WIN);
	}
}

void	mov_player(int keycode, t_list_mlx *lst_mlx)
{
	char		*nb_mov;

	nb_mov = ft_itoa(lst_mlx->lst_x_y.mov);
	if ((keycode == 119 || keycode == XK_Up))
		mov_up(lst_mlx);
	else if (keycode == 100 || keycode == XK_Right)
		mov_right(lst_mlx);
	else if (keycode == 97 || keycode == XK_Left)
		mov_left(lst_mlx);
	else if (keycode == 115 || keycode == XK_Down)
		mov_down(lst_mlx);
	if (lst_mlx->map_tab[lst_mlx->lst_x_y.y_p]
		[lst_mlx->lst_x_y.x_p] == COMPOSEE_MAP[2])
	{
		lst_mlx->map_tab[lst_mlx->lst_x_y.y_p]
		[lst_mlx->lst_x_y.x_p] = COMPOSEE_MAP[0];
		--lst_mlx->lst_map.c;
	}
	mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
		lst_mlx->img_mur, 0, 0);
	mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
		lst_mlx->img_mur, 64, 0);
	mlx_string_put(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
		10, 10, -200, nb_mov);
	free(nb_mov);
}
