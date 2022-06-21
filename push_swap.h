/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:43:15 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/21 15:29:57 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
    int             data;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_list
{
    t_node  *top;
} t_list;

t_node	*new_node(int data);
t_list	*new_list(void);
void	check_error(int argc, char *argv[]);
t_list	*get_stack(int argc, char *argv[], t_list *stack);
int     is_empty(t_list *stack);
void	traverse_stack(t_list *a);//remove
void    push_at_first(t_list *stack, t_node *temp);
void	is_duplicated(t_list *a);
#endif
