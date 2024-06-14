/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:28:52 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 13:10:17 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_top2(int_lst **a)
{
	if ((*a)->content > (*a)->next->content)
		sa(*a);
}

void	sort_a_top3(int_lst **a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*a)->content;
	mid = (*a)->next->content;
	bottom = (*a)->next->next->content;
	if (top < mid && top < bottom && mid < bottom)
		return ;
	else if (top > mid)
		(sa(*a));
	if (bottom > mid && bottom > top)
		return ;
	ra(a);
	sa(*a);
	rra(a);
	if (mid > top && mid > bottom && top > bottom)
		sa(*a);
	else if (top > mid && top > bottom && mid > bottom)
		sa(*a);
}

void	sort_b_top2(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	if ((*b)->content < (*b)->next->content)
		sb(*b);
	pa(a, b);
	pa(a, b);
	int_lstdel_front(&sub_stacks[1]);
}

void	sort_b_top3(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*b)->content;
	mid = (*b)->next->content;
	bottom = (*b)->next->next->content;
	if (bottom > top && bottom > mid)
	{
		pa(a, b);
		sb(*b);
		pa(a, b);
		sa(*a);
		pa(a, b);
		if (mid > top)
			sa(*a);
		int_lstdel_front(&sub_stacks[1]);
		return ;
	}
	else if (mid > top && mid > bottom)
		sb(*b);
	pa(a, b);
	sort_b_top2(a, b, sub_stacks);
}

void	sort_a_sub_stack(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	int	size;

	size = find_unordered_count(a, sub_stacks);
	if (size <= 1)
		return ;
	else if (size == 2)
		sa(*a);
	else if (size == 3)
		sort_a_top3(a);
	else
	{
		while (sub_stacks[0]->content > 3)
			merge_sort_atob(a, b, sub_stacks, false);
		if (sub_stacks[0]->content == 3)
			sort_a_top3(a);
		else if (sub_stacks[0]->content == 2)
			sort_a_top2(a);
	}
}