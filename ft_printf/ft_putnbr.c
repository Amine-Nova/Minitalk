/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:41:04 by abenmous          #+#    #+#             */
/*   Updated: 2022/10/27 19:39:26 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		i;

	i = 0;
	n = nb;
	if (nb < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		i += ft_putchar(n + 48);
	}
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}
