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

t_node	*get_max(t_list *a)
{
	t_node	*temp;
	t_node	*max;

	max = a->top;
	temp = max->next;
	while (temp != NULL)
	{
		if (temp->data > max->data)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

int	abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	*best(int *positions, int size_b)
{
	int	*best;
	int	i;
	int	j;
	int	index;

	best = malloc(size_b * sizeof(int));
	i = 0;
	while (i < size_b)
	{
		j = 0;
		index = 0;
		while (j < size_b - i - 1)
		{
			if (positions[j] < positions[j + 1])
			{
				index = j;
			}
			else
			{
				index = j + 1;
			}
			j++;

		}
		best[i] = index;
		i++;
	}
	return (best);
}

void	sort_big_stack(t_list *a, t_list *b, int size_a)
{
	int	*moves;
	int	*positions;
	int	*best1;
	int	size_b;

	send_to_b(a, b, size_a);
	size_b = stack_size(b);
	moves = put_on_top(b, size_b);
	positions = a_position(a, b, size_a);
	best1 = best(positions, size_b);
	send_to_a(best1, b, a, positions, moves);
	//rotate_smallest(a, size_a);
}