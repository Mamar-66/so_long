/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:47:10 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/06 15:02:39 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	gen_img(t_list_mlx *lst_mlx)
{
	int	x;
	int	y;

	lst_mlx->img_mur = mlx_xpm_file_to_image(lst_mlx->ptr_mlx, "images/mur.xpm", &x, &y);
	lst_mlx->img_floor = mlx_xpm_file_to_image(lst_mlx->ptr_mlx, "images/floor.xpm", &x, &y);
	lst_mlx->img_player_profil = mlx_xpm_file_to_image(lst_mlx->ptr_mlx, "images/player/profil.xpm", &x, &y);
	lst_mlx->img_item = mlx_xpm_file_to_image(lst_mlx->ptr_mlx, "images/item.xpm", &x, &y);
	lst_mlx->img_door[0] = mlx_xpm_file_to_image(lst_mlx->ptr_mlx, "images/door/close_door.xpm", &x, &y);
	lst_mlx->img_door[1] = mlx_xpm_file_to_image(lst_mlx->ptr_mlx, "images/door/open_door.xpm", &x, &y);
	if (!lst_mlx->img_mur || !lst_mlx->img_door[0] || !lst_mlx->img_door[1])
	{
		ft_printf("error the path of the image for the wall not found\n");
		return (false);
	}
	return (true);
}

bool	put_img(t_list_mlx *lst_mlx)
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
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx, lst_mlx->img_mur, i * MUL_WIN, j * MUL_WIN);
			else if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[0])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx, lst_mlx->img_floor, i * MUL_WIN, j * MUL_WIN);
			else if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[2])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx, lst_mlx->img_item, i * MUL_WIN, j * MUL_WIN);
			else if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[3])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx, lst_mlx->img_door[0], i * MUL_WIN, j * MUL_WIN);
			else if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[4])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx, lst_mlx->img_player_profil, i * MUL_WIN, j * MUL_WIN);
			i++;
		}
		j++;
	}
	return (true);
}

int	my_function(int keycode, void *param)
{
	t_list_mlx	*my_params;

	my_params = (t_list_mlx *)param;
	printf("code clavier est %d keycode\n", keycode);
	if (keycode == XK_Escape)
		stop(my_params);
	return (1);
}

void	add_graphe(t_list_mlx *lst_mlx)
{
	lst_mlx->ptr_mlx = mlx_init();
	if (!lst_mlx->ptr_mlx)
	{
		free(lst_mlx);
		return ;
	}
	lst_mlx->win_mlx = mlx_new_window(lst_mlx->ptr_mlx,
			(lst_mlx->width * MUL_WIN), (lst_mlx->lenght * MUL_WIN), "so_long");
	mlx_hook(lst_mlx->win_mlx, 3, (1L << 0) + (1L << 1),
		my_function, (void *)lst_mlx);
	mlx_hook(lst_mlx->win_mlx, 17, 0L, stop, (void *)lst_mlx);
	put_img(lst_mlx);
	mlx_loop(lst_mlx->ptr_mlx);
}
