/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:47:31 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/25 13:26:56 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *x)
{
	int		i;
	int		t;

	if (stack_len(x) < 2)
		return ;
	t = x->data[x->top];
	i = x->top;
	while (i > 0)
	{
		x->data[i] = x->data[i - 1];
		i--;
	}
	x->data[0] = t;
}

void	op_ra(t_stack *a, t_ops *ops)
{
	if (stack_len(a) < 2)
		return ;
	rotate(a);
	if (!ops->silent)
		write(1, "ra\n", 3);
	ops->ra++;
	ops->total++;
}

void	op_rb(t_stack *b, t_ops *ops)
{
	if (stack_len(b) < 2)
		return ;
	rotate(b);
	if (!ops->silent)
		write(1, "rb\n", 3);
	ops->rb++;
	ops->total++;
}

void	op_rr(t_stack *a, t_stack *b, t_ops *ops)
{
	if (stack_len(a) < 2 && stack_len(b) < 2)
		return ;
	if (stack_len(a) >= 2)
		rotate(a);
	if (stack_len(b) >= 2)
		rotate(b);
	if (!ops->silent)
		write(1, "rr\n", 3);
	ops->rr++;
	ops->total++;
}
