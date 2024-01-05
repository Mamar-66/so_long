/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:47:10 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/05 17:00:14 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	put_img(t_list_mlx *lst_mlx)
{
	int	i;
	int	j;

	lst_mlx->img_mur = mlx_xpm_file_to_image(lst_mlx->ptr_mlx, "images/mur.xpm", &i, &j);
	if (lst_mlx->img_mur == NULL)
	{
		ft_printf("error the path of the image for the wall not found\n");
		return (false);
	}
	j = 0;
	while (lst_mlx->map_tab[j])
	{
		i = 0;
		while (lst_mlx->map_tab[j][i])
		{
			if (lst_mlx->map_tab[j][i] == COMPOSEE_MAP[1])
				mlx_put_image_to_window(lst_mlx->ptr_mlx, lst_mlx->win_mlx, lst_mlx->img_mur, i * MUL_WIN, j * MUL_WIN);
			i++;
		}
		j++;
	}
	mlx_destroy_image(lst_mlx->ptr_mlx, lst_mlx->img_mur);
	return (true);
}

static int	stop(t_list_mlx *my_params)
{
	mlx_destroy_window(my_params->ptr_mlx, my_params->win_mlx);
	mlx_destroy_display(my_params->ptr_mlx);
	free(my_params->ptr_mlx);
	free_tab_map(my_params->map_tab);
	return (exit (1), 0);
}

int	function(int keycode, void *param)
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
		function, (void *)lst_mlx);
	mlx_hook(lst_mlx->win_mlx, 17, 0L, stop, (void *)lst_mlx);
	put_img(lst_mlx);
	mlx_loop(lst_mlx->ptr_mlx);
}
