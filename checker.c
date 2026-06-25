/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:27:07 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/30 12:37:35 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_line(void)
{
	char	*line;
	char	c;
	int		i;
	int		bites;

	line = malloc(5);
	if (!line)
		return (NULL);
	i = 0;
	while (1)
	{
		bites = read(0, &c, 1);
		if (bites != 1 || c == '\n')
			break ;
		if (i < 4)
			line[i++] = c;
	}
	if (bites == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

int	apply_op1(char	*line, t_stack *a, t_stack *b, t_ops *ops)
{
	if (!ft_strcmp(line, "sa"))
		op_sa(a, ops);
	else if (!ft_strcmp(line, "sb"))
		op_sb(b, ops);
	else if (!ft_strcmp(line, "ss"))
		op_ss(a, b, ops);
	else if (!ft_strcmp(line, "pa"))
		op_pa(a, b, ops);
	else if (!ft_strcmp(line, "pb"))
		op_pb(a, b, ops);
	else if (!ft_strcmp(line, "ra"))
		op_ra(a, ops);
	else if (!ft_strcmp(line, "rb"))
		op_rb(b, ops);
	else if (!ft_strcmp(line, "rr"))
		op_rr(a, b, ops);
	else
		return (0);
	return (1);
}

int	apply_op2(char	*line, t_stack *a, t_stack *b, t_ops *ops)
{
	if (line[0] == '\0')
		return (1);
	else if (apply_op1(line, a, b, ops))
		return (1);
	else if (!ft_strcmp(line, "rra"))
		op_rra(a, ops);
	else if (!ft_strcmp(line, "rrb"))
		op_rrb(b, ops);
	else if (!ft_strcmp(line, "rrr"))
		op_rrr(a, b, ops);
	else
	{
		write (2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	read_and_apply(t_stack *a, t_stack *b, t_ops *ops)
{
	char	*line;

	line = read_line();
	while (line)
	{
		if (!apply_op2(line, a, b, ops))
		{
			free(line);
			return (0);
		}
		free(line);
		line = read_line();
	}
	free(line);
	return (1);
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
	ops.silent = 1;
	arr = parse_args(argv, argc, &size);
	a = stack_new(size);
	b = stack_new(size);
	if (!a || !b)
		error_exit(a, b, arr);
	fill_stack(a, arr, size);
	free(arr);
	if (read_and_apply(a, b, &ops))
		check(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
