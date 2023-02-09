/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:41:13 by abenmous          #+#    #+#             */
/*   Updated: 2022/10/27 18:29:43 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_hexu(unsigned int i)
{
	char	*str;
	int		j;

	j = 0;
	str = "0123456789ABCDEF";
	if (j >= 0 && i < 16)
	{
		j += ft_putchar(str[i]);
	}
	else
	{
		j += ft_putnbr_hexu(i / 16);
		j += ft_putnbr_hexu(i % 16);
	}
	return (j);
}
