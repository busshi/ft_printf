/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:07:07 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/07 17:52:16 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		count_len_u(unsigned int u)
{
	size_t	len;

	len = 1;
	while (u >= 10)
	{
		u /= 10;
		len++;
	}
	return (len);
}

static size_t		ft_putunbr(unsigned nb, size_t *len)
{
	int	c;

	if (nb < 10)
	{
		c = nb + '0';
		(*len) += ft_putc(c);
	}
	else
	{
		ft_putunbr(nb / 10, len);
		ft_putunbr(nb % 10, len);
	}
	return (*len);
}

static size_t		check_before(t_flag *flags, size_t len_nb, size_t max)
{
	size_t	len;

	len = 0;
	if (!flags->left && (!flags->zero || flags->precision != -1))
		len += ft_putnc(' ', flags->width - (int)max);
	if (flags->zero && flags->precision == -1)
		len += ft_putnc('0', flags->width - (int)max);
	if (flags->precision > (int)len_nb && flags->precision != -1)
		len += ft_putnc('0', flags->precision - (int)len_nb);
	return (len);
}

size_t				print_u(unsigned int u, t_flag *flags)
{
	size_t	len;
	size_t	len2;
	size_t	len_nb;
	size_t	max;

	len = 0;
	if (u < 0)
		flags->width--;
	len_nb = count_len_u(u);
	if ((int)len_nb < flags->precision)
		max = flags->precision;
	else
		max = len_nb;
	if (flags->precision == 0 && u == 0)
	{
		len += ft_putnc(' ', flags->width);
		return (len);
	}
	len += check_before(flags, len_nb, max);
	len2 = 0;
	ft_putunbr(u, &len2);
	if (flags->left)
		len += ft_putnc(' ', flags->width - (int)max);
	return (len + len2);
}
