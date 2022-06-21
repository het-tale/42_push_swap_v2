/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:03:09 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 18:03:09 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate(t_list *a)
{
    t_node  *removed;

    removed = pop_stack(a);
    push_at_last(a, removed);
}

void    rev_rotate(t_list *a)
{
    t_node  *removed;

    removed = del_last(a);
    push_at_first(a, removed);
}

void    rotate_two(t_list *a, t_list *b)
{
    rotate(a);
    rotate(b);
}

void    rev_rotate_two(t_list *a, t_list *b)
{
    rev_rotate(a);
    rev_rotate(b);
}