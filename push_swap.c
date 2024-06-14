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

void	sort_a_sub_stack(int_lst **a, int_lst **b, int_lst **sub_stacks)
{
	int	size;

	size = find_unordered_count(a, sub_stacks);
	if (size <= 1)
		return ;
	else if (size == 2)
		sa(*a);
	else if (size == 3)
		sort_a_top3(a);
	else
	{
		while (sub_stacks[0]->content > 3)
			merge_sort_atob(a, b, sub_stacks, false);
		if (sub_stacks[0]->content == 3)
			sort_a_top3(a);
		else if (sub_stacks[0]->content == 2)
			sort_a_top2(a);
	}
}

void	sort_b_sub_stack(int_lst **b, int_lst **sub_stacks, int rb_count)
{
	while (rb_count > 0 && int_lstsize(sub_stacks[1]) > 1)
		rb_count -= rrb(b);
	sub_stacks[1]->content -= sub_stacks[0]->content;
}

void	push_swap(int_lst **a)
{
	int_lst	**b;
	int_lst	*sub_stacks[2];

	b = malloc(sizeof(int_lst *));
	if (!b)
		return ;
	*b = NULL;
	sub_stacks[0] = int_lstnew(int_lstsize(*a));
	sub_stacks[1] = NULL;
	merge_sort(a, b, sub_stacks);
	print_stacks_both(*a, *b);
	int_lstclear(&sub_stacks[0]);
	int_lstclear(&sub_stacks[1]);
	int_lstclear(b);
	free(b);
}

int	main(int argc, char **argv)
{
	int_lst	**a;
	int_lst	*tmp;
	int		i;

	if (argc < 2)
		return (1);
	if (!check_input(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	a = malloc(sizeof(int_lst *));
	if (!a)
		return (1);
	*a = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = int_lstnew(ft_atoi(argv[i]));
		int_lstadd_back(a, tmp);
		i++;
	}
	push_swap(a);
	int_lstclear(a);
	free(a);
}
