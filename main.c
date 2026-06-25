/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:46:06 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/30 17:47:37 by hmnatsak         ###   ########.fr       */
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

void	run_sort(t_stack *a, t_stack *b, t_ops *ops, int size)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (stack_is_sorted(a) && ops->bench)
	{
		print_bench(ops, disorder);
		return ;
	}
	if (stack_is_sorted(a))
		return ;
	normalize(a);
	if (ops->flag == FLAG_SIMPLE)
		sort_simple(a, b, ops);
	else if (ops->flag == FLAG_MEDIUM)
		sort_medium(a, b, ops);
	else if (ops->flag == FLAG_COMPLEX)
		sort_complex(a, b, ops);
	else
		sort_adaptive(a, b, ops, size);
	if (ops->bench)
		print_bench(ops, disorder);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	ops;
	int		*arr;
	int		size;

	if (argc < 2)
		return (0);
	ops = (t_ops){0};
	ops.flag = parse_flag(argv, argc);
	ops.bench = parse_bench(argv, argc);
	arr = parse_args(argv, argc, &size);
	a = stack_new(size);
	b = stack_new(size);
	if (!a || !b)
		error_exit(a, b, arr);
	fill_stack(a, arr, size);
	free(arr);
	run_sort(a, b, &ops, size);
	stack_free(a);
	stack_free(b);
	return (0);
}
