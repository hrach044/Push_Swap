/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:25:50 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/16 12:40:18 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int n)
{
	int		max;
	int		bits;

	max = n - 1;
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	sort_complex(t_stack *a, t_stack *b, t_ops *ops)
{
	int		i;
	int		n;
	int		bit;
	int		bits;

	n = stack_len(a);
	bits = get_max_bits(n);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < n)
		{
			if ((a->data[a->top] >> bit) & 1)
				op_ra(a, ops);
			else
				op_pb(a, b, ops);
			i++;
		}
		bit++;
		while (!stack_empty(b))
		{
			op_pa(a, b, ops);
		}
	}
}
