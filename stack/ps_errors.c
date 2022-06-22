/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:35:46 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 20:32:44 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isinteger(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_error(int argc, char *argv[])
{
	int		j;
	int		i;
	char	**split;

	j = 1;
	while (j < argc)
	{
		split = ft_split(argv[j], ' ');
		i = 0;
		while (split[i])
		{
			if (!ft_isinteger(split[i]))
				ft_error();
			free(split[i]);
			i++;
		}
		j++;
		free(split);
	}
}

void	is_duplicated(t_list *a)
{
	t_node	*temp;
	t_node	*tmp;

	temp = a->top;
	while (temp)
	{
		tmp = temp->next;
		while (tmp)
		{
			if (temp->data == tmp->data)
				ft_error();
			tmp = tmp->next;
		}
		temp = temp->next;
	}
}