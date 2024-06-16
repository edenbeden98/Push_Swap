/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_fns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:40:37 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 13:31:11 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void	rev_rotate(int_lst **stack)
{
	int_lst	*last;
	int_lst	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		int_lstadd_front(stack, int_lstnew(last->content));
		free(last);
		tmp->next = NULL;
	}
}

int	rra(int_lst **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(int_lst	**b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(int_lst **a, int_lst **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
	return (1);
}
