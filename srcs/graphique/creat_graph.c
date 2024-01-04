/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:47:10 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/04 14:21:10 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
void	add_graphe(char **argv, t_list_mlx *lst_mlx)
{
	if (!argv[2])
		lst_mlx->mult = 64;
	else
		lst_mlx->mult = ft_atoi(argv[2]);
	lst_mlx->ptr_mlx = mlx_init();
	if (!lst_mlx->ptr_mlx)
	{
		free(lst_mlx);
		return ;
	}
	lst_mlx->win_mlx = mlx_new_window(lst_mlx->ptr_mlx, (lst_mlx->width * lst_mlx->mult)
									, (lst_mlx->lenght * lst_mlx->mult), "so_long");
	mlx_hook(lst_mlx->win_mlx, 3, (1L << 0) + (1L << 1), function, (void *)lst_mlx);
	mlx_hook(lst_mlx->win_mlx, 17, 0L, stop, (void *)lst_mlx);
	mlx_loop(lst_mlx->ptr_mlx);
}
