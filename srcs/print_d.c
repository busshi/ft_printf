/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:07:07 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/08 15:10:20 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_putnnbr(long nb, size_t *len)
{
	int	c;

	if (nb < 0)
		nb = -nb;
	if (nb < 10)
	{
		c = nb + '0';
		(*len) += ft_putc(c);
	}
	else
	{
		ft_putnnbr(nb / 10, len);
		ft_putnnbr(nb % 10, len);
	}
	return (*len);
}

static size_t	count_len_d(int nb)
{
	size_t			i;
	unsigned int	n;

	i = 1;
	n = nb;
	if (nb < 0)
		n = -nb;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static size_t	check_before(int d, t_flag *flags, size_t len_nb, size_t max)
{
	size_t	len;

	len = 0;
	if (!flags->left && (!flags->zero || flags->precision != -1))
		len += ft_putnc(' ', flags->width - (int)max);
	if (d < 0)
		len += ft_putc('-');
	if (flags->zero && flags->precision == -1)
		len += ft_putnc('0', flags->width - (int)max);
	if (flags->precision > (int)len_nb && flags->precision != -1)
		len += ft_putnc('0', flags->precision - (int)len_nb);
	return (len);
}

static size_t	check_after(t_flag *flags, size_t max)
{
	size_t	len;

	len = 0;
	if (flags->left)
		len += ft_putnc(' ', flags->width - (int)max);
	return (len);
}

size_t			print_d(int d, t_flag *flags)
{
	size_t	len;
	size_t	len2;
	size_t	len_nb;
	size_t	max;

	len = 0;
	if (d < 0)
		flags->width--;
	len_nb = count_len_d(d);
	if ((int)len_nb < flags->precision)
		max = flags->precision;
	else
		max = len_nb;
	if (flags->precision == 0 && d == 0)
	{
		len += ft_putnc(' ', flags->width);
		return (len);
	}
	len += check_before(d, flags, len_nb, max);
	len2 = 0;
	ft_putnnbr(d, &len2);
	len += check_after(flags, max);
	return (len + len2);
}
