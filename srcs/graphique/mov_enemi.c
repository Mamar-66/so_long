/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_enemi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:56:00 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/09 22:08:59 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	enemi_mov_up(t_list_mlx *lst_mlx)
{
	int	y;

	y = lst_mlx->lst_x_y.y_n;
	if (lst_mlx->map_tab[--y][lst_mlx->lst_x_y.x_n] != COMPOSEE_MAP[1]
		&& lst_mlx->map_tab[y][lst_mlx->lst_x_y.x_n] != COMPOSEE_MAP[2]
		&& lst_mlx->map_tab[y][lst_mlx->lst_x_y.x_n] != COMPOSEE_MAP[3]
		&& lst_mlx->map_tab[y][lst_mlx->lst_x_y.x_n] != COMPOSEE_MAP[5])
	{
		lst_mlx->lst_x_y.y_n = y;
		lst_mlx->map_tab[y][lst_mlx->lst_x_y.x_n] = COMPOSEE_MAP[5];
		lst_mlx->map_tab[++y][lst_mlx->lst_x_y.x_n] = COMPOSEE_MAP[0];
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_floor,
			lst_mlx->lst_x_y.x_n * MUL_WIN, ++lst_mlx->lst_x_y.y_n * MUL_WIN);
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_enemi_back,
			lst_mlx->lst_x_y.x_n * MUL_WIN, --lst_mlx->lst_x_y.y_n * MUL_WIN);
		return (true);
	}
	return (false);
}

bool	enemi_mov_right(t_list_mlx *lst_mlx)
{
	int	x;

	x = lst_mlx->lst_x_y.x_n;
	if (lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][++x] != COMPOSEE_MAP[1]
		&& lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][x] != COMPOSEE_MAP[2]
		&& lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][x] != COMPOSEE_MAP[3]
		&& lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][x] != COMPOSEE_MAP[5])
	{
		lst_mlx->lst_x_y.x_n = x;
		lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][x] = COMPOSEE_MAP[5];
		lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][--x] = COMPOSEE_MAP[0];
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_floor,
			--lst_mlx->lst_x_y.x_n * MUL_WIN, lst_mlx->lst_x_y.y_n * MUL_WIN);
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_enemi_right,
			++lst_mlx->lst_x_y.x_n * MUL_WIN, lst_mlx->lst_x_y.y_n * MUL_WIN);
		return (true);
	}
	return (false);
}

bool	enemi_mov_left(t_list_mlx *lst_mlx)
{
	int	x;

	x = lst_mlx->lst_x_y.x_n;
	if (lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][--x] != COMPOSEE_MAP[1]
		&& lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][x] != COMPOSEE_MAP[2]
		&& lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][x] != COMPOSEE_MAP[3]
		&& lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][x] != COMPOSEE_MAP[5])
	{
		lst_mlx->lst_x_y.x_n = x;
		lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][x] = COMPOSEE_MAP[5];
		lst_mlx->map_tab[lst_mlx->lst_x_y.y_n][++x] = COMPOSEE_MAP[0];
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_floor,
			++lst_mlx->lst_x_y.x_n * MUL_WIN, lst_mlx->lst_x_y.y_n * MUL_WIN);
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_enemi_left,
			--lst_mlx->lst_x_y.x_n * MUL_WIN, lst_mlx->lst_x_y.y_n * MUL_WIN);
		return (true);
	}
	return (false);
}

bool	enemi_mov_down(t_list_mlx *lst_mlx)
{
	int	y;

	y = lst_mlx->lst_x_y.y_n;
	if (lst_mlx->map_tab[++y][lst_mlx->lst_x_y.x_n] != COMPOSEE_MAP[1]
		&& lst_mlx->map_tab[y][lst_mlx->lst_x_y.x_n] != COMPOSEE_MAP[2]
		&& lst_mlx->map_tab[y][lst_mlx->lst_x_y.x_n] != COMPOSEE_MAP[3]
		&& lst_mlx->map_tab[y][lst_mlx->lst_x_y.x_n] != COMPOSEE_MAP[5])
	{
		lst_mlx->lst_x_y.y_n = y;
		lst_mlx->map_tab[y][lst_mlx->lst_x_y.x_n] = COMPOSEE_MAP[5];
		lst_mlx->map_tab[--y][lst_mlx->lst_x_y.x_n] = COMPOSEE_MAP[0];
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_floor,
			lst_mlx->lst_x_y.x_n * MUL_WIN, --lst_mlx->lst_x_y.y_n * MUL_WIN);
		mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
			lst_mlx->img_enemi_profil,
			lst_mlx->lst_x_y.x_n * MUL_WIN, ++lst_mlx->lst_x_y.y_n * MUL_WIN);
		return (true);
	}
	return (false);
}

