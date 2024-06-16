/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:27:16 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 16:27:20 by eamsalem         ###   ########.fr       */
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

void	push_swap(t_int_lst **a, t_int_lst **b, t_int_lst **sub_stacks)
{
	while (sub_stacks[0]->content > 3)
		merge_sort_atob(a, b, sub_stacks);
	sort_a_sub_stack(a, b, sub_stacks);
	while (*b)
	{
		if ((sub_stacks[1])->content == 1)
		{
			pa(a, b);
			int_lstdel_front(&sub_stacks[1]);
			continue ;
		}
		else if (sub_stacks[1]->content == 2)
			sort_b_top2(a, b, sub_stacks);
		else if (sub_stacks[1]->content == 3)
			sort_b_top3(a, b, sub_stacks);
		else
			merge_sort_btoa(a, b, sub_stacks);
	}
}

void	read_input_to_stack(t_int_lst **a, int argc, char **argv)
{
	t_int_lst	*tmp;
	int		i;

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

int	main(int argc, char **argv)
{
	t_int_lst	**a;
	t_int_lst	**b;
	t_int_lst	*sub_stacks[2];

	if (argc < 2)
		return (1);
	if (!check_input(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!initialize_stacks(&a, &b))
		return (1);
	read_input_to_stack(a, argc, argv);
	sub_stacks[0] = int_lstnew(argc - 1);
	sub_stacks[1] = NULL;
	push_swap(a, b, sub_stacks);
	print_stacks_both(*a, *b);
	free_mem(a, b, sub_stacks);
}
