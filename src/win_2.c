/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win2_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:49:39 by cglens            #+#    #+#             */
/*   Updated: 2016/11/15 13:56:27 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_2(int key, t_tamere *e)
{
	if (key == 53)
		mlx_destroy_window(e->gr.mlx_2, e->gr.win_2);
	return (0);
}

void	ft_win_2(t_tamere *e)
{
	e->gr.mlx_2 = mlx_init();
	e->gr.win_2 = mlx_new_window(e->gr.mlx_2, 250, 250, "Help");
	mlx_string_put(e->gr.mlx_2, e->gr.win_2, 20, 50, 0x00ff00,
			"w / s / a / d  = move");
	mlx_string_put(e->gr.mlx_2, e->gr.win_2, 20, 100, 0x00ff00,
			"fleches = move");
	mlx_string_put(e->gr.mlx_2, e->gr.win_2, 20, 150, 0x00ff00,
			"ESC = exit");
	mlx_string_put(e->gr.mlx_2, e->gr.win_2, 20, 200, 0x00ff00,
			"SPACE = speed +/-");
	mlx_key_hook(e->gr.win_2, key_2, e);
	mlx_loop(e->gr.mlx_2);
}
