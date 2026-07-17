/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsevind <emsevind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:59:04 by emsevind          #+#    #+#             */
/*   Updated: 2026/07/17 12:59:05 by emsevind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_string(const char *str);
int	ft_print_number(int number);
int	ft_print_unsigned(unsigned int number);
int	ft_print_hex(unsigned int number, char format);
int	ft_print_pointer(void *pointer);

#endif
