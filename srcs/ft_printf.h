/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:39:59 by aldubar           #+#    #+#             */
/*   Updated: 2020/12/08 15:11:58 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flag
{
	int		left;
	int		zero;
	int		width;
	int		precision;
	int		upper;
}				t_flag;

int				ft_printf(const char *s, ...);
size_t			check_conversion(va_list param, t_flag *flags, char c);
size_t			print_c(char c, t_flag *flags);
size_t			print_s(const char *s, t_flag *flags);
size_t			print_d(int nb, t_flag *flags);
size_t			print_p(long p, t_flag *flags);
size_t			print_u(unsigned int u, t_flag *flags);
size_t			print_x(unsigned int x, t_flag *flags);
size_t			ft_putc(char c);
size_t			ft_putnc(char c, int n);
size_t			ft_putnstr(char *str, size_t n);

#endif
