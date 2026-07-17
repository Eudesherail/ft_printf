/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsevind <emsevind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:57:13 by emsevind          #+#    #+#             */
/*   Updated: 2026/07/17 12:57:15 by emsevind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int number)
{
	long	value;
	int		count;
	int		result;

	value = number;
	count = 0;
	if (value < 0)
	{
		result = ft_print_char('-');
		if (result < 0)
			return (-1);
		count += result;
		value = -value;
	}
	result = ft_print_unsigned((unsigned int)value);
	if (result < 0)
		return (-1);
	return (count + result);
}
