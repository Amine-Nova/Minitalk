/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:22:29 by abenmous          #+#    #+#             */
/*   Updated: 2023/02/06 23:15:29 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	g_i;

void	get_character(char *str, int pid)
{
	int				i;
	int				j;
	unsigned char	c;
	int				k;

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
	c = (unsigned char)k;
	ft_printf("%c", c);
	if (k == 0)
		kill(pid, SIGUSR1);
}

void	get_signal(char c, int pid)
{
	static char	str[33];

	if (g_i <= 32)
	{
		str[g_i] = c;
		g_i++;
	}
	if (g_i == 33)
	{
		g_i = 0;
		get_character(str, pid);
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
		get_signal('0', pid);
	if (signum == SIGUSR1)
		get_signal('1', pid);
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
