/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:07:07 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/08 14:38:14 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t			ft_putpnbr(long n, size_t *len)
{
	if (n >= 16)
		ft_putpnbr(n / 16, len);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += 'a' - 10;
	*len += ft_putc(n);
	return (*len);
}

static size_t			count_len_p(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static size_t			check_before(t_flag *flags, size_t len_nb, size_t max)
{
	size_t	len;

	len = 0;
	if (!flags->left && (!flags->zero || flags->precision != -1))
		len += ft_putnc(' ', flags->width - (int)max);
	len += ft_putnstr("0x", 2);
	if (flags->zero && flags->precision == -1)
		len += ft_putnc('0', flags->width - (int)max);
	if (flags->precision > (int)len_nb)
		len += ft_putnc('0', flags->precision - (int)len_nb);
	return (len);
}

static size_t			print_p_next(long p, t_flag *flags)
{
	size_t	max;
	size_t	len;
	size_t	len2;

	len = 0;
	max = count_len_p(p);
	if (max < 0)
		max = flags->precision;
	len += check_before(flags, count_len_p(p), max);
	len2 = 0;
	ft_putpnbr(p, &len2);
	if (flags->left)
		len += ft_putnc(' ', flags->width - max);
	return (len + len2);
}

size_t					print_p(long p, t_flag *flags)
{
	size_t	len;

	len = 0;
	flags->width -= 2;
	if (p == 0 && flags->precision == 0)
	{
		if (!flags->left)
		{
			len = ft_putnc(' ', flags->width);
			len += ft_putnstr("0x", 2);
		}
		else
		{
			len = ft_putnstr("0x", 2);
			len += ft_putnc(' ', flags->width);
		}
		return (len);
	}
	return (print_p_next(p, flags));
}
