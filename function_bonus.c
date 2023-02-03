/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:22:34 by abenmous          #+#    #+#             */
/*   Updated: 2023/02/03 21:27:45 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

void	*my_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	len;
	size_t	i;	

	len = count * size;
	str = malloc(len);
	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	my_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*my_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str3;

	i = -1;
	j = 0;
	if (!str1 && !str2)
		return (0);
	if (!str1)
		str1 = my_calloc(1, 1);
	str3 = malloc(my_strlen(str1) + my_strlen(str2) + 1);
	if (!str3)
	{
		free(str1);
		return (0);
	}
	while (str1[++i])
		str3[i] = str1[i];
	while (str2[j])
		str3[i++] = str2[j++];
	str3[i] = '\0';
	free(str1);
	return (str3);
}

char	*switch_bin(unsigned char c)
{
	int		j;
	int		i;
	int		o;
	char	*str;

	str = malloc(33);
	i = 0;
	while (i <= 32)
	{
		str[i] = '0';
		i++;
	}
	i--;
	j = (int) c;
	while (j > 0 && i >= 0)
	{
		o = (j % 2);
		j = (j / 2);
		str[i] = o + 48;
		i--;
	}
	return (str);
}

char	*bin_text(char *str)
{
	int		i;
	char	*s;
	char	*ptr;
	char	d[33];

	i = 0;
	ptr = NULL;
	while (i <= 32)
	{
		d[i] = '0';
		i++;
	}
	i = 0;
	while (str[i])
	{
		s = switch_bin(str[i]);
		ptr = my_strjoin(ptr, s);
		free(s);
		i++;
	}
	free(str);
	ptr = my_strjoin(ptr, d);
	return (ptr);
}
