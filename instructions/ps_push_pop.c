/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:06:07 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 15:06:07 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_at_first(t_list *stack, t_node *temp)
{
	if (is_empty(stack))
		stack->top = temp;
	else
	{
		temp->next = stack->top;
		stack->top->prev = temp;
		stack->top = temp;
	}
}

void	push_at_last(t_list *stack, t_node *n)
{
	t_node	*temp;

	temp = stack->top;
	if (is_empty(stack))
		stack->top = n;
	else
	{
		temp = get_last(stack);
		temp->next = n;
		n->prev = temp;
		n->next = NULL;
	}
}

t_node	*pop_stack(t_list *a)
{
	t_node	*removed;

	removed = NULL;
	if (!is_empty(a))
	{
		removed = a->top;
		a->top->next->prev = NULL;
		a->top = a->top->next;
		removed->next = NULL;
		removed->prev = NULL;
	}
	return (removed);
}

t_node	*del_last(t_list *a)
{
	t_node	*removed;

	removed = a->top;
	if (!is_empty(a))
	{
		while (removed)
		{
			if (removed->next == NULL)
			{
				removed->prev->next = NULL;
				removed->next = NULL;
				removed->prev = NULL;
				return (removed);
			}
			removed = removed->next;
		}
	}
	return (removed);
}

void	push_stack(t_list *a, t_list *b)
{
	t_node	*removed;

	removed = NULL;
	if (!is_empty(b))
	{
		removed = pop_stack(b);
		push_at_first(a, removed);
	}
}
