/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:47:27 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/24 16:02:21 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pb(t_stack *a, t_stack *b, t_ops *ops)
{
	int		t;

	if (stack_len(a) == 0)
		return ;
	t = stack_pop(a);
	stack_push(b, t);
	if (!ops->silent)
		write(1, "pb\n", 3);
	ops->pb++;
	ops->total++;
}

void	op_pa(t_stack *a, t_stack *b, t_ops *ops)
{
	int		t;

	if (stack_len(b) == 0)
		return ;
	t = stack_pop(b);
	stack_push(a, t);
	if (!ops->silent)
		write(1, "pa\n", 3);
	ops->pa++;
	ops->total++;
}
