/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsevind <emsevind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:57:03 by emsevind          #+#    #+#             */
/*   Updated: 2026/07/17 12:57:06 by emsevind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned int number, const char *base)
{
	int	count;
	int	result;

	count = 0;
	if (number >= 16)
	{
		result = ft_put_hex(number / 16, base);
		if (result < 0)
			return (-1);
		count += result;
	}
	result = ft_print_char(base[number % 16]);
	if (result < 0)
		return (-1);
	return (count + result);
}

int	ft_print_hex(unsigned int number, char format)
{
	if (format == 'X')
		return (ft_put_hex(number, "0123456789ABCDEF"));
	return (ft_put_hex(number, "0123456789abcdef"));
}
