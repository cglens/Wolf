/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:12:36 by cglens            #+#    #+#             */
/*   Updated: 2016/11/15 12:25:45 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_wall(t_tamere *e)
{
	while (e->hit == 0)
	{
		if (e->rc.side_dist_x < e->rc.side_dist_y)
		{
			e->rc.side_dist_x += e->rc.delta_dist_x;
			e->move.map_x += e->rc.step_x;
			e->side = 0;
		}
		else
		{
			e->rc.side_dist_y += e->rc.delta_dist_y;
			e->move.map_y += e->rc.step_y;
			e->side = 1;
		}
		if (e->world_map[e->move.map_x][e->move.map_y] > 0)
		{
			e->hit = 1;
			if (e->side == 0)
				e->rc.wall_dist = (e->move.map_x - e->rc.ray_pos_x +
						(1 - e->rc.step_x) / 2) / e->rc.ray_dir_x;
			else
				e->rc.wall_dist = (e->move.map_y - e->rc.ray_pos_y +
						(1 - e->rc.step_y) / 2) / e->rc.ray_dir_y;
		}
	}
}

void	ft_ray_lenght(t_tamere *e)
{
	if (e->rc.ray_dir_x < 0)
	{
		e->rc.step_x = -1;
		e->rc.side_dist_x = (e->rc.ray_pos_x - e->move.map_x)
			* e->rc.delta_dist_x;
	}
	else
	{
		e->rc.step_x = 1;
		e->rc.side_dist_x = (e->move.map_x + 1.0 - e->rc.ray_pos_x)
			* e->rc.delta_dist_x;
	}
	if (e->rc.ray_dir_y < 0)
	{
		e->rc.step_y = -1;
		e->rc.side_dist_y = (e->rc.ray_pos_y - e->move.map_y)
			* e->rc.delta_dist_y;
	}
	else
	{
		e->rc.step_y = 1;
		e->rc.side_dist_y = (e->move.map_y + 1.0 - e->rc.ray_pos_y)
			* e->rc.delta_dist_y;
	}
	ft_wall(e);
}

void	ft_ray_init(t_tamere *e, int x)
{
	e->move.camera = 2 * x / (double)W - 1;
	e->rc.ray_pos_x = e->pos_x;
	e->rc.ray_pos_y = e->pos_y;
	e->rc.ray_dir_x = e->dir_x + e->rc.plane_x * e->move.camera;
	e->rc.ray_dir_y = e->dir_y + e->rc.plane_y * e->move.camera;
	e->move.map_x = (int)e->rc.ray_pos_x;
	e->move.map_y = (int)e->rc.ray_pos_y;
	e->rc.delta_dist_x = sqrt(1 + (e->rc.ray_dir_y *
				e->rc.ray_dir_y) / (e->rc.ray_dir_x * e->rc.ray_dir_x));
	e->rc.delta_dist_y = sqrt(1 + (e->rc.ray_dir_x *
				e->rc.ray_dir_x) / (e->rc.ray_dir_y * e->rc.ray_dir_y));
	e->hit = 0;
	ft_ray_lenght(e);
}
