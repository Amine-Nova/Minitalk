/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:59:05 by abenmous          #+#    #+#             */
/*   Updated: 2023/02/06 23:40:04 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include "ft_printf/ft_printf.h"

int		ft_putstr(char *s);
void	*my_calloc(size_t count, size_t size);
size_t	my_strlen(char *s);
char	*my_strjoin(char *str1, char *str2);
char	*switch_bin(char c);
char	*bin_text(char *str);
int		ft_atoi(const char *str);
void	get_character(char *str);
void	get_signal(char c);

#endif