/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:40:20 by omfelk            #+#    #+#             */
/*   Updated: 2024/01/08 13:15:20 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**generated_tab_for_map(char **argv, t_list_mlx *lst_mlx)
{
	char	**tab_map_return;
	char	*on_line_for_tab;
	int		key_map;

	key_map = open(argv[1], O_RDONLY);
	if (key_map == -1)
	{
		ft_printf("error the file <%s> does not exist\n", argv[1]);
		exit (1);
	}
	on_line_for_tab = on_a_line(key_map);
	if (!on_line_for_tab)
	{
		ft_printf("error the file <%s> is empty\n", argv[1]);
		exit (1);
	}
	tab_map_return = ft_split(on_line_for_tab, '\n');
	if (!composee_caract(tab_map_return, COMPOSEE_MAP, lst_mlx))
	{
		free_tab_map(tab_map_return);
		tab_map_return = NULL;
	}
	free(on_line_for_tab);
	close(key_map);
	return (tab_map_return);
}

char	*on_a_line(int fd)
{
	char	*line_return;
	char	*buff;

	line_return = get_next_line(fd);
	buff = get_next_line(fd);
	while (buff)
	{
		line_return = ft_strjoin(line_return, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	return (line_return);
}
