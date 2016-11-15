/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:15:18 by cglens            #+#    #+#             */
/*   Updated: 2016/11/15 13:16:59 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_graph(t_tamere *e)
{
	e->gr.mlx = mlx_init();
	e->gr.win = mlx_new_window(e->gr.mlx, W, H, "qwer");
	e->gr.bpp = 0;
	e->gr.sizeline = 0;
	e->gr.img = mlx_new_image(e->gr.mlx, W, H);
	e->gr.data = mlx_get_data_addr(e->gr.img, &e->gr.bpp,
			&e->gr.sizeline, &e->gr.endian);
}

void	init_move(t_tamere *e)
{
	e->move.up = 0;
	e->move.down = 0;
	e->move.right = 0;
	e->move.left = 0;
	e->move.move_speed = 0.05;
	e->move.tmp_speed = 0;
	e->move.rot_speed = 0.05;
}

void	init_e(t_tamere *e)
{
	init_move(e);
	init_graph(e);
	e->lig = 0;
	e->col = 0;
	e->pos_x = 5;
	e->pos_y = 5;
	e->dir_x = -1;
	e->dir_y = 0;
	e->rc.plane_x = 0;
	e->rc.plane_y = 0.66;
}
