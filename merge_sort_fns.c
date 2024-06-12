/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_fns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:05:10 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 16:06:26 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_atob(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	int	pb_count;
	int	ra_count;
	int	max_pb;
	int	median;
	int	size;

	size = sub_stacks[0]->content;
	median = find_median(*a, size);
	pb_count = 0;
	ra_count = 0;
	max_pb = find_max_pb(size);
	while (size > 0 && pb_count < max_pb)
	{
		if ((*a)->content > median)
			ra_count += ra(a);
		else
			pb_count += pb(a, b);
		size--;
	}
	int_lstadd_front(&sub_stacks[1], int_lstnew(pb_count));
	sub_stacks[0]->content = pb_count;
	while (ra_count > 0)
		ra_count -= rra(a);
}

void	merge_sort_btoa(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	int	pa_count;
	int	rb_count;
	int	median;
	int	size;
	int	max_pa;

	size = sub_stacks[1]->content;
	median = find_median(*b, size);
	pa_count = 0;
	rb_count = 0;
	max_pa = size / 2;
	while (size > 0 && pa_count < max_pa)
	{
		if ((*b)->content > median)
			pa_count += pa(a, b);
		else
			rb_count += rb(b);
		size--;
	}
	sort_b(b, sub_stacks, rb_count, pa_count);
	sort_a(a, b, sub_stacks, pa_count);
}

void	merge_sort(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	while (*b)
	{
		if ((sub_stacks[1])->content == 1)
		{
			pa(a, b);
			int_lstdel_front(&sub_stacks[1]);
			continue ;
		}
		else if (sub_stacks[1]->content == 2)
			sort_b_top2(a, b, sub_stacks);
		else if (sub_stacks[1]->content == 3)
			sort_b_top3(a, b, sub_stacks);
		else
			merge_sort_btoa(a, b, sub_stacks);
		if (int_lstsize(*b) == 1)
			pa(a, b);
	}
}

void	split_atob(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	int	size;
	int	median;
	int	a_size;
	int	pb_count;

	a_size = int_lstsize(*a);
	while (a_size > 3)
	{
		size = int_lstsize(*a);
		median = find_median(*a, size);
		pb_count = 0;
		while (size > 0)
		{
			if ((*a)->content > median)
				ra(a);
			else
			{
				pb_count += pb(a, b);
				a_size--;
			}
			size--;
		}
		int_lstadd_front(&sub_stacks[1], int_lstnew(pb_count));
	}
	sort_a(a, b, sub_stacks, a_size);
}
