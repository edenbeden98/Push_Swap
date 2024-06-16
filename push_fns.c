/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:16:43 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/16 17:26:08 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_int_lst **a, t_int_lst **b)
{
	t_int_lst	*tmp;

	if (*b)
	{
		if ((*b)->next)
			tmp = (*b)->next;
		else
			tmp = NULL;
		(*b)->next = (*a);
		(*a) = (*b);
		(*b) = tmp;
		ft_printf("pa\n");
	}
	return (1);
}

int	pb(t_int_lst **a, t_int_lst **b)
{
	t_int_lst	*tmp;

	if (*a)
	{
		if ((*a)->next)
			tmp = (*a)->next;
		else
			tmp = NULL;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = tmp;
		ft_printf("pb\n");
	}
	return (1);
}

/*
int	main(void)
{
	int_list	**A;
	int_list	**B;
	int_list	*tmp;
	int			i;

	A = malloc(sizeof(int_list *));
	if (!A)
		return (0);
	*A = NULL;
	i = 0;
	ft_printf("A = ");
	while (i < 1)
	{
		tmp = int_lstnew(i);
		ft_printf("%d", tmp->content);
		int_lstadd_back(A, tmp);
		i++;
	}
	B = malloc(sizeof(int_list *));
	if (!B)
		return (0);
	*B = NULL;
	ft_printf("\nB = ");
	i = 5;
	while (i < 9)
	{
		tmp = int_lstnew(i);
		ft_printf("%d", tmp->content);
		int_lstadd_back(B, tmp);
		i++;
	}
	ft_printf("\n");
	pa(A, B);
	i = 0;
	tmp = *A;
	ft_printf("A = ");
	while (i < 1)
	{
		ft_printf("%d", tmp->content);
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = *B;
	ft_printf("\nB = ");
	while (i < 3)
	{
		ft_printf("%d", tmp->content);
		tmp = tmp->next;
		i++;
	}
	int_lstclear(A);
	free(A);
	int_lstclear(B);
	free(B);
}*/
