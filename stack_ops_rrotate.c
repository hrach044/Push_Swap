/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:47:35 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/24 16:03:31 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack *x)
{
	int		i;
	int		t;

	if (stack_len(x) < 2)
		return ;
	t = x->data[0];
	i = 0;
	while (i < x->top)
	{
		x->data[i] = x->data[i + 1];
		i++;
	}
	x->data[x->top] = t;
}

void	op_rra(t_stack *a, t_ops *ops)
{
	if (stack_len(a) < 2)
		return ;
	rev_rotate(a);
	if (!ops->silent)
		write(1, "rra\n", 4);
	ops->rra++;
	ops->total++;
}

void	op_rrb(t_stack *b, t_ops *ops)
{
	if (stack_len(b) < 2)
		return ;
	rev_rotate(b);
	if (!ops->silent)
		write(1, "rrb\n", 4);
	ops->rrb++;
	ops->total++;
}

void	op_rrr(t_stack *a, t_stack *b, t_ops *ops)
{
	if (stack_len(a) < 2 && stack_len(b) < 2)
		return ;
	if (stack_len(a) >= 2)
		rev_rotate(a);
	if (stack_len(b) >= 2)
		rev_rotate(b);
	if (!ops->silent)
		write(1, "rrr\n", 4);
	ops->rrr++;
	ops->total++;
}
