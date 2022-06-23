/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:40:06 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 16:40:06 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_two_first(t_list *a)
{
	if (!ft_only_one(a) && !is_empty(a))
		ft_swap(&(a->top->data), &(a->top->next->data));
}

void	swap_two(t_list *a, t_list *b)
{
	swap_two_first(a);
	swap_two_first(b);
}
