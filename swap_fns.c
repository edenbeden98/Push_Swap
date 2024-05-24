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

static void	swap(int_lst *stack)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
}

int	sa(int_lst *A)
{
	swap(A);
	ft_printf("sa\n");
	return (1);
}

int	sb(int_lst *B)
{
	swap(B);
	ft_printf("sb\n");
	return (1);
}

int	ss(int_lst *A, int_lst *B)
{
	swap(A);
	swap(B);
	ft_printf("ss\n");
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
	swap(*A);
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
