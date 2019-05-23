/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:17:49 by dberger           #+#    #+#             */
/*   Updated: 2019/05/22 18:10:59 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	ft_width_di(t_printf save, int *j, long long type)
{
	int			count;
	long long	s;
	int			w;

	w = save.width;
	s = ft_sizenb_ll(type);
	count = w - s;
	if (save.precision && w > save.precision && s < save.precision)
		count = w - save.precision;
	if (save.precision && s < save.precision && w < save.precision)
		return (save);
	if ((save.flags & F_PLUS && type > 0) || type < 0)
		count--;
	if (type > 0 && (save.flags & F_SPACE))
		count--;
	if ((save.flags & F_ZERO) && !(save.precision) && !(save.flags & F_MINUS))
	{
		while (s < w && (count--) > 0)
			save = ft_check_add(save, j, '0');
		return (save);
	}
	while (s < w && (count--) > 0)
		save = ft_check_add(save, j, ' ');
	return (save);
}

t_printf	ft_precision_di(t_printf save, int *j, long long type)
{
	long long	s;
	int			p;

	s = ft_sizenb_ll(type);
	p = save.precision;
	if (type > 0 && (save.flags & F_PLUS))
		save = ft_check_add(save, j, '+');
	if (type < 0)
	{
		save = ft_check_add(save, j, '-');
		type = -type;
		s--;
	}
	if (s < p)
	{
		while (p - s > 0)
		{
			save = ft_check_add(save, j, '0');
			p--;
		}
	}
	return (save);
}

long long	ft_modif_di(t_printf save, va_list ap)
{
	long long	number;

	if (save.modif && (save.modif & M_HH))
		return (number = (char)va_arg(ap, int));
	if (save.modif && (save.modif & M_H))
		return (number = (short)va_arg(ap, int));
	if (save.modif && (save.modif & M_L))
		return (number = va_arg(ap, long));
	if (save.modif && (save.modif & M_LL))
		return (number = va_arg(ap, long long));
	return (number = va_arg(ap, int));
}

t_printf	ft_format_di(t_printf save, va_list ap, int *j)
{
	long long	type;

	type = ft_modif_di(save, ap);
	if (type > 0 && (save.flags & F_SPACE))
		save = ft_check_add(save, j, ' ');
	if (save.width && !(save.flags & F_MINUS))
		save = ft_width_di(save, j, type);
	if (save.precision)
		save = ft_precision_di(save, j, type);
	save = ft_lltoa(save, j, type);
	if (save.width && (save.flags & F_MINUS))
		save = ft_width_di(save, j, type);
	return (save);
}
