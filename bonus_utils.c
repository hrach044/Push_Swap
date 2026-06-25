/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:26:21 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/30 17:47:08 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *a, int *arr, int size)
{
	int		i;

	i = size - 1;
	while (i >= 0)
	{
		stack_push(a, arr[i]);
		i--;
	}
}

void	check(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a) && stack_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
