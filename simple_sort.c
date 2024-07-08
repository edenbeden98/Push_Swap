/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:07:16 by eamsalem          #+#    #+#             */
/*   Updated: 2024/07/08 12:07:17 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_3(t_int_lst **a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*a)->content;
	mid = (*a)->next->content;
	bottom = (*a)->next->next->content;
	if (top > mid && top > bottom)
	{
		ra(a);
		if (mid > bottom)
			sa(*a);
	}
	if (mid > top && mid > bottom)
	{
		rra(a);
		if (bottom > top)
			sa(*a);
	}
	if (bottom > top & bottom > mid)
		sa(*a);
}

void	simple_sort(t_int_lst **a)
{
	if (int_lstsize(*a) == 2)
		sa(*a);
	if (int_lstsize(*a) == 3)
		simple_sort_3(a);
}
