/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:47:19 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/30 14:16:55 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int *arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_bench(char **argv, int argc)
{
	if (argc > 1 && !ft_strcmp(argv[1], "--bench"))
		return (1);
	if (argc > 2 && !ft_strcmp(argv[2], "--bench"))
		return (1);
	return (0);
}

int	parse_flag(char **argv, int argc)
{
	int		i;

	i = 1;
	while (i < 3 && i < argc)
	{
		if (!ft_strcmp(argv[i], "--simple"))
			return (FLAG_SIMPLE);
		else if (!ft_strcmp(argv[i], "--medium"))
			return (FLAG_MEDIUM);
		else if (!ft_strcmp(argv[i], "--complex"))
			return (FLAG_COMPLEX);
		i++;
	}
	return (FLAG_ADAPTIVE);
}

int	*parse_args(char **argv, int argc, int *out_size)
{
	int		start;
	int		*arr;
	int		i;
	int		val;
	char	**args;

	start = get_start_index(argv, argc);
	args = check_str(argv, argc, out_size, start);
	arr = malloc(*out_size * sizeof(int));
	if (!arr)
		error_free(argv, args, arr, start);
	i = 0;
	while (i < *out_size)
	{
		if (!check_arg(args[i], &val))
			error_free(argv, args, arr, start);
		arr[i++] = val;
	}
	free_args(args, argv, start);
	if (has_duplicates(arr, *out_size))
		error_exit(NULL, NULL, arr);
	return (arr);
}
