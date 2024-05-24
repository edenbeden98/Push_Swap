/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:32:54 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/24 16:24:00 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H

# define	PUSH_SWAP_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int			ra(int_lst **A);

int			rb(int_lst **B);

int			rr(int_lst **A, int_lst **B);

int			sa(int_lst *A);

int			sb(int_lst *B);

int			ss(int_lst *A, int_lst *B);

int			pa(int_lst **A, int_lst **B);

int			pb(int_lst **A, int_lst **B);

int			rra(int_lst **A);

int			rrb(int_lst **B);

int 		rrr(int_lst **A, int_lst **B);

int			s_bubble_sort(int_lst **A, int_lst **B);

int			sort(int_lst **A, int_lst **B, int index);

int			find_median(int_lst *X, int size);

void		bubble_sort_arr(int *arr, int size);

void		rev_bubble_sort_arr(int *arr, int size);

void		ft_swap(int *a, int *b);

int			*int_lst_to_arr(int_lst *X, int size);

int			rot_n_push(int_lst **A, int_lst **B, int roll_count);

int			rev_rot_n_push(int_lst **A, int_lst **B, int rot_count);

int			fill_bucket(int_lst **A, int_lst **B, int bucket_size);

int			bucket_sort(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst);

void		print_int_arr(int *arr, int size); // ADD TO LIBFT

void		print_stack(int_lst *X); // ADD TO LIBFT

void		print_stacks_both(int_lst *A, int_lst *B);

void		print_int_arr(int *arr, int size);

//int			find_next_smallest(int_lst *B);

//int			find_next_largest(int_lst *X);

bool		check_input(int argc, char **argv);

bool		check_int_size(int argc, char **argv);

bool		check_all_integers(int argc, char **argv);

int			check_duplicates(int argc, char **argv);

#endif
