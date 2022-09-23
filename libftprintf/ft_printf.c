/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:30:54 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/22 11:11:46 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_eval_format(va_list ap, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(ap, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(ap, int));
	else if (format == 'u')
		print_length += ft_unsign(va_arg(ap, unsigned int));
	else if (format == 'p')
		print_length += ft_printadresse(va_arg(ap, unsigned long long));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		new;

	va_start (ap, s);
	i = 0;
	new = 0;
	while (s[i])
	{
		if (s[i] == '%' )
		{
			new += ft_eval_format(ap, s[i + 1]);
			i++;
		}
		else
			new += ft_printchar (s[i]);
		i++;
	}
	va_end (ap);
	return (new);
}
