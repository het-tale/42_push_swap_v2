/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:40:53 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 15:49:32 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;

	a = new_list();
	if (argc > 1)
	{
		check_error(argc, argv);
		a = get_stack(argc, argv, a);
		is_duplicated(a);
	}
	traverse_stack(a);
	return (0);
}
