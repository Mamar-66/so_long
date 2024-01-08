/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:38:19 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/08 11:47:18 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	my_function(int keycode, void *param)
{
	t_list_mlx	*my_params;

	my_params = (t_list_mlx *)param;
	printf("code clavier est %d keycode\n", keycode);
	if (keycode == XK_Escape)
		stop(my_params);
	else if (keycode == 119 || keycode == 100 || keycode == 97 || keycode == 115
		|| keycode == XK_Up || keycode == XK_Right || keycode == XK_Left || keycode == XK_Down)
		mov_player(keycode, my_params);

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
