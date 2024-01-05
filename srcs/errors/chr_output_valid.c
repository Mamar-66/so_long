/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_output_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:51:33 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/04 21:02:21 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	chr_output_valid(char **tab_map, t_list_mlx *lst_mlx)
{
	t_list_x_y	*indexs;

	indexs = malloc(sizeof(t_list_x_y) * 1);
	if (!indexs)
		exit (1);
	chr_pos(tab_map, indexs, COMPOSEE_MAP);
	lst_mlx->lst_map.P = 0;
	lst_mlx->lst_map.C = 0;
	lst_mlx->lst_map.E = 0;
	verif_composee(tab_map, COMPOSEE_MAP, &lst_mlx->lst_map);
	find_way(tab_map, indexs->x_p, indexs->y_p, lst_mlx);
	if (lst_mlx->lst_map.E != 0 || lst_mlx->lst_map.C != 0)
	{
		if (lst_mlx->lst_map.E != 0)
			ft_printf("error the output is not accessible\n");
		if (lst_mlx->lst_map.C != 0)
			ft_printf("error not all items are accessible\n");
		free(indexs);
		free_tab_map(tab_map);
		return (false);
	}
	free(indexs);
	free_tab_map(tab_map);
	return (true);
}

bool	find_way(char **tab_map, int x, int y, t_list_mlx *lst_mlx)
{
	if (tab_map[x][y] == COMPOSEE_MAP[2])
		lst_mlx->lst_map.C--;
	if (tab_map[x][y] == COMPOSEE_MAP[3])
		lst_mlx->lst_map.E--;
	if (tab_map[x][y] == COMPOSEE_MAP[1] || tab_map[x][y] == '*')
		return (false);
	tab_map[x][y] = '*';
	find_way(tab_map, x - 1, y, lst_mlx);
	find_way(tab_map, x + 1, y, lst_mlx);
	find_way(tab_map, x, y - 1, lst_mlx);
	find_way(tab_map, x, y + 1, lst_mlx);
	return (false);
}

void	chr_pos(char **tab_map, t_list_x_y *x_y, char *composee)
{
	int	i;
	int	j;

	j = 0;
	while (tab_map[j])
	{
		i = 0;
		while (tab_map[j][i])
		{
			if (tab_map[j][i] == composee[4])
			{
				x_y->x_p = j;
				x_y->y_p = i;
			}
			if (tab_map[j][i] == composee[3])
			{
				x_y->x_e = j;
				x_y->y_e = i;
			}
			i++;
		}
		j++;
	}
}
