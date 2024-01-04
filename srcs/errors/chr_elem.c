/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:59:25 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/04 14:14:49 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	composee_caract(char **tab_map, char *composee, t_list_mlx *lst_mlx)
{
	t_list_maps	*info_map;

	info_map = malloc(sizeof(t_list_maps) * 1);
	if (!info_map)
		return (false);
	info_map->P = 0;
	info_map->C = 0;
	info_map->E = 0;
	info_map->len = strlen(tab_map[0]);
	lst_mlx->width = info_map->len;
	if (!verif_map(tab_map, composee, info_map)
	|| !verif_composee(tab_map, composee, info_map))
	{
		free(info_map);
		return (false);
	}
	lst_mlx->lenght = info_map->lenght;
	free(info_map);
	return (true);
}

bool	first_fast_line_maps(char *tab_map, char composee)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		if (tab_map[i] != composee)
		{
			ft_printf("error on the delimitation of the maps (up down)\n");
			return (false);
		}
		i++;
	}
	return (i);
}

bool	medum_tab_map(char *tab_map, char *composee)
{
	int	i;
	int	j;

	i = -1;
	while (tab_map[++i])
	{
		j = 0;
		while (composee[j])
		{
			if (tab_map[i] == composee[j])
				break;
			j++;
		}
		if (composee[j] == '\0')
		{
			ft_printf("character \"%c\" is not part of the map component\n", tab_map[i]);
			return (false);
		}
	}
	if (tab_map[0] != composee[1] || tab_map[i - 1] != composee[1])
	{
			ft_printf("error on the delimitation of the maps (medum)\n");
			return (false);
	}
	return (i);
}

bool	verif_map(char **tab_map, char *composee, t_list_maps *info_map)
{
	int	j;

	j = 0;
	if (!first_fast_line_maps(tab_map[j], composee[1]))
		return (false);
	while (tab_map[j])
	{
		if (!medum_tab_map(tab_map[j], composee))
			return (false);
		if ((int)strlen(tab_map[j] ) != info_map->len)
		{
			ft_printf("error size map\n");
			return (false);
		}
		j++;
	}
	if (!first_fast_line_maps(tab_map[--j], composee[1]))
		return (false);
	return (true);
}

bool	verif_composee(char **tab_map, char *composee, t_list_maps *info_map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tab_map[j])
	{
		while (tab_map[j][i])
		{
			if (tab_map[j][i] == composee[4])
				info_map->P++;
			else if (tab_map[j][i] == composee[3])
				info_map->E++;
			else if (tab_map[j][i] == composee[2])
				info_map->C++;
			i++;
		}
		i = 0;
		j++;
	}
	info_map->lenght = j;
	return (print_error_comp(info_map));
}
