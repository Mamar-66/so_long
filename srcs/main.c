/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:21:14 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/28 14:40:27 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	return (1);
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