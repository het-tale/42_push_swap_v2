/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:29:35 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 15:20:44 by het-tale         ###   ########.fr       */
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