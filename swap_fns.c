/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:28:56 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/16 17:27:44 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_int_lst *stack)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
}

int	sa(t_int_lst *a)
{
	swap(a);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_int_lst *b)
{
	swap(b);
	ft_printf("sb\n");
	return (1);
}

int	ss(t_int_lst *a, t_int_lst *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
	return (1);
}
