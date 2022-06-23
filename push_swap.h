/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:43:15 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/22 19:39:31 by het-tale         ###   ########.fr       */
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
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*top;
}	t_list;

t_node	*new_node(int data);
t_list	*new_list(void);
void	check_error(int argc, char *argv[]);
t_list	*get_stack(int argc, char *argv[], t_list *stack);
int		is_empty(t_list *stack);
void	traverse_stack(t_list *a);//remove
void	push_at_first(t_list *stack, t_node *temp);
void	is_duplicated(t_list *a);
int		is_sorted(t_list *a);
int		ft_only_one(t_list *a);
void	ft_swap(int *a, int *b);
void	swap_two_first(t_list *a);
void	swap_two(t_list *a, t_list *b);
void	push_at_last(t_list *stack, t_node *n);
t_node	*pop_stack(t_list *a);
void	push_stack(t_list *a, t_list *b);
void	rotate(t_list *a);
t_node	*del_last(t_list *a);
void	rev_rotate(t_list *a);
void	print_inst(char *instruction);
void	rev_rotate_two(t_list *a, t_list *b);
void	rotate_two(t_list *a, t_list *b);
void	instructions(t_list *a, int d);
int		stack_size(t_list *a);
void	sort_stack(t_list *a, t_list *b);
void	three_elements(t_list *a);
t_list	*copy_stack(t_list *a);
t_node	*get_last(t_list *a);
t_node	*get_min(t_list *copy);
int		get_index(t_list *a, t_node *n);
t_list	*rotate_copy_stack(t_list *a);
#endif
