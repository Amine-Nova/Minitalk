/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:07:14 by abenmous          #+#    #+#             */
/*   Updated: 2023/02/06 23:20:31 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 0;
	while (str[a] == 32 || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			b = -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		c = c * 10 + str[a] - 48;
		a++;
	}
	return (c * b);
}

int	main(int ac, char **av)
{
	int		i;
	char	*str;
	int		j;
	char	*ptr;

	j = 0;
	if (ac != 3)
		return (0);
	if (!av[2] || !av[2][0])
		return (0);
	str = av[2];
	ptr = bin_text(str);
	i = ft_atoi(av[1]);
	while (ptr[j])
	{
		if (ptr[j] == '1')
			kill(i, SIGUSR1);
		if (ptr[j] == '0')
			kill(i, SIGUSR2);
		j++;
		usleep(100);
	}
	free(ptr);
	return (0);
}
