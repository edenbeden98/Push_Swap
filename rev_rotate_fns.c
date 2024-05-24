/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_fns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:40:37 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/24 16:49:45 by eamsalem         ###   ########.fr       */
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

int	rra(int_lst **A)
{
	rev_rotate(A);
	ft_printf("rra\n");
	return (1);
}

int	rrb(int_lst	**B)
{
	rev_rotate(B);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(int_lst **A, int_lst **B)
{
	rev_rotate(A);
	rev_rotate(B);
	ft_printf("rrr\n");
	return (1);
}
/*
int	main(void)
{
	int_list	**A;
	int_list	*tmp;
	int		i;

	A = malloc(sizeof(int_list *));
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
	rra(A);
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
