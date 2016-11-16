/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorielle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:43:02 by cglens            #+#    #+#             */
/*   Updated: 2016/11/16 14:43:04 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorielle(int nb)
{
	int		i;
	int		n;

	i = 0;
	n = 1;
	if (nb < 0)
		return (0);
	while (++i <= nb)
		n = n * i;
	return (n);
}
