/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:59:05 by abenmous          #+#    #+#             */
/*   Updated: 2023/01/26 17:16:47 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct t_var
{
	int i;
	int j;
	char *str;
} t_vars;

int	ft_putstr(char *s);

#endif