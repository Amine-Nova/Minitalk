/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:22:36 by abenmous          #+#    #+#             */
/*   Updated: 2023/02/03 21:27:10 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("The Message Has Been Received\n");
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					i;
	int					j;
	char				*ptr;

	(void) ac;
	j = 0;
	if (!av[2] || !av[2][0])
		return (0);
	sa.sa_flags = 0;
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	ptr = bin_text(av[2]);
	i = ft_atoi(av[1]);
	while (ptr[j])
	{
		if (ptr[j] == '1')
			kill(i, SIGUSR1);
		if (ptr[j] == '0')
			kill(i, SIGUSR2);
		j++;
		usleep(222);
	}
	free(ptr);
}
