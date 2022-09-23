/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:59:20 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/22 11:27:58 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_print_hex(unsigned int num, const char format);
int	ft_printnbr(int n);
int	ft_printstr(char *str);
int	ft_unsign(unsigned int n);
int	ft_printadresse(unsigned long ptr);
int	ft_print_percent(void);
int	ft_printchar(char c);

#endif
