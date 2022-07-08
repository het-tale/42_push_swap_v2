/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:40:53 by het-tale          #+#    #+#             */
/*   Updated: 2022/07/08 20:11:22 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list *a, t_list *b)
{
	int	size;

	size = stack_size(a);
	if (size == 2)
	{
		swap_two_first(a);
		print_inst("sa\n");
	}
	else if (size == 3)
		three_elements(a);
	else
		sort_big_stack(a, b, size);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = new_list();
	b = new_list();
	if (argc > 1)
	{
		check_error(argc, argv);
		a = get_stack(argc, argv, a);
		is_duplicated(a);
		if (!is_empty(a) && !ft_only_one(a) && !is_sorted(a))
		{
			sort_stack(a, b);
		}
	}
	traverse_stack(a);
	traverse_stack(b);
	// (void)b;
	// send_to_b(a, b, stack_size(a));
	// traverse_stack(a);
	// traverse_stack(b);
	// int size_b = stack_size(b);
	// //int *moves = put_on_top(b, size_b);
	// int *positions = a_position(a, b, stack_size(a));
	// int	*best1 = best(positions, size_b);
	// int i = 0;
	// while (i < 4)
	// {
	// 	printf("%d ", best1[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// while (i < 4)
	// {
	// 	printf("%d ", positions[i]);
	// 	i++;
	// }
	return (0);
}
