/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:20:42 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/25 14:33:27 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int size)
{
	t_stack	*x;

	x = malloc(sizeof(t_stack));
	if (!x)
		return (NULL);
	x->data = malloc(size * sizeof(int));
	if (!x->data)
		return (free(x), NULL);
	x->size = size;
	x->top = -1;
	return (x);
}

void	stack_free(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->data);
	free(stack);
}

void	stack_push(t_stack *x, int nbr)
{
	x->top++;
	x->data[x->top] = nbr;
}

int	stack_pop(t_stack *x)
{
	int		t;

	t = x->data[x->top];
	x->top--;
	return (t);
}

int	stack_len(t_stack *x)
{
	return (x->top + 1);
}
