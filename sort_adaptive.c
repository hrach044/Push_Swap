/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:02:25 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/28 16:55:08 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b, t_ops *ops, int size)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (size == 3)
	{
		if (stack_is_sorted(a))
			return ;
		sort3(a, ops);
	}
	else if (size == 5)
	{
		if (stack_is_sorted(a))
			return ;
		sort5(a, b, ops);
	}
	else if (disorder < 0.2)
		sort_simple(a, b, ops);
	else if (disorder < 0.5)
		sort_medium(a, b, ops);
	else
		sort_complex(a, b, ops);
}
