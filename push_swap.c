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

void	sort_a(int_lst **a, int_lst **b, int_lst **sub_stacks, int pa_count)
{
	int	size;
	int	pb_count;

	size = sub_stacks[1]->content;
	pb_count = find_pb_count(a, pa_count);
	if (pa_count < 1 || pb_count <= 1)
		return ;
	else if (pb_count == 2)
		ss(*a, *b);
	else if (pb_count == 3)
		sort_a_top3(a);
	else
	{
		sub_stacks[0]->content = pb_count;
		while (sub_stacks[0]->content > 3)
			merge_sort_atob(a, b, sub_stacks);
		if (sub_stacks[0]->content == 3)
			sort_a_top3(a);
		else if (sub_stacks[0]->content == 2)
			sort_a_top2(a);
	}
}

void	sort_b(int_lst **b, int_lst **sub_stacks, int rb_count, int pa_count)
{
	int	prev_sub_stack_size;

	prev_sub_stack_size = sub_stacks[1]->content;
	while (rb_count > 0 && int_lstsize(sub_stacks[1]) > 1)
		rb_count -= rrb(b);
	sub_stacks[1]->content = prev_sub_stack_size - pa_count;
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
	split_atob(a, b, sub_stacks);
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
