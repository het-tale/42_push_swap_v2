/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:24:17 by het-tale          #+#    #+#             */
/*   Updated: 2022/07/02 16:24:17 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_big_stack(t_list *a, t_list *b, int size_a)
{
	int	*moves;
	int	size_b;
	int	i;

	i = 0;
	send_to_b(a, b, size_a);
	size_b = stack_size(b);
	moves = put_on_top(b, size_b);
}