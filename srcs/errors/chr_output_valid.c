/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_output_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:51:33 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/03 22:36:18 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	chr_output_valid(char **tab_map)
{
	t_list_x_y	*indexs;

	indexs = malloc(sizeof(t_list_x_y) * 1);
	if (!indexs)
		exit (1);
	chr_pos(tab_map, indexs, COMPOSEE_MAP);
	if (!find_way(tab_map, indexs->x_p, indexs->y_p, COMPOSEE_MAP))
	{
		ft_printf("the output is not accessible\n");
		free(indexs);
		free_tab_map(tab_map);
		return (false);
	}
	free(indexs);
	free_tab_map(tab_map);
	return (true);
}

bool	find_way(char **tab_map, int x, int y, char *composee)
{
	if (tab_map[x][y] == composee[3])
		return (true);
	if (tab_map[x][y] == composee[1] || tab_map[x][y] == '*')
		return (false);
	tab_map[x][y] = '*';
	if (find_way(tab_map, x - 1, y , composee) || find_way(tab_map, x + 1, y , composee)
		|| find_way(tab_map, x, y - 1 , composee) || find_way(tab_map, x, y + 1, composee))
	{
		return (true);
	}
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
		while(tab_map[j][i])
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
