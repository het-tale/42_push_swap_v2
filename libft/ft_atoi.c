/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:03:17 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 19:34:49 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	return (i);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				d;
	unsigned long	res;

	i = 0;
	d = 1;
	res = 0;
	i = ft_isspace(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			d = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (d == -1 && (long)(res * d) < -2147483648)
		ft_error();
	else if ((long)(res * d) > 2147483647)
		ft_error();
	return ((int)res * d);
}
