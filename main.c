/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:50:43 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/23 23:13:24 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>

void	check(int mine, int real)
{
	printf("\e[0;33m[ %d - %d ]\e[0;m", mine, real);
	if (mine == real)
		printf("\t\t\t\t\t\t\t\t\t\e[1;32m[ OK ]\e[0;m\n\n");
	else
		printf("\t\t\t\t\t\t\t\t\t\e[1;31m[ KO ]\e[0;m\n\n");
}

int	main(void)
{
	int	mine;
	int	real;

	ft_printf("_____________________________________\n______________ c / i ______________\n");
        mine = ft_printf("ft_printf d.: %.2d %.2d %.2d %.2d %.2d %.3d %d %.20d\n", 2147483647, 421, -0, -421, +421, 0, -2147483648, 0);
        real = printf("___printf d.: %.2d %.2d %.2d %.2d %.2d %.3d %ld %.20d\n", 2147483647, 421, -0, -421, +421, 0, -2147483648, 0);
        check(mine, real);

        mine = ft_printf("ft_printf d\" \": % d % d % d % d % d\n", 2147483647, 421, 0, -421, +421);
        real = printf("___printf d\" \": % d % d % d % d % d\n", 2147483647, 421, 0, -421, +421);
        check(mine, real);

	mine = ft_printf("ft_printf *: %*d 42 %d %-*d|%*d|\n", 3, 42, -42, 4, 50, 4, 51);
        real = printf("___printf *: %*d 42 %d %-*d|%*d|\n", 3, 42, -42, 4, 50, 4, 51);
        check(mine, real);

      	mine = ft_printf("ft_printf d.-: %10.d | %-10.d | %.5d | %.10d | %5.10d | %-.2d |\n", 42, 42, 42, -42, 42, -42);
        real = printf("___printf d.-: %10.d | %-10.d | %.5d | %.10d | %5.10d | %-.2d |\n", 42, 42, 42, -42, 42, -42);
        check(mine,  real);

        mine = ft_printf("ft_printf d.-: %10.d | %-10.d | %10.d | %-10.d |\n", -42, -42, 0, 0);
        real = printf("___printf d.-: %10.d | %-10.d | %10.d | %-10.d |\n", -42, -42, 0, 0);
        check(mine, real);

        mine = ft_printf("ft_printf .*d: %10.*d| %10.*d | %10.*d | %10.*d |\n", -10, 42, 10, -43, -10, 0, 0, 0);
        real = printf("___printf .*d: %10.*d| %10.*d | %10.*d | %10.*d |\n", -10, 42, 10, -43, -10, 0, 0, 0);
        mine = ft_printf("ft_printf d.: %.2d %.2d %.2d %.2d %.2d %.3d %d %.20d\n", 2147483647, 421, -0, -421, +421, 0, -2147483648, 0);
        real = printf("___printf d.: %.2d %.2d %.2d %.2d %.2d %.3d %ld %.20d\n", 2147483647, 421, -0, -421, +421, 0, -2147483648, 0);
        check(mine, real);

        mine = ft_printf("ft_printf d\" \": % d % d % d % d % d\n", 2147483647, 421, 0, -421, +421);
        real = printf("___printf d\" \": % d % d % d % d % d\n", 2147483647, 421, 0, -421, +421);
        check(mine, real);

 	mine = ft_printf("ft_printf i: %i %i\n", -2147483648, 2147483647);
        real = printf("___printf i: %li %i\n", -2147483648, 2147483647);
        check(mine, real);

        mine = ft_printf("ft_printf d: %d %d\n", -2147483648, 2147483647);
        real = printf("___printf d: %ld %d\n", -2147483648, 2147483647);
        check(mine, real);


	ft_printf("__________________________________\n________________ u ________________\n");  
        mine = ft_printf("ft_printf u: %u %u %u %u\n", 214748364, 2147483647, 214748364, 0);
        real = printf("___printf u: %u %u %u %u\n", 214748364, 2147483647, 214748364, 0);
        check(mine, real);

	mine = ft_printf("ft_printf u.15: %.u, %.ud %.15u %u %u\n", 0, 42, 42365478, 1, 0);
        real = printf("___printf u.15: %.u, %.ud %.15u %u %u\n", 0, 42, 42365478, 1, 0);
        check(mine, real);
	
	mine = ft_printf("ft_printf u.15: %.u, %.ud %.15u %u %u\n", 0, 42, 42365478, 1, 0);
        real = printf("___printf u.15: %.u, %.ud %.15u %u %u\n", 0, 42, 42365478, 1, 0);
        check(mine, real);

	ft_printf("__________________________________\n________________ p / x ________________\n");
	mine = ft_printf("ft_printf xp: %x %p\n", (long)"holà", "holà");
	real = printf("___printf xp: %lx %p\n", (long)"holà", "holà");
	check(mine, real);

	mine = ft_printf("ft_printf p: %p %p\n", "NULL", "");
	real = printf("___printf p: %p %p\n", "NULL", "");
	check(mine, real);
	
	mine = ft_printf("ft_printf Xp: %X %p\n", (long)"bonjour", "bonjour");
	real = printf("___printf Xp: %lX %p\n", (long)"bonjour", "bonjour");
	check(mine, real);

	mine = ft_printf("ft_printf p.: %.p, %.pd %p %p %p\n", "hello", "hi", "abcde", "", "1000");
        real = printf("___printf p.: %.p, %.pd %p %p %p\n", "hello", "hi", "abcde", "", "1000");
        check(mine, real);

       	mine = ft_printf("ft_printf (nil/null): %p ça va ?  😎 😵 %s\n", NULL, NULL);
        real = printf("___printf (nil/null): %p ça va ?  😎 😵 %s\n", NULL, NULL);
        check(mine, real);

        mine = ft_printf("ft_printf xX.15: %.x, %.Xd %.15x %.15X %.5x %.2x# %#.2X\n", 'a', 'c', -5646, 1000, 0, 42, 42);
        real = printf("___printf xX.15: %.x, %.Xd %.15x %.15X %.5x %.2x# %#.2X\n", 'a', 'c', -5646, 1000, 0, 42, 42);
        check(mine, real);

        mine = ft_printf("ft_printf #xX: %#x %#X %.5x %.2X %#x %.2x\n", 2147483647, 0, 0, -421, +0, 0);
        real = printf("___printf #xX: %#x %#X %.5x %.2X %#x %.2x\n", 2147483647, 0, 0, -421, +0, 0);
	check(mine, real);

	ft_printf("__________________________________\n________________ + ________________\n");
	mine = ft_printf("ft_printf d+: %+d %+d %+d %+d %+d\n", 2147483647, 42, 0, -42, +42);
        real = printf("___printf d+: %+d %+d %+d %+d %+d\n", 2147483647, 42, 0, -42, +42);
	check(mine, real);

	ft_printf("__________________________________\n________________ s ________________\n");
	mine = ft_printf("ft_printf s.: %s coucou coucou %.2s holà holà %% %s\n", "", "weshwesh", "0123456789");
	real = printf("___printf s.: %s coucou coucou %.2s holà holà %% %s\n", "", "weshwesh", "0123456789");
	check(mine, real);

        ft_printf("____________________________________\n________________ csd ________________\n");
	mine = ft_printf("ft_printf csd: %d A %% p %c coucou %c %c %s\n", 0, '@', 'd', 'e', "hello coucou !%");
        real = printf("___printf csd: %d A %% p %c coucou %c %c %s\n", 0, '@', 'd', 'e', "hello coucou !%");
        check(mine, real);

	mine = ft_printf("ft_printf sdc.15: %.c, %.cd %.15s %.15d %.2d % .%w\n", 'a', 'c', "abcde", 1000, 0);
	real = printf("___printf sdc.15: %.c, %.cd %.15s %.15d %.2d % .%w\n", 'a', 'c', "abcde", 1000, 0);
	check(mine, real);

	mine = ft_printf("ft_printf csd_0: c->%c%c%c d->%d s->%s%c%c\n", '\x00', '\x05', '\x10', '\x00', "holà\x00coucou", '!', '@');
	real = printf("___printf csd_0: c->%c%c%c d->%d s->%s%c%c\n", '\x00', '\x05', '\x10', '\x00', "holà\x00coucou", '!', '@');
	check(mine, real);
	
	mine = ft_printf("ft_printf s.-: %.s %s %.s %-.2s\n", "holà", NULL, NULL, "null");
     	real = printf("___printf s.-: %.s %s %.s %-.2s\n", "holà", NULL, NULL, "null");
        check(mine,  real);

//	mine = ft_printf("%0*.1p|%x|%X|\n", 12, "NULL", 100, 100);
//	real = printf("%0*.1p|%x|%X|\n", 12, "NULL", 100, 100);
//	check(mine, real);

	mine = ft_printf("ft_printf : %c %c\n", 0, -0);
	real = printf("___printf : %c %c\n", 0, -0);
	check(mine, real);

	mine = ft_printf("ft_printf %%-8.3i: %-8.3i\n", 8375);
	real = printf("___printf %%-8.3i: %-8.3i\n", 8375);
	check(mine, real);

    	mine = ft_printf("ft_printf %%03i: %03i\n", 0);
        real = printf("___printf %%03i: %03i\n", 0);
        check(mine, real);

	mine = ft_printf("ft_printf %%.03s: %.03s\n", NULL);
	real = printf("___printf %%.03s: %.03s\n", NULL);
	check(mine, real);

      	mine = ft_printf("ft_printf %%3.1s: %3.1s\n", NULL);
        real = printf("___printf %%3.1s: %3.1s\n", NULL);
        check(mine, real);

    	mine = ft_printf("ft_printf %%9.1s: %9.1s\n", NULL);
        real = printf("___printf %%9.1s: %9.1s\n", NULL);
        check(mine, real);

        mine = ft_printf("ft_printf %%-3.1s: %-3.1s\n", NULL);
        real = printf("___printf %%-3.1s: %-3.1s\n", NULL);
        check(mine, real);

        mine = ft_printf("ft_printf %%-9.1s: %-9.1s\n", NULL);
        real = printf("___printf %%-9.1s: %-9.1s\n", NULL);
	check(mine, real);

        mine = ft_printf("ft_printf %%3.1s: %3.1s\n", NULL);
        real = printf("___printf %%3.1s: %3.1s\n", NULL);
        check(mine, real);

        mine = ft_printf("ft_printf %%3s: %3s %-3s %3.s %-3.s %.s\n", NULL, NULL, NULL, NULL, NULL);
        real = printf("___printf %%3s: %3s %-3s %3.s %-3.s %.s\n", NULL, NULL, NULL, NULL, NULL);
	check(mine, real);
      
	mine = ft_printf("ft_printf %%3.1s: %10.5s\n", NULL);
        real = printf("%10.5s\n", NULL);
        check(mine, real);
/*
	mine = ft_printf("%");
	printf("\n");
	real = printf("%");
	check(mine, real);
*/
	return (0);
}	
