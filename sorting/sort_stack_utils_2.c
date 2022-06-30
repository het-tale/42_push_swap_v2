/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:46:33 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/30 17:46:33 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_val(t_list *copy, int i)
{
	t_node	*temp;
	int		index;

	temp = copy->top;
	while (temp)
	{
		index = get_index(copy, temp);
		if (index == i)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
