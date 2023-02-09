/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:56:21 by abenmous          #+#    #+#             */
/*   Updated: 2022/10/27 19:38:50 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putnbr_hex(unsigned int n);
int	ft_putnbr_hexu(unsigned int i);
int	ft_putnbr_un(unsigned int u);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putnbr_p(unsigned long n);

#endif
