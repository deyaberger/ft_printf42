/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:47:27 by dberger           #+#    #+#             */
/*   Updated: 2019/06/17 18:52:24 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	ft_print_float(t_printf save, int *j, char *fix, char *nb)
{
	int		i;
	int		p;
	int		f;
	int		l;

	l = ft_strlen_l(fix);
	p = save.pre;
	i = 0;
	f = save.flags;
	if (fix[0] == '-' && (save.width) && (f & F_ZERO) && !(f & F_MINUS))
		i = 1;
	while (fix[i])
		save = ft_check_add(save, j, fix[i++]);
	i = 0;
	if ((!(save.pre) && !(f & F_POINT)) || (save.pre > 0) || (f & F_HASH))
	{
		if (!(save.pre) && !(f & F_POINT))
			p = 6;
		save = ft_check_add(save, j, '.');
		if ((!(save.pre) && !(f & F_POINT)) || (save.pre > 0))
			while (nb[i] && i < p)
				save = ft_check_add(save, j, nb[i++]);
	}
	return (save);
}