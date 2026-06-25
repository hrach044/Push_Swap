/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:48:21 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/30 17:48:39 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**check_str(char **argv, int argc, int *sizeout, int start)
{
	char	**result;
	int		count;

	if (argc == start + 1 && is_list(argv[start]))
	{
		result = ft_split(argv[start], ' ');
		count = 0;
		while (result[count])
			count++;
		*sizeout = count;
		return (result);
	}
	*sizeout = argc - start;
	return (argv + start);
}

void	free_args(char	**args, char	**argv, int start)
{
	int	i;

	if (args == argv + start)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	get_start_index(char **argv, int argc)
{
	int	start;

	start = 1;
	while (start < argc && start < 3
		&& argv[start][0] == '-' && argv[start][1] == '-')
		start++;
	return (start);
}

void	error_free(char **argv, char **args, int *arr, int start)
{
	free_args(args, argv, start);
	error_exit(NULL, NULL, arr);
}
