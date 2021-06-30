/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:07:07 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/07 17:57:25 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_putxnbr(long n, size_t *len, t_flag *flags)
{
	int	c;

	c = 'a';
	if (flags->upper)
		c = 'A';
	if (n >= 16)
		ft_putxnbr(n / 16, len, flags);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += c - 10;
	*len += ft_putc(n);
	return (*len);
}

static size_t	count_len_x(unsigned int n, unsigned int base)
{
	size_t		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

static size_t	check_before(t_flag *flags, size_t len_nb, size_t max)
{
	size_t	len;

	len = 0;
	if (!flags->left && (!flags->zero || flags->precision != -1))
		len += ft_putnc(' ', flags->width - (int)max);
	if (flags->zero && flags->precision == -1)
		len += ft_putnc('0', flags->width - (int)max);
	if (flags->precision > (int)len_nb)
		len += ft_putnc('0', flags->precision - (int)len_nb);
	return (len);
}

size_t			print_x(unsigned int x, t_flag *flags)
{
	size_t	len;
	size_t	len2;
	size_t	max;

	len = 0;
	if (x < 0)
		flags->width--;
	if ((int)count_len_x(x, 16) < flags->precision)
		max = flags->precision;
	else
		max = count_len_x(x, 16);
	if (flags->precision == 0 && x == 0)
	{
		len += ft_putnc(' ', flags->width);
		return (len);
	}
	len += check_before(flags, count_len_x(x, 16), max);
	len2 = 0;
	ft_putxnbr(x, &len2, flags);
	if (flags->left)
		len += ft_putnc(' ', flags->width - (int)max);
	return (len + len2);
}
