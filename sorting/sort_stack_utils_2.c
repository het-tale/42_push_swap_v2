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

int	is_exist(t_list *lis, t_node *n)
{
	t_node	*temp;

	temp = lis->top;
	while (temp)
	{
		if (temp->data == n->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	send_to_b(t_list *a, t_list *b, int size)
{
	t_list	*lis;
	t_node	*temp;
	t_node	*tmp;
	int		index;

	temp = a->top;
	lis = get_lis(a, size);
	index = 0;
	while (temp)
	{
		tmp = temp->next;
		if (is_exist(lis, temp) == 0)
		{
			index = get_index(a, temp);
			if (index > size / 2)
			{
				while (a->top->data != temp->data)
				{
					rev_rotate(a);
				}
			}
			else
			{
				while (a->top->data != temp->data)
				{
					rotate(a);
				}
			}
			push_stack(b, a);
			print_inst("pb\n");
		}
		temp = tmp;
	}
}

int	*put_on_top(t_list *b, int size)
{
	t_node	*temp;
	int		*moves;
	int		index;

	temp = b->top;
	moves = malloc(size * sizeof(int));
	index = 0;
	while (temp)
	{
		index = get_index(b, temp);
		if (index > size / 2)
			moves[index] = (size - index) * -1;
		else
			moves[index] = index;
		temp = temp->next;
	}
	return (moves);
}

int	max(int a, int b)
{
	int	max;

	max = 0;
	if (a > b)
		max = a;
	else
		max = b;
	return (max);
}

int	min(int a, int b)
{
	int	min;

	min = 0;
	if (a < b)
		min = a;
	else
		min = b;
	return (min);
}
// int	*a_position(t_list *a, t_list *b, int size)
// {
// 	t_node	*temp;
// 	t_node	*tmp;
// 	t_node	*last;
// 	int		*positions;

// 	temp = b->top;
// 	tmp = a->top;
// 	last = get_last(a);
// 	positions = malloc(sizeof(int) * stack_size(b));
// 	while (temp)
// 	{
// 		while (tmp)
// 		{
// 			if (temp->data > min(tmp->data, last->data)
// 				&& temp->data < max(tmp->data, last->data))
					

// 		}
// 	}
// }