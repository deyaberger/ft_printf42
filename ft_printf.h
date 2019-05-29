/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:04:24 by dberger           #+#    #+#             */
/*   Updated: 2019/05/29 12:16:06 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include "./libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

# define BUFF_SIZE 550

# define F_SPACE	(1 << 0)
# define F_HASH		(1 << 1)
# define F_MINUS	(1 << 2)
# define F_PLUS		(1 << 3)
# define F_ZERO		(1 << 4)
# define F_POINT	(1 << 5)

# define M_HH		(1 << 0)
# define M_H		(1 << 1)
# define M_L		(1 << 2)
# define M_BIGL		(1 << 3)
# define M_LL		(1 << 4)

typedef struct		s_printf
{
	int				flags;
	int				width;
	int				precision;
	int				modif;
	int				index;
	int				ret;
	char			buf[BUFF_SIZE + 1];
}					t_printf;

t_printf			ft_check_add(t_printf save, int *j, char c);
int					ft_printf(const char *restrict format, ...);
t_printf			ft_convert(t_printf save, char *str, int *i, int *s);
t_printf			ft_lltoa(t_printf save, int *j, long long type);
t_printf			ft_otoa(t_printf save, int *j, long long type);
t_printf			ft_dtoh(t_printf save, int *j, unsigned long int k, int i);
t_printf			ft_format_di(t_printf save, va_list ap, int *j);
t_printf			ft_format_csp(t_printf save, va_list ap, int *j, char c);
t_printf			ft_format_xx(t_printf save, va_list ap, int *j, char c);
t_printf			ft_format_f(t_printf save, va_list ap, int *j);
t_printf			ft_format_u(t_printf save, va_list ap, int *j);
t_printf			ft_format_o(t_printf save, va_list ap, int *j);
t_printf			ft_format_pct(t_printf save, int *j);
t_printf			ft_format_b(t_printf save, va_list ap, int *j);

#endif
