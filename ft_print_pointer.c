/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsevind <emsevind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:57:56 by emsevind          #+#    #+#             */
/*   Updated: 2026/07/17 12:57:58 by emsevind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_pointer(uintptr_t number)
{
	const char	*base;
	int			count;
	int			result;

	base = "0123456789abcdef";
	count = 0;
	if (number >= 16)
	{
		result = ft_put_pointer(number / 16);
		if (result < 0)
			return (-1);
		count += result;
	}
	result = ft_print_char(base[number % 16]);
	if (result < 0)
		return (-1);
	return (count + result);
}

int	ft_print_pointer(void *pointer)
{
	int	count;
	int	result;

	if (!pointer)
		return (ft_print_string("(nil)"));
	count = ft_print_string("0x");
	if (count < 0)
		return (-1);
	result = ft_put_pointer((uintptr_t)pointer);
	if (result < 0)
		return (-1);
	return (count + result);
}
