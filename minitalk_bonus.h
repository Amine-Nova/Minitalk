/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:22:25 by abenmous          #+#    #+#             */
/*   Updated: 2023/02/06 23:40:08 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
char	*switch_bin(unsigned char c);
char	*bin_text(char *str);
int		ft_atoi(const char *str);
void	get_character(char *str, int pid);
void	get_signal(char c, int pid);

#endif
