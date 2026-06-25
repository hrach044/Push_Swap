/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:07:46 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/30 17:48:12 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*data;
	int		top;
	int		size;
}	t_stack;

typedef struct s_ops
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	int		flag;
	int		bench;
	int		silent;
}	t_ops;

# define FLAG_ADAPTIVE	0
# define FLAG_SIMPLE	1
# define FLAG_MEDIUM	2
# define FLAG_COMPLEX	3

//stack_utils.c
t_stack	*stack_new(int size);
void	stack_free(t_stack *stack);
void	stack_push(t_stack *x, int nbr);
int		stack_pop(t_stack *x);
int		stack_len(t_stack *x);
//
//stack_utils2.c
int		stack_empty(t_stack *x);
int		stack_is_sorted(t_stack *a);
void	normalize(t_stack *a);
int		find_max_index(t_stack *a);
int		find_min_index(t_stack *a);
//
//stack_utils3.c
int		ft_sqrt(int n);
void	error_exit(t_stack *a, t_stack *b, int *arr);
int		ft_strcmp(char *s1, char *s2);
long	ft_atoi(char *str);
int		check_arg(char *str, int *val);
//
//stack_ops_rotate
void	op_sa(t_stack *a, t_ops *ops);
void	op_sb(t_stack *b, t_ops *ops);
void	op_ss(t_stack *a, t_stack *b, t_ops *ops);
void	op_pb(t_stack *a, t_stack *b, t_ops *ops);
void	op_pa(t_stack *a, t_stack *b, t_ops *ops);
void	op_ra(t_stack *a, t_ops *ops);
void	op_rb(t_stack *b, t_ops *ops);
void	op_rr(t_stack *a, t_stack *b, t_ops *ops);
void	op_rra(t_stack *a, t_ops *ops);
void	op_rrb(t_stack *b, t_ops *ops);
void	op_rrr(t_stack *a, t_stack *b, t_ops *ops);
//
//input_parse
int		is_integer(char *str);
int		parse_bench(char **argv, int argc);
int		parse_flag(char **argv, int argc);
int		*parse_args(char **argv, int argc, int *out_size);
//
double	compute_disorder(t_stack *a);
void	ft_putnbr(int n);
void	print_bench(t_ops *ops, double disorder);
void	sort_simple(t_stack *a, t_stack *b, t_ops *ops);
void	sort_medium(t_stack *a, t_stack *b, t_ops *ops);
void	sort_complex(t_stack *a, t_stack *b, t_ops *ops);
void	sort_adaptive(t_stack *a, t_stack *b, t_ops *ops, int size);
void	fill_stack(t_stack *a, int *arr, int size);
void	check(t_stack *a, t_stack *b);
void	sort3(t_stack *a, t_ops *ops);
void	sort5(t_stack *a, t_stack *b, t_ops *ops);
char	**ft_split(char const *s, char c);
char	**check_str(char **argv, int argc, int *sizeout, int start);
void	free_args(char	**args, char	**argv, int start);
int		get_start_index(char **argv, int argc);
void	error_free(char **argv, char **args, int *arr, int start);

#endif