/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:51 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 13:09:10 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void	rotate(t_int_lst **stack)
{
	t_int_lst	*first;
	t_int_lst	*tmp;

	if (*stack && (*stack)->next)
	{
		first = int_lstnew((*stack)->content);
		if (!first)
			return ;
		int_lstadd_back(stack, first);
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	ra(t_int_lst	**a)
{
	rotate(a);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_int_lst	**b)
{
	rotate(b);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_int_lst **a, t_int_lst **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	return (1);
}
