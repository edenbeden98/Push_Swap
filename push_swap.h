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

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int		ra(int_lst **a);

int		rb(int_lst **b);

int		rr(int_lst **a, int_lst **b);

int		sa(int_lst *a);

int		sb(int_lst *b);

int		ss(int_lst *a, int_lst *b);

int		pa(int_lst **a, int_lst **b);

int		pb(int_lst **a, int_lst **b);

int		rra(int_lst **a);

int		rrb(int_lst **b);

int		rrr(int_lst **a, int_lst **b);

int		find_median(int_lst *X, int size);

int		find_unordered_count(int_lst **a, int_lst **sub_stacks);

int		find_max_pb(int size);

void	print_int_arr(int *arr, int size); // ADD TO PRINTF

void	print_stack(int_lst *X); // ADD TO PRINTF

void	print_stacks_both(int_lst *a, int_lst *b);

bool	check_input(int argc, char **argv);

bool	check_int_size(int argc, char **argv);

bool	check_all_integers(int argc, char **argv);

int		check_duplicates(int argc, char **argv);

void	sort_a_top2(int_lst **a);

void	sort_a_top3(int_lst **a);

void	sort_b_top2(int_lst **a, int_lst **b, int_lst **sub_stacks);

void	sort_b_top3(int_lst **a, int_lst **b, int_lst **sub_stacks);

void	sort_a_sub_stack(int_lst **a, int_lst **b, int_lst **sub_stacks);

void	push_swap(int_lst **a);

void	merge_sort_atob(int_lst **a, int_lst **b, int_lst **sub_stacks);

void	merge_sort_btoa(int_lst **a, int_lst **b, int_lst **sub_stacks);

void	merge_sort(int_lst **a, int_lst **b, int_lst **sub_stacks);

#endif
