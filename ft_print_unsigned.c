/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsevind <emsevind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:58:11 by emsevind          #+#    #+#             */
/*   Updated: 2026/07/17 12:58:12 by emsevind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int number)
{
	int	count;
	int	result;

	count = 0;
	if (number >= 10)
	{
		result = ft_print_unsigned(number / 10);
		if (result < 0)
			return (-1);
		count += result;
	}
	result = ft_print_char((number % 10) + '0');
	if (result < 0)
		return (-1);
	return (count + result);
}
