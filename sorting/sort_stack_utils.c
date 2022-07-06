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

void	init_array(int *arr, t_list *copy)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(copy);
	while (i < size)
	{
		arr[i] = 1;
		i++;
	}
}

int	get_lis_len(t_list *copy, int *arr)
{
	int		i;
	int		j;
	t_node	*temp;
	int		len;
	t_node	*tmp;

	i = 0;
	len = 0;
	temp = copy->top;
	while (temp->next)
	{
		i = get_index(copy, temp->next);
		j = 0;
		tmp = copy->top;
		while (j < i)
		{
			if (temp->next->data > tmp->data && arr[i] <= arr[j])
			{
				arr[i] = arr[j] + 1;
				len = arr[i];
			}
			j++;
			tmp = tmp->next;
		}
		temp = temp->next;
	}
	return (len);
}

t_list	*get_lis(t_list *a, int size)
{
	t_lis	longest;

	longest.copy = rotate_copy_stack(a);
	longest.arr = malloc(sizeof(int) * size);
	init_array(longest.arr, longest.copy);
	longest.len = get_lis_len(longest.copy, longest.arr);
	longest.lis = new_list();
	longest.i = size - 1;
	longest.k = longest.arr[longest.i];
	longest.l = 0;
	while (longest.i >= 0)
	{
		if (longest.arr[longest.i] == longest.k - longest.l)
		{
			longest.val = find_val(longest.copy, longest.i);
			if (longest.val)
				push_at_first(longest.lis, longest.val);
			longest.l++;
		}
		longest.i--;
	}
	return (longest.lis);
}
