/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:07:00 by abenmous          #+#    #+#             */
/*   Updated: 2023/01/26 17:38:10 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_signal(char c)
{
	static int i;
	static char str[8];

	if(i <= 7)
	{
		str[i] = c;
		i++;
	}
	if(i == 8)
	{
		i = 0;
		printf("%s\n", str);
	}

}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		get_signal('1');
	if (signum == SIGUSR2)
		get_signal('0');
}
int main()
{
	struct sigaction sa;
	
	sa.sa_flags = 0;
	sa.sa_handler = &handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	printf("%d\n", getpid());
	while (1);
}