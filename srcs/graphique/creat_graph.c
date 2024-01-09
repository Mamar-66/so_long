/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:47:10 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/09 17:59:40 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	gen_img_player(t_list_mlx *lst_mlx)
{
	int	x;
	int	y;

	lst_mlx->img_player_profil = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/player/profil.xpm", &x, &y);
	lst_mlx->img_player_right = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/player/right.xpm", &x, &y);
	lst_mlx->img_player_left = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/player/left.xpm", &x, &y);
	lst_mlx->img_player_back = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/player/back.xpm", &x, &y);
	if (!lst_mlx->img_player_profil || !lst_mlx->img_player_right
		|| !lst_mlx->img_player_left || !lst_mlx->img_player_back)
		return (false);
	return (true);
}

bool	gen_img(t_list_mlx *lst_mlx)
{
	int	x;
	int	y;

	lst_mlx->img_mur = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/mur.xpm", &x, &y);
	lst_mlx->img_floor = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/floor.xpm", &x, &y);
	lst_mlx->img_item = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/item.xpm", &x, &y);
	lst_mlx->img_door[0] = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/door/close_door.xpm", &x, &y);
	lst_mlx->img_door[1] = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/door/open_door.xpm", &x, &y);
	if (!lst_mlx->img_mur || !lst_mlx->img_door[0] || !lst_mlx->img_door[1]
		|| !gen_img_player(lst_mlx) || !gen_img_enemi(lst_mlx))
	{
		ft_printf("error the path of the image for the wall not found\n");
		return (false);
	}
	return (true);
}

void	put_img(t_list_mlx *lst_mlx)
{
	int	i;
	int	j;

	if (!gen_img(lst_mlx))
		stop(lst_mlx);
	j = 0;
	while (lst_mlx->map_tab[j])
	{
		i = 0;
		while (lst_mlx->map_tab[j][i])
		{
			if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[1])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
					lst_mlx->img_mur, i * MUL_WIN, j * MUL_WIN);
			else if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[0])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
					lst_mlx->img_floor, i * MUL_WIN, j * MUL_WIN);
			i++;
		}
		j++;
	}
	put_img_2(lst_mlx);
}

void	put_img_2(t_list_mlx *lst_mlx)
{
	int	i;
	int	j;

	j = 0;
	while (lst_mlx->map_tab[j])
	{
		i = 0;
		while (lst_mlx->map_tab[j][i])
		{
			if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[2])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
					lst_mlx->img_item, i * MUL_WIN, j * MUL_WIN);
			else if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[3])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
					lst_mlx->img_door[0], i * MUL_WIN, j * MUL_WIN);
			else if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[4])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
					lst_mlx->img_player_profil, i * MUL_WIN, j * MUL_WIN);
			else if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[5])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx,
					lst_mlx->img_enemi_profil, i * MUL_WIN, j * MUL_WIN);
			i++;
		}
		j++;
	}
}
bool	gen_img_enemi(t_list_mlx *lst_mlx)
{
	int	x;
	int	y;

	lst_mlx->img_enemi_profil = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/enemi/profil.xpm", &x, &y);
	lst_mlx->img_enemi_right = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/enemi/right.xpm", &x, &y);
	lst_mlx->img_enemi_left = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/enemi/left.xpm", &x, &y);
	lst_mlx->img_enemi_back = mlx_xpm_file_to_image(lst_mlx->ptr_mlx,
			"images/enemi/back.xpm", &x, &y);
	if (!lst_mlx->img_enemi_profil || !lst_mlx->img_enemi_right
		|| !lst_mlx->img_enemi_left || !lst_mlx->img_enemi_back)
		return (false);
	return (true);
}