/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:06:18 by cglens            #+#    #+#             */
/*   Updated: 2016/11/16 14:39:25 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_move_up(t_tamere *e)
{
	if (!(e->world_map[(int)(e->pos_x + e->dir_x *
					e->move.move_speed)][(int)e->pos_y]))
		e->pos_x += e->dir_x * e->move.move_speed;
	if (!(e->world_map[(int)(e->pos_x)][(int)(e->pos_y + e->dir_y *
					e->move.move_speed)]))
		e->pos_y += e->dir_y * e->move.move_speed;
}

void	ft_move_down(t_tamere *e)
{
	if (!(e->world_map[(int)(e->pos_x - e->dir_x *
					e->move.move_speed)][(int)e->pos_y]))
		e->pos_x -= e->dir_x * e->move.move_speed;
	if (!(e->world_map[(int)(e->pos_x)][(int)(e->pos_y - e->dir_y *
					e->move.move_speed)]))
		e->pos_y -= e->dir_y * e->move.move_speed;
}

void	ft_move_right(t_tamere *e)
{
	e->old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(-e->move.rot_speed) - e->dir_y *
		sin(-e->move.rot_speed);
	e->dir_y = e->old_dir_x * sin(-e->move.rot_speed) + e->dir_y *
		cos(-e->move.rot_speed);
	e->rc.plane_x = e->rc.plane_x;
	e->rc.plane_x = e->rc.plane_x * cos(-e->move.rot_speed) -
		e->rc.plane_y * sin(-e->move.rot_speed);
	e->rc.plane_y = e->rc.plane_x * sin(-e->move.rot_speed) +
		e->rc.plane_y * cos(-e->move.rot_speed);
}

void	ft_move_left(t_tamere *e)
{
	e->old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(e->move.rot_speed) - e->dir_y *
		sin(e->move.rot_speed);
	e->dir_y = e->old_dir_x * sin(e->move.rot_speed) + e->dir_y *
		cos(e->move.rot_speed);
	e->rc.plane_x = e->rc.plane_x;
	e->rc.plane_x = e->rc.plane_x * cos(e->move.rot_speed) -
		e->rc.plane_y * sin(e->move.rot_speed);
	e->rc.plane_y = e->rc.plane_x * sin(e->move.rot_speed) +
		e->rc.plane_y * cos(e->move.rot_speed);
}
