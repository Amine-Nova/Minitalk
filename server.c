/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:07:00 by abenmous          #+#    #+#             */
/*   Updated: 2023/02/03 21:19:14 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_i;

void	get_character(char *str)
{
	int		i;
	int		j;
	char	c;
	int		k;

	i = strlen(str) - 1;
	k = 0;
	j = 1;
	while (i >= 0)
	{
		if (str[i] == '1')
			k = k + j;
		i--;
		j = j * 2;
	}
	c = (char)k;
	ft_printf("%c", c);
}

void	get_signal(char c)
{
	static char	str[8];

	if (g_i <= 7)
	{
		str[g_i] = c;
		g_i++;
	}
	if (g_i == 8)
	{
		g_i = 0;
		get_character(str);
	}
}

void	sigact(int signum, siginfo_t *info, void *p)
{
	static int	pid;

	(void) p;
	if (pid != info->si_pid)
	{
		g_i = 0;
		pid = info->si_pid;
	}
	if (signum == SIGUSR2)
		get_signal('0');
	if (signum == SIGUSR1)
		get_signal('1');
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigact;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("%d\n", getpid());
	while (1)
		;
}
