/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:38:23 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/03 21:38:50 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
