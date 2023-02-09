/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:41:00 by abenmous          #+#    #+#             */
/*   Updated: 2022/10/27 19:40:01 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_un(unsigned int u)
{
	int	i;

	i = 0;
	if (u >= 0 && u <= 9)
	{
		i += ft_putchar(u + 48);
	}
	else
	{
		i += ft_putnbr_un(u / 10);
		i += ft_putnbr_un(u % 10);
	}
	return (i);
}
