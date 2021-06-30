/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:48:23 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/08 13:32:42 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		get_precision(va_list param, t_flag *flags, const char *str)
{
	size_t	i;

	i = 1;
	if (str[i] == '*')
	{
		flags->precision = (int)va_arg(param, int);
		if (flags->precision < 0)
			flags->precision = -1;
		i++;
		return (i);
	}
	else if (ft_isdigit(str[i]))
	{
		flags->precision = ft_atoi(&str[i]);
		if (flags->precision < 0)
			flags->precision = -1;
	}
	else
		flags->precision = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static size_t		get_width(va_list param, t_flag *flags, const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '*')
	{
		flags->width = (int)va_arg(param, int);
		if (flags->width < 0)
		{
			flags->width = -flags->width;
			flags->left = 1;
			flags->zero = 0;
		}
		i++;
		return (i);
	}
	else
		flags->width = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static size_t		check_flags(va_list param, t_flag *flags, const char *str)
{
	size_t	i;

	i = 1;
	while (str[i] && ft_strchr("0123456789.*-", str[i]))
	{
		if (str[i] == '0' && !flags->left)
		{
			flags->zero = 1;
			i++;
		}
		else if (str[i] == '-')
		{
			flags->zero = 0;
			flags->left = 1;
			i++;
		}
		else if (str[i] == '*' || ft_isdigit(str[i]))
			i += get_width(param, flags, &str[i]);
		else if (str[i] == '.')
			i += get_precision(param, flags, &str[i]);
	}
	return (i);
}

static t_flag		*init_flags(void)
{
	t_flag	*flags;

	flags = (t_flag *)malloc(sizeof(t_flag));
	if (!flags)
		return (NULL);
	flags->left = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->upper = 0;
	return (flags);
}

int					ft_printf(const char *str, ...)
{
	size_t	res;
	size_t	i;
	t_flag	*flags;
	va_list	param;

	i = 0;
	res = 0;
	va_start(param, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			flags = init_flags();
			i += check_flags(param, flags, &str[i]);
			res += check_conversion(param, flags, str[i]);
			free(flags);
		}
		else
			res += ft_putc(str[i]);
		if (str[i])
			i++;
	}
	va_end(param);
	return (res);
}
