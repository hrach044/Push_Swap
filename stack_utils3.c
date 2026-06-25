/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:18:23 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/26 17:06:22 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int		i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	error_exit(t_stack *a, t_stack *b, int *arr)
{
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
	if (arr)
		free(arr);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int	check_arg(char *str, int *val)
{
	long	n;

	if (!is_integer(str))
		return (0);
	n = ft_atoi(str);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	*val = (int)n;
	return (1);
}
