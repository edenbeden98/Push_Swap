/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:18:03 by eamsalem          #+#    #+#             */
/*   Updated: 2024/07/08 12:18:23 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks)
{
	int_lstclear(&sub_stacks[0]);
	int_lstclear(&sub_stacks[1]);
	int_lstclear(a);
	int_lstclear(b);
	free(a);
	free(b);
}

void	read_input_to_stack(t_int_lst **a, int argc, char **argv)
{
	t_int_lst	*tmp;
	int			i;

	i = 1;
	while (i < argc)
	{
		tmp = int_lstnew(ft_atoi(argv[i]));
		int_lstadd_back(a, tmp);
		i++;
	}
}

int	initialize_stacks(t_int_lst ***a, t_int_lst ***b)
{
	*a = malloc(sizeof(t_int_lst *));
	if (!a)
		return (0);
	*b = malloc(sizeof(t_int_lst *));
	if (!b)
	{
		free(a);
		return (0);
	}
	**a = NULL;
	**b = NULL;
	return (1);
}

bool	sorted(t_int_lst *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}
