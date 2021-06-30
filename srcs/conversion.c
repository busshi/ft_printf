/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:35:08 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/08 13:49:10 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_conversion(va_list param, t_flag *flags, char c)
{
	size_t	res;

	res = 0;
	if (c == 'c')
		res += print_c((char)va_arg(param, int), flags);
	else if (c == 's')
		res += print_s((char *)va_arg(param, char *), flags);
	else if (c == 'd' || c == 'i')
		res += print_d((int)va_arg(param, int), flags);
	else if (c == 'p')
		res += print_p((long)va_arg(param, long), flags);
	else if (c == 'u')
		res += print_u((unsigned int)va_arg(param, unsigned int), flags);
	else if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			flags->upper = 1;
		res += print_x((unsigned int)va_arg(param, unsigned int), flags);
	}
	else if (c == '%')
		res += print_c('%', flags);
	return (res);
}
