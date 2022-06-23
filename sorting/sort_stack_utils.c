/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:11:32 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/22 17:11:32 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*copy_stack(t_list *a)
{
	t_list	*copy;
	t_node	*temp;
	t_node	*n;

	copy = new_list();
	temp = a->top;
	while (temp)
	{
		n = new_node(temp->data);
		push_at_last(copy, n);
		temp = temp->next;
	}
	return (copy);
}

t_node	*get_min(t_list *copy)
{
	t_node	*min;
	t_node	*temp;

	min = copy->top;
	temp = copy->top->next;
	while (temp)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

int	get_index(t_list *a, t_node *n)
{
	int		index;
	t_node	*temp;

	index = 0;
	temp = a->top;
	while (temp)
	{
		if (temp->data == n->data)
			return (index);
		index++;
		temp = temp->next;
	}
	return (-1);
}

t_list	*rotate_copy_stack(t_list *a)
{
	t_list	*copy;
	int		index;
	int		size;
	t_node	*min;

	copy = copy_stack(a);
	size = stack_size(copy);
	min = get_min(copy);
	index = get_index(copy, min);
	if (index > size / 2)
	{
		while (copy->top->data != min->data)
		{
			rev_rotate(copy);
		}
	}
	else
	{
		while (copy->top->data != min->data)
		{
			rotate(copy);
		}
	}
	return (copy);
}

int	*get_lis(t_list *a)
{
	t_list	*copy;

	copy = rotate_copy_stack(a);
}
