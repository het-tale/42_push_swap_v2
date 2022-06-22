/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:45:27 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 20:45:27 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    instructions(t_list *a, int d)
{
    if (d == 0)
    {
        swap_two_first(a);
        print_inst("sa\n");
    }
    else if (d == 1)
    {
        swap_two_first(a);
        print_inst("sa\n");
        rev_rotate(a);
        print_inst("rra\n");
    }
    else if (d == 2)
    {
        rotate(a);
        print_inst("ra\n");
    }
    else if (d == 3)
    {
        swap_two_first(a);
        print_inst("sa\n");
        rotate(a);
        print_inst("ra\n");
    }
}

void    three_elements(t_list *a)
{
    t_node  *top;
    t_node  *middle;
    t_node  *bottom;

    top = a->top;
    middle = a->top->next;
    bottom = a->top->next->next;
    if (top->data > middle->data && middle->data < bottom->data
        && bottom->data > top->data)
        instructions(a, 0);
    else if (top->data > middle->data && middle->data > bottom->data
        && bottom->data < top->data)
        instructions(a, 1);
    else if (top->data > middle->data && middle->data < bottom->data
        && bottom->data < top->data)
        instructions(a, 2);
    else if (top->data < middle->data && middle->data > bottom->data
        && bottom->data > top->data)
        instructions(a, 3);
    else
    {
        rev_rotate(a);
        print_inst("rra\n");
    }
}