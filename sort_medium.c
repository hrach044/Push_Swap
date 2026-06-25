/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:01:03 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/16 15:08:39 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_chunk(t_stack *a, int min, int max)
{
	int		i;

	i = 0;
	while (i <= a->top)
	{
		if (a->data[i] <= max && a->data[i] >= min)
			return (1);
		i++;
	}
	return (0);
}

void	push_chunk_to_b(t_stack	*a, t_stack *b, int chunk, t_ops *ops)
{
	int		min;
	int		max;
	int		n;

	n = stack_len(a) + stack_len(b);
	min = chunk * ft_sqrt(n);
	max = min + ft_sqrt(n) - 1;
	while (has_chunk(a, min, max))
	{
		if (a->data[a->top] >= min && a->data[a->top] <= max)
			op_pb(a, b, ops);
		else
			op_ra(a, ops);
	}
}

void	bring_max_to_top(t_stack *b, t_ops *ops)
{
	int		max_index;
	int		n;

	max_index = find_max_index(b);
	n = stack_len(b) / 2;
	while (max_index != b->top)
	{
		if (max_index > n)
			op_rb(b, ops);
		else
			op_rrb(b, ops);
		max_index = find_max_index(b);
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_ops *ops)
{
	int		chunk;
	int		n;

	n = stack_len(a);
	chunk = 0;
	while (chunk * ft_sqrt(n) < n)
	{
		push_chunk_to_b(a, b, chunk, ops);
		chunk++;
	}
	while (!stack_empty(b))
	{
		bring_max_to_top(b, ops);
		op_pa(a, b, ops);
	}
}
