/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:07:04 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/17 14:01:32 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	num;
	int	count;

	num = n;
	count = 0;
	if (n == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	count = count + (n <= 0);
	return (count);
}

static char	*exist(int n)
{
	char	*str;
	int		counter;

	counter = count(n);
	str = (char *)malloc(sizeof(char) * (counter + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	int		sign;
	int		counter;

	sign = 1;
	counter = count(n);
	if (n < 0)
		sign = sign * -1;
	newstr = exist(n);
	if (newstr == NULL)
		return (NULL);
	newstr[counter] = '\0';
	while (counter - (sign < 0) > 0)
	{
		counter--;
		newstr[counter] = sign * (char)(n % 10) + '0';
		n = n / 10;
	}
	counter--;
	if (sign < 0)
		newstr[counter] = '-';
	return (newstr);
}
