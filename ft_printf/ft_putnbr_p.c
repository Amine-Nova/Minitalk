/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:32:14 by abenmous          #+#    #+#             */
/*   Updated: 2022/10/27 19:40:20 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_p(unsigned long n)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	if (n >= 0 && n < 16)
	{
		i += ft_putchar(str[n]);
	}
	else
	{
		i += ft_putnbr_p(n / 16);
		i += ft_putnbr_p(n % 16);
	}
	return (i);
}
