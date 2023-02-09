/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:32:22 by abenmous          #+#    #+#             */
/*   Updated: 2022/10/28 17:13:02 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char i, va_list str)
{
	int	res;

	res = 0;
	if (i == 'c')
		res = res + ft_putchar(va_arg(str, int));
	else if (i == 's')
		res = res + ft_putstr(va_arg(str, char *));
	else if (i == 'p')
	{
		res = res + ft_putstr("0x");
		res = res + ft_putnbr_p(va_arg(str, unsigned long));
	}
	else if (i == 'd' || i == 'i')
		res = res + ft_putnbr(va_arg(str, int));
	else if (i == 'u')
		res = res + ft_putnbr_un(va_arg(str, unsigned int));
	else if (i == 'X')
		res = res + ft_putnbr_hexu(va_arg(str, unsigned int));
	else if (i == 'x')
		res = res + ft_putnbr_hex(va_arg(str, unsigned int));
	else if (i == '%')
		res = res + ft_putchar('%');
	return (res);
}

int	ft_printf(const char *s, ...)
{
	int		res;
	int		i;
	va_list	str;

	va_start(str, s);
	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			res = res + ft_check(s[i], str);
			i++;
		}
		else
		{
			res += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(str);
	return (res);
}
