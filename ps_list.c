/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:29:35 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 16:34:12 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->top = NULL;
	return (list);
}

int	is_empty(t_list *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

void	traverse_stack(t_list *a)
{
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int	ft_only_one(t_list *a)
{
	if (!is_empty(a) && a->top->next == NULL)
		return (1);
	return (0);
}

int	is_sorted(t_list *a)
{
	t_node	*tmp;
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		tmp = temp->next;
		while (tmp)
		{
			if (temp->data > tmp->data)
				return (0);
			tmp = tmp->next;
		}
		temp = temp->next;
	}
	return (1);
}