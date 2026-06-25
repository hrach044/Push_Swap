/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:09:04 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/25 20:00:57 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int		i;
	int		j;
	double	mistakes;
	double	total;

	if (stack_len(a) < 2)
		return (0);
	i = 0;
	mistakes = 0;
	total = 0;
	while (i < stack_len(a))
	{
		j = i + 1;
		while (j < stack_len(a))
		{
			total++;
			if (a->data[i] < a->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total);
}
