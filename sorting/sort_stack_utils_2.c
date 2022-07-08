/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:46:33 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/30 17:46:33 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_val(t_list *copy, int i)
{
	t_node	*temp;
	int		index;

	temp = copy->top;
	while (temp)
	{
		index = get_index(copy, temp);
		if (index == i)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	is_exist(t_list *lis, t_node *n)
{
	t_node	*temp;

	temp = lis->top;
	while (temp)
	{
		if (temp->data == n->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	send_to_b(t_list *a, t_list *b, int size)
{
	t_list	*lis;
	t_node	*temp;
	t_node	*tmp;
	int		index;

	temp = a->top;
	lis = get_lis(a, size);
	index = 0;
	while (temp)
	{
		tmp = temp->next;
		if (is_exist(lis, temp) == 0)
		{
			index = get_index(a, temp);
			if (index > size / 2)
			{
				while (a->top->data != temp->data)
				{
					rev_rotate(a);
				}
			}
			else
			{
				while (a->top->data != temp->data)
				{
					rotate(a);
				}
			}
			push_stack(b, a);
			print_inst("pb\n");
		}
		temp = tmp;
	}
}

int	*put_on_top(t_list *b, int size)
{
	t_node	*temp;
	int		*moves;
	int		index;

	temp = b->top;
	moves = malloc(size * sizeof(int));
	index = 0;
	while (temp)
	{
		index = get_index(b, temp);
		if (index >= size / 2)
			moves[index] = (size - index) * -1;
		else
			moves[index] = index;
		temp = temp->next;
	}
	return (moves);
}

t_node	*max(t_node *a, t_node *b)
{
	t_node	*max;

	if (a->data > b->data)
		max = a;
	else
		max = b;
	return (max);
}

t_node	*min(t_node *a, t_node *b)
{
	t_node	*min;

	if (a->data < b->data)
		min = a;
	else
		min = b;
	return (min);
}
int	*a_position(t_list *a, t_list *b, int size)
{
	t_node	*temp;
	t_node	*tmp;
	t_node	*last;
	int		*positions;
	int		index;
	int		j;
	t_node	*min_;
	t_node	*max_;
	int		l;
	int		in;

	temp = b->top;
	positions = malloc(sizeof(int) * stack_size(b));
	index = 0;
	j = 0;
	while (temp)
	{
		l = 0;
		tmp = a->top;
		last = get_last(a);
		min_ = min(tmp, last);
		max_ = max(tmp, last);
		index = get_index(b, temp);
		in = get_index(a, tmp);
		if (temp->data > min_->data && temp->data < max_->data)
			positions[index] = in + 1;
		else if (temp->data > get_max(a)->data)
		{
			in = get_index(a, get_max(a));
			if (in > size / 2)
				positions[index] = (in + 1) * -1;
			else
				positions[index] = in + 1;
		}
		else
		{
			if (l == 0)
			{
				while (in < size / 2)
				{
					min_ = min(tmp, tmp->next);
					max_ = max(tmp, tmp->next);
					if (temp->data > min_->data && temp->data < max_->data)
					{
						positions[index] = in + 1;
						l = 1;
						break ;
					}
					tmp = tmp->next;
					in = get_index(a, tmp);
				}
			}
			if (l == 0)
			{
				j = get_index(a, last);
				while (j >= size / 2)
				{
					min_ = min(last, last->prev);
					max_ = max(last, last->prev);
					if (temp->data > min_->data && temp->data < max_->data)
					{
						positions[index] = j * -1;
						break ;
					}
					last = last->prev;
					j = get_index(a, last);
				}
			}
		}
		temp = temp->next;
	}
	return(positions);
}

void	rotate_smallest(t_list *a, int size)
{
	t_node	*min;
	int		index;

	min = get_min(a);
	index = get_index(a, min);
	if (min->data != a->top->data)
	{
		if (index > size / 2)
		{
			while (min->data != a->top->data)
			{
				rev_rotate(a);
				print_inst("rra\n");
			}
		}
		else
		{
			while (min->data != a->top->data)
			{
				rotate(a);
				print_inst("ra\n");
			}
		}
	}
}

void	send_to_a(int *best, t_list *b, t_list *a, int *positions, int *moves)
{
	int		i;
	int		size_b;
	t_node	*temp;
	int		index;
	int		l;
	int		k;

	size_b = stack_size(b);
	i = 0;
	l = 0;
	k = 0;
	while (i < size_b)
	{
		temp = b->top;
		while (temp)
		{
			index = get_index(b, temp);
			if (index == best[i])
			{
				if (l == 0)
				{
					if (moves[index] < 0)
					{
						while (temp->data != b->top->data)
						{
							rev_rotate(b);
							print_inst("rrb\n");
							l = 1;
						}
					}
					else
					{
						while (temp->data != b->top->data)
						{
							rotate(b);
							print_inst("rb\n");
							l = 1;
						}
					}
				}
				else
				{
					moves[index] = abs(moves[index]);
					if (moves[index] < 0)
					{
						while (temp->data != b->top->data)
						{
							rev_rotate(b);
							print_inst("rrb\n");
							l = 1;
						}
					}
					else
					{
						while (temp->data != b->top->data)
						{
							rotate(b);
							print_inst("rb\n");
							l = 1;
						}
					}
				}
				// (void)a;
				// (void)positions;
				// (void)k;
				//send to a
				if (temp->data > a->top->data)
				{
					k = 0;
					while (k < positions[index])
					{
						rotate(a);
						print_inst("ra\n");
						k++;
					}
					push_stack(a, b);
				}
				else
				{
					push_stack(a, b);
					k = 0;
					while (k < positions[index])
					{
						rotate(a);
						print_inst("ra\n");
						k++;
					}
				}
			}
			temp = temp->next;
		}
		i++;
	}
}