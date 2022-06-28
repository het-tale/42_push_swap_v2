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
	// t_list	*copy;
	// int		*arr;
	int		i;
	int		j;
	t_node	*temp;
	int		len;
	t_node	*tmp;

	i = 0;
	len = 0;
	//copy = rotate_copy_stack(a);
	temp = copy->top;
	// arr = malloc(sizeof(int) * stack_size(copy));
	// init_array(arr, copy);
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

void	get_lis(t_list *a)
{
	int	*lis;
	int	len;
	t_list	*copy;
	int		*arr;
	int		i;
	int		j;

	copy = rotate_copy_stack(a);
	arr = malloc(sizeof(int) * stack_size(copy));
	init_array(arr, copy);
	len = get_lis_len(copy, arr);
	lis = malloc(len * sizeof(int));
	i = stack_size(copy) - 1;
	j = len;
	
}