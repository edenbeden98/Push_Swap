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

static void	rotate(int_lst **stack)
{
	int_lst	*first;
	int_lst	*tmp;

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

int	ra(int_lst	**A)
{
	rotate(A);
	ft_printf("ra\n");
	return (1);
}

int	rb(int_lst	**B)
{
	rotate(B);
	ft_printf("rb\n");
	return (1);
}

int	rr(int_lst **A, int_lst **B)
{
	rotate(A);
	rotate(B);
	ft_printf("rr\n");
	return (1);
}
/*
int	main(void)
{
	int_lst	**A;
	int_lst	*tmp;
	int		i;

	A = malloc(sizeof(int_lst *));
	if (!A)
		return (0);
	*A = NULL;
	i = 0;
	while (i < 4)
	{
		tmp = int_lstnew(i);
		ft_printf("%d", tmp->content);
		int_lstadd_back(A, tmp);
		i++;
	}
	ft_printf("\n", 1);
	ra(A);
	i = 0;
	tmp = *A;
	while (i < 4)
	{
		printf("%d", tmp->content);
		tmp = tmp->next;
		i++;
	}
	int_lstclear(A);
	free(A);
}*/
