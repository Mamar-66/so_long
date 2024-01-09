/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_enemi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:35:49 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/09 22:54:48 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	gest_mov_enemi(t_list_mlx *lst_mlx)
{
	if (lst_mlx->map_tab[lst_mlx->lst_x_y.y_p]
		[lst_mlx->lst_x_y.x_p] == COMPOSEE_MAP [5])
		stop(lst_mlx);
	if (lst_mlx->lst_x_y.temp++ > TEMPS)
	{
		enemi_animation(lst_mlx);
		lst_mlx->lst_x_y.temp = 0;
	}
	return (1);
}

void	mov_enemi(int keycode, t_list_mlx *lst_mlx)
{
	if (keycode == 0)
		enemi_mov_up(lst_mlx);
	else if (keycode == 1)
		enemi_mov_right(lst_mlx);
	else if (keycode == 2)
		enemi_mov_left(lst_mlx);
	else if (keycode == 3)
		enemi_mov_down(lst_mlx);
}

void	enemi_animation(t_list_mlx *lst_mlx)
{
	int	i;
	int	j;

	j = -1;
	while (lst_mlx->map_tab[++j])
	{
		i = -1;
		while (lst_mlx->map_tab[j][++i])
		{
			if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[5])
			{
				lst_mlx->lst_x_y.y_n = j;
				lst_mlx->lst_x_y.x_n = i;
				mov_enemi(rand() % 4, lst_mlx);
				j = lst_mlx->lst_x_y.y_n;
				i = lst_mlx->lst_x_y.x_n;
			}
		}
	}
}
