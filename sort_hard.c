/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:44:16 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/26 18:44:17 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *a, t_ops *ops)
{
	if (a->data[a->top] > a->data[a->top - 1]
		&& a->data[a->top] > a->data[a->top - 2])
	{
		op_ra(a, ops);
		if (a->data[a->top] > a->data[a->top - 1])
			op_sa(a, ops);
	}
	else if (a->data[a->top - 1] > a->data[a->top]
		&& a->data[a->top - 1] > a->data[a->top - 2])
	{
		op_rra(a, ops);
		if (a->data[a->top] > a->data[a->top - 1])
			op_sa(a, ops);
	}
	else if (a->data[a->top] > a->data[a->top - 1])
		op_sa(a, ops);
}

void	sort5(t_stack *a, t_stack *b, t_ops *ops)
{
	while (find_min_index(a) != a->top)
	{
		if (find_min_index(a) > 2)
			op_ra(a, ops);
		else
			op_rra(a, ops);
	}
	op_pb(a, b, ops);
	while (find_min_index(a) != a->top)
	{
		if (find_min_index(a) > 1)
			op_ra(a, ops);
		else
			op_rra(a, ops);
	}
	op_pb(a, b, ops);
	sort3(a, ops);
	op_pa(a, b, ops);
	op_pa(a, b, ops);
}
