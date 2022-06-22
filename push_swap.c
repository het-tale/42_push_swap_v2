/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:40:53 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/22 13:41:05 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list *a, t_list *b)
{
	int	size;

	(void)b;
	size = stack_size(a);
	if (size == 3)
		three_elements(a);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = new_list();
	b = new_list();
	(void)b;
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
	return (0);
}
