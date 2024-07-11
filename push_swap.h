/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:32:54 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 13:13:34 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

int		ra(t_int_lst **a);

int		rb(t_int_lst **b);

int		rr(t_int_lst **a, t_int_lst **b);

int		sa(t_int_lst *a);

int		sb(t_int_lst *b);

int		ss(t_int_lst *a, t_int_lst *b);

int		pa(t_int_lst **a, t_int_lst **b);

int		pb(t_int_lst **a, t_int_lst **b);

int		rra(t_int_lst **a);

int		rrb(t_int_lst **b);

int		rrr(t_int_lst **a, t_int_lst **b);

int		find_median(t_int_lst *X, int size);

int		find_unordered_count(t_int_lst **a, t_int_lst **sub_stacks);

int		find_max_pb(int size);

void	print_int_arr(int *arr, int size);

void	print_stack(t_int_lst *X);

void	print_stacks_both(t_int_lst *a, t_int_lst *b);

bool	check_input(int argc, char **argv);

bool	check_int_size(int argc, char **argv);

bool	check_all_integers(int argc, char **argv);

bool	check_duplicates(int argc, char **argv);

void	sort_a_top2(t_int_lst **a);

void	sort_a_top3(t_int_lst **a);

void	sort_b_top2(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks);

void	sort_b_top3(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks);

void	sort_a_sub_stack(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks);

void	push_swap(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks);

void	merge_sort_atob(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks);

void	merge_sort_btoa(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks);

bool	sorted(t_int_lst *a);

void	simple_sort(t_int_lst **a);

void	simple_sort_3(t_int_lst **a);

void	free_mem(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks);

void	read_input_to_stack(t_int_lst **a, int argc, char **argv);

int		initialize_stacks(t_int_lst ***a, t_int_lst ***b);

bool	sorted(t_int_lst *a);

#endif
