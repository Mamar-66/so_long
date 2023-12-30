/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:21:14 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/30 14:27:12 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map_tab;

	if (argc < 2)
		return (ft_printf("error %d argument\n", argc));
	map_tab = generated_tab_for_map(argv);
	affichetab(map_tab);
	free_tab_map(map_tab);
	return (1);
}

void	affichetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

void	free_tab_map(char **tab_map)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		free(tab_map[i]);
		i++;
	}
	free(tab_map);
}

/* int	function(int keycode, void *param)
{
	(void)param;
	printf("code clavier est %d keycode\n", keycode);
	if (keycode == 65307)
		exit(1);
	return (1);
} */

/* 	void	*ptr_mlx;
	void	*win_mlx;
	void	*img;
	int		x;
	int		y;

	x = 20;
	y = 20;

	(void)argc;
	(void)argv;
	ptr_mlx = mlx_init();
	if (!ptr_mlx)
		return (0);
	win_mlx = mlx_new_window(ptr_mlx, 600, 600, "so_long");
	mlx_key_hook(win_mlx, function, NULL);
	mlx_mouse_hook(win_mlx, function, NULL);
	img = mlx_xpm_file_to_image(ptr_mlx, "images/test.xpm", &x, &y);
	mlx_put_image_to_window(ptr_mlx, win_mlx, img, 20, 20);
	mlx_loop(ptr_mlx); */