/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:38:00 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/22 11:25:33 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*exist(unsigned int n)
{
	char	*str;
	int		counter;

	counter = count(n);
	str = (char *)malloc(sizeof(char) * (counter + 1));
	if (!str)
		return (0);
	str[counter] = '\0';
	while (counter > 0)
	{
		counter--;
		str[counter] = (char)(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

int	ft_unsign(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len = write (1, "0", 1);
	else
	{
		num = exist(n);
		len += ft_printstr(num);
		free (num);
	}
	return (len);
}
