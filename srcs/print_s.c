/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:07:07 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/08 14:49:39 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnstr(char *s, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] && i < n)
	{
		len += ft_putc(s[i]);
		i++;
	}
	return (len);
}

size_t	ft_puts(char *s, size_t max, int precision)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (precision == 0)
	{
		len += ft_putnc(' ', max);
		return (len);
	}
	else if (precision > 0)
	{
		while (s[i] && (int)i < precision)
		{
			len += ft_putc(s[i]);
			i++;
		}
		return (len);
	}
	while (s[i])
	{
		len += ft_putc(s[i]);
		i++;
	}
	return (len);
}

size_t	fill_or_not(char const *s, t_flag *flags, size_t max)
{
	size_t	len;
	size_t	width;

	len = 0;
	width = flags->width;
	if (flags->left)
	{
		len += ft_puts((char *)s, max, flags->precision);
		len += ft_putnc(' ', width - max);
	}
	else
	{
		if (!flags->zero)
			len += ft_putnc(' ', width - max);
		else
			len += ft_putnc('0', width - max);
		len += ft_puts((char *)s, max, flags->precision);
	}
	return (len);
}

size_t	print_s(char const *s, t_flag *flags)
{
	size_t	max;
	int		precision;

	if (!s)
		s = "(null)";
	max = ft_strlen(s);
	precision = flags->precision;
	if (precision < (int)max && precision != -1)
		max = (size_t)precision;
	return (fill_or_not(s, flags, max));
}
