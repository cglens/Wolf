/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:06:18 by cglens            #+#    #+#             */
/*   Updated: 2016/11/16 14:39:11 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ext(void)
{
	exit(0);
	return (0);
}

int		ft_go_move(t_tamere *e)
{
	if (e->move.up)
		ft_move_up(e);
	if (e->move.down)
		ft_move_down(e);
	if (e->move.right)
		ft_move_right(e);
	if (e->move.left)
		ft_move_left(e);
	wolf(e);
	mlx_put_image_to_window(e->gr.mlx, e->gr.win, e->gr.img, 0, 0);
	return (0);
}

void	ft_key_value(int key, t_tamere *e)
{
	if (key == 13 || key == 126)
		e->move.up = !e->move.up;
	else if (key == 1 || key == 125)
		e->move.down = !e->move.down;
	else if (key == 2 || key == 124)
		e->move.right = !e->move.right;
	else if (key == 0 || key == 123)
		e->move.left = !e->move.left;
}

int		key_press(int key, t_tamere *e)
{
	if (key == 49 && e->move.tmp_speed == 0)
	{
		e->move.move_speed *= 2;
		e->move.tmp_speed++;
	}
	else if (key == 49 && e->move.tmp_speed == 1)
	{
		e->move.move_speed /= 2;
		e->move.tmp_speed--;
	}
	ft_key_value(key, e);
	return (0);
}

int		key_event(int key, t_tamere *e)
{
	printf("key : %d\n", key);
	if (key == 53)
		exit(0);
	else
		ft_key_value(key, e);
	return (0);
}
