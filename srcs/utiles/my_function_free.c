/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_function_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:58:20 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/09 17:34:27 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_tab_map(char **tab_map)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		free(tab_map[i]);
		i++;
	}
	free(tab_map);
}

void	my_free_img(t_list_mlx *lst_mlx)
{
	if (lst_mlx->img_mur)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_mur);
	if (lst_mlx->img_floor)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_floor);
	if (lst_mlx->img_item)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_item);
	if (lst_mlx->img_player_profil)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_player_profil);
	if (lst_mlx->img_player_right)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_player_right);
	if (lst_mlx->img_player_left)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_player_left);
	if (lst_mlx->img_player_back)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_player_back);
	if (lst_mlx->img_door[0])
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_door[0]);
	if (lst_mlx->img_door[1])
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_door[1]);
	my_free_img_enemi(lst_mlx);
}

void	my_free_img_enemi(t_list_mlx *lst_mlx)
{
	if (lst_mlx->img_enemi_profil)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_enemi_profil);
	if (lst_mlx->img_enemi_right)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_enemi_right);
	if (lst_mlx->img_enemi_left)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_enemi_left);
	if (lst_mlx->img_enemi_back)
		mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_enemi_back);
}

int	stop(t_list_mlx *my_params)
{
	my_free_img(my_params);
	mlx_destroy_window(my_params->ptr_mlx, my_params->win_mlx);
	mlx_destroy_display(my_params->ptr_mlx);
	free(my_params->ptr_mlx);
	free_tab_map(my_params->map_tab);
	return (exit (1), 0);
}

