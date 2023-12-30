/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:40:20 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/30 14:26:46 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**generated_tab_for_map(char **argv)
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
		ft_printf("error the file <%s> is empty", argv[1]);
		exit (1);
	}
	tab_map_return = ft_split(on_line_for_tab, '\n');
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
