/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:57:02 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/16 14:50:29 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_stack *a, t_stack *b, t_ops *ops)
{
	while (stack_len(a) > 0)
	{
		if (find_min_index(a) == a->top)
			op_pb(a, b, ops);
		else if ((a->top - find_min_index(a)) <= stack_len(a) / 2)
			op_ra(a, ops);
		else
			op_rra(a, ops);
	}
	while (!stack_empty(b))
		op_pa(a, b, ops);
}
