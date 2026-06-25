/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:23:37 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/24 16:04:01 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a, t_ops *ops)
{
	int		t;

	if (stack_len(a) < 2)
		return ;
	t = a->data[a->top];
	a->data[a->top] = a->data[a->top - 1];
	a->data[a->top - 1] = t;
	if (!ops->silent)
		write(1, "sa\n", 3);
	ops->sa++;
	ops->total++;
}

void	op_sb(t_stack *b, t_ops *ops)
{
	int		t;

	if (stack_len(b) < 2)
		return ;
	t = b->data[b->top];
	b->data[b->top] = b->data[b->top - 1];
	b->data[b->top - 1] = t;
	if (!ops->silent)
		write(1, "sb\n", 3);
	ops->sb++;
	ops->total++;
}

void	op_ss(t_stack *a, t_stack *b, t_ops *ops)
{
	int		t;

	if (stack_len(a) >= 2)
	{
		t = a->data[a->top];
		a->data[a->top] = a->data[a->top - 1];
		a->data[a->top - 1] = t;
	}
	if (stack_len(b) >= 2)
	{
		t = b->data[b->top];
		b->data[b->top] = b->data[b->top - 1];
		b->data[b->top - 1] = t;
	}
	if (!ops->silent)
		write(1, "ss\n", 3);
	ops->ss++;
	ops->total++;
}
