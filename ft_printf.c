/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsevind <emsevind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:58:23 by emsevind          #+#    #+#             */
/*   Updated: 2026/07/17 12:58:25 by emsevind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(char specifier, va_list *arguments)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(*arguments, int)));
	if (specifier == 's')
		return (ft_print_string(va_arg(*arguments, char *)));
	if (specifier == 'p')
		return (ft_print_pointer(va_arg(*arguments, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_number(va_arg(*arguments, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(*arguments, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(*arguments, unsigned int), specifier));
	if (specifier == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	ft_process_format(const char *format, va_list *arguments)
{
	int	index;
	int	total;
	int	result;

	index = 0;
	total = 0;
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1])
		{
			result = ft_conversion(format[index + 1], arguments);
			index += 2;
		}
		else
		{
			result = ft_print_char(format[index]);
			index++;
		}
		if (result < 0)
			return (-1);
		total += result;
	}
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		result;

	if (!format)
		return (-1);
	va_start(arguments, format);
	result = ft_process_format(format, &arguments);
	va_end(arguments);
	return (result);
}
