/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:21:14 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/26 11:38:46 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	void	*ptr_mlx;
	// void	*win_mlx;

	(void)argc;
	(void)argv;
	ptr_mlx = mlx_init();
	if (!ptr_mlx)
		return (0);
	/* win_mlx =  */mlx_new_window(ptr_mlx, 400, 400, "so_long");
	mlx_loop(ptr_mlx);
	printf("hello word\n");
	return (1);
}
