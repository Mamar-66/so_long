/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_output_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:51:33 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/03 12:18:35 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	chr_output_valid(char **tab_map)
{
	tab_map[0][0] = 'p';
	affichetab(tab_map);
	free_tab_map(tab_map);
	return (true);
}

char	**dup_tab(char **tab_src)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab_src[i])
		i++;
	new_tab = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (tab_src[i])
	{
		new_tab[i] = ft_strdup(tab_src[i]);
		i++;
	}
	return (new_tab);
}
