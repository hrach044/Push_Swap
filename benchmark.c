/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:10:16 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/27 13:26:46 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int n)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write (2, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(2, &c, 1);
}

void	print_disorder(double d)
{
	int		first;
	int		second;

	d *= 100;
	first = (int)d;
	second = (int)((d - first) * 100);
	write(2, "[bench] disorder: ", 18);
	ft_putnbr(first);
	write(2, ".", 1);
	if (second < 10)
		write(2, "0", 1);
	ft_putnbr(second);
	write(2, "%\n", 2);
}

void	print_strategy(t_ops *ops)
{
	write(2, "[bench] strategy: ", 18);
	if (ops->flag == FLAG_SIMPLE)
		write(2, "Simple / O(n2)\n", 15);
	else if (ops->flag == FLAG_MEDIUM)
		write(2, "Medium / O(nsqrtn)\n", 19);
	else if (ops->flag == FLAG_COMPLEX)
		write(2, "Complex / O(nlogn)\n", 19);
	else
		write(2, "Adaptive\n", 9);
}

void	print_ops_1(t_ops *ops)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr(ops->sa);
	write(2, " sb: ", 5);
	ft_putnbr(ops->sb);
	write(2, " ss: ", 5);
	ft_putnbr(ops->ss);
	write(2, " pa: ", 5);
	ft_putnbr(ops->pa);
	write(2, " pb: ", 5);
	ft_putnbr(ops->pb);
	write(2, "\n", 1);
}

void	print_bench(t_ops *ops, double disorder)
{
	print_disorder(disorder);
	print_strategy(ops);
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr(ops->total);
	write(2, "\n", 1);
	print_ops_1(ops);
	write(2, "[bench] ra: ", 12);
	ft_putnbr(ops->ra);
	write(2, " rb: ", 5);
	ft_putnbr(ops->rb);
	write(2, " rr: ", 5);
	ft_putnbr(ops->rr);
	write(2, " rra: ", 6);
	ft_putnbr(ops->rra);
	write(2, " rrb: ", 6);
	ft_putnbr(ops->rrb);
	write(2, " rrr: ", 6);
	ft_putnbr(ops->rrr);
	write(2, "\n", 1);
}
