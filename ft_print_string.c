/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsevind <emsevind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:58:02 by emsevind          #+#    #+#             */
/*   Updated: 2026/07/17 12:58:04 by emsevind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(const char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
	{
		if (ft_print_char(str[count]) < 0)
			return (-1);
		count++;
	}
	return (count);
}
