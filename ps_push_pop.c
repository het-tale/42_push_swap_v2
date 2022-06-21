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

#include "push_swap.h"

void    push_at_first(t_list *stack, t_node *temp)
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