/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:07:00 by abenmous          #+#    #+#             */
/*   Updated: 2023/01/26 16:26:45 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	if(signum == SIGUSR1)
		write (1,"1", 1);
	if(signum == SIGUSR2)
		write (1,"0", 1);

}

int main()
{
	struct sigaction sa;
	
	sa.sa_flags = 0;
	sa.sa_handler = &handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	printf("%d\n", getpid());
	while(1);
}