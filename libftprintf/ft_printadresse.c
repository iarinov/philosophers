/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadresse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:30:01 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/27 14:27:51 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long num)
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

static void	ft_put_ptr(unsigned long num)
{
	char	c;

	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			c = num + '0';
		else
			c = num - 10 + 'a';
		write (1, &c, 1);
	}
}

int	ft_printadresse(unsigned long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write (1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
