/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:07:07 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/07 17:49:35 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putc(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putnc(char c, int n)
{
	int	len;

	len = 0;
	while (len < n)
		len += ft_putc(c);
	return (len);
}

size_t	print_c(char c, t_flag *flags)
{
	size_t	len;
	size_t	width;

	len = 0;
	width = flags->width;
	if (flags->left)
	{
		len += ft_putc(c);
		len += ft_putnc(' ', width - 1);
	}
	else
	{
		if (!flags->zero)
			len += ft_putnc(' ', width - 1);
		else
			len += ft_putnc('0', width - 1);
		len += ft_putc(c);
	}
	return (len);
}
