/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:16:22 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/27 14:27:50 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num, const char format)
{
	char	c;

	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
		{
			c = num + '0';
		}
		else
		{
			if (format == 'x')
				c = num - 10 + 'a';
			if (format == 'X')
				c = num - 10 + 'A';
		}
		write (1, &c, 1);
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}
