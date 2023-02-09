/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:04:18 by abenmous          #+#    #+#             */
/*   Updated: 2022/10/27 18:29:38 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_hex(unsigned int n)
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
		i += ft_putnbr_hex(n / 16);
		i += ft_putnbr_hex(n % 16);
	}
	return (i);
}
