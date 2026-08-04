/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsevind <emsevind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 00:30:00 by emsevind          #+#    #+#             */
/*   Updated: 2026/08/05 00:30:00 by emsevind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static void	test_limits(void)
{
	printf("printf   : %d %d %u %x %X\n", INT_MIN, INT_MAX, UINT_MAX,
		UINT_MAX, UINT_MAX);
	ft_printf("ft_printf: %d %d %u %x %X\n", INT_MIN, INT_MAX, UINT_MAX,
		UINT_MAX, UINT_MAX);
}

int	main(void)
{
	int	standard;
	int	custom;
	int	value;

	setbuf(stdout, NULL);
	value = 42;
	standard = printf("printf   : %c %s %p %d %i %u %x %X %%\n",
			'A', "Hello", &value, -42, 42, 42U, 255U, 255U);
	custom = ft_printf("ft_printf: %c %s %p %d %i %u %x %X %%\n",
			'A', "Hello", &value, -42, 42, 42U, 255U, 255U);
	printf("return values: %d / %d\n", standard, custom);
	test_limits();
	return (0);
}
