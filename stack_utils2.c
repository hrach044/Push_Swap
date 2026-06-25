/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:21:47 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/25 13:22:27 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_empty(t_stack *x)
{
	if (x->top == -1)
		return (1);
	else
		return (0);
}

int	stack_is_sorted(t_stack *a)
{
	int		i;

	i = 0;
	while (i < a->top)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	normalize(t_stack *a)
{
	int		*ranks;
	int		i;
	int		j;
	int		rank;

	ranks = malloc(stack_len(a) * sizeof(int));
	if (!ranks)
		return ;
	i = 0;
	while (i <= a->top)
	{
		rank = 0;
		j = 0;
		while (j <= a->top)
		{
			if (a->data[i] > a->data[j])
				rank++;
			j++;
		}
		ranks[i++] = rank;
	}
	i = 0;
	while (i++ <= a->top)
		a->data[i - 1] = ranks[i - 1];
	free(ranks);
}

int	find_max_index(t_stack *a)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (i <= a->top)
	{
		if (a->data[i] > a->data[max])
			max = i;
		i++;
	}
	return (max);
}

int	find_min_index(t_stack *a)
{
	int		i;
	int		min;

	i = 0;
	min = 0;
	while (i <= a->top)
	{
		if (a->data[i] < a->data[min])
			min = i;
		i++;
	}
	return (min);
}
