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

void	merge_sort_atob(int_lst **a, int_lst **b, int_lst **sub_stacks, bool first_merge)
{
	int	pb_count;
	int	ra_count;
	int	median;
	int	size;
	
	size = sub_stacks[0]->content;
	median = find_median(*a, size);
	pb_count = 0;
	ra_count = 0;
	//print_stacks_both(*a, *b);
	//ft_printf("A sub stack size = %d\n", sub_stacks[0]->content);
	//ft_printf("max_pb = %d\n", max_pb);
	//ft_printf("A = ");
	//print_stack(*a);
	while (size > 0/* && pb_count < max_pb*/)
	{
		if ((*a)->content < median)
			pb_count += pb(a, b);
		else
			ra_count += ra(a);
		size--;
	}
	int_lstadd_front(&sub_stacks[1], int_lstnew(pb_count));
	sub_stacks[0]->content = ra_count;
	while (ra_count > 0 && !first_merge)
		ra_count -= rra(a);
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
	//ft_printf("B sub stack size = %d\n", sub_stacks[1]->content);
	//ft_printf("max_pa = %d\n", max_pa);
	//ft_printf("B = ");
	//print_stack(*b);
	while (size > 0 && pa_count < size / 2)
	{
		if ((*b)->content > median)
			pa_count += pa(a, b);
		else
			rb_count += rb(b);
		size--;
	}
	while (rb_count > 0 && int_lstsize(sub_stacks[1]) > 1)
		rb_count -= rrb(b);
	sub_stacks[0]->content = pa_count;
	sub_stacks[1]->content -= pa_count;
	sort_a_sub_stack(a, b, sub_stacks);
}

void	merge_sort(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	while (sub_stacks[0]->content > 3)
		merge_sort_atob(a, b, sub_stacks, true);
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
		if (int_lstsize(*b) == 1)
			pa(a, b);
	}
}

