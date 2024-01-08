/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_comp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:57:49 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/06 18:07:34 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	print_error_comp(t_list_maps *info_map)
{
	if (info_map->p != 1)
	{
		ft_printf("error there are \"%d\" starting position\n", info_map->p);
		return (false);
	}
	if (info_map->e != 1)
	{
		ft_printf("error there are \"%d\" output positions\n", info_map->e);
		return (false);
	}
	if (info_map->c == 0)
	{
		ft_printf("error there are \"%d\" item\n", info_map->c);
		return (false);
	}
	return (true);
}
