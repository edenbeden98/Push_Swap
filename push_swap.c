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

void	read_input_to_stack(int_lst **a, int argc, char ** argv)
{
	int_lst	*tmp;
	int		i;

	i = 1;
	while (i < argc)
	{
		tmp = int_lstnew(ft_atoi(argv[i]));
		int_lstadd_back(a, tmp);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int_lst	**a;

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
	read_input_to_stack(a, argc, argv);
	push_swap(a);
	int_lstclear(a);
	free(a);
}
