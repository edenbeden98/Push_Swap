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
	int	size;
	int	median;
	int	max_pb;
	int	pb_count;
	int	ra_count;

	size = sub_stacks[0]->content;
	median = find_median(*a, size);
	max_pb = find_max_pb(size);
	pb_count = 0;
	ra_count = 0;
	while (pb_count < max_pb)
	{
		if ((*a)->content > median)
			ra_count += ra(a);
		else
			pb_count += pb(a, b);
	}
	while (ra_count > 0 && int_lstsize(sub_stacks[0]) > 1)
		ra_count -= rra(a);
	sub_stacks[0]->content -= pb_count;
	int_lstadd_front(&sub_stacks[1], int_lstnew(pb_count));
}

void	merge_sort_btoa(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	int	size;
	int	median;
	int	pa_count;
	int	rb_count;

	size = sub_stacks[1]->content;
	median = find_median(*b, size);
	pa_count = 0;
	rb_count = 0;
	while (pa_count < size / 2)
	{
		if ((*b)->content > median)
			pa_count += pa(a, b);
		else
			rb_count += rb(b);
	}
	while (rb_count > 0 && int_lstsize(sub_stacks[1]) > 1)
		rb_count -= rrb(b);
	int_lstadd_front(&sub_stacks[0], int_lstnew(pa_count));
	sub_stacks[1]->content -= pa_count;
	sort_a_sub_stack(a, b, sub_stacks);
}

void	merge_sort(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	while (sub_stacks[0]->content > 3)
		merge_sort_atob(a, b, sub_stacks);
	sort_a_sub_stack(a, b, sub_stacks);
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
	}
}
