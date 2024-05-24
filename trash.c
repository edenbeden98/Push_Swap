* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:28:52 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/23 17:13:12 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pb_count(int_lst **A, int pa_count)
{
	int	*arr;
	int	*sorted_arr;
	int i;

	arr = int_lst_to_arr(*A, pa_count);
	if (!arr)
		return (-1);
	sorted_arr = int_lst_to_arr(*A, pa_count);
	if (!sorted_arr)
		return (-1);
	bubble_sort_arr(sorted_arr, pa_count);
//	print_int_arr(arr, pa_count);
//	print_int_arr(sorted_arr, pa_count);
	i = pa_count - 1;
	while (i >= 0)
	{
		if (arr[i] != sorted_arr[i])
			break ;
		i--;
	}
	free(arr);
	free(sorted_arr);
	return (i + 1);
}

int	sort_A_top3(int_lst **A, int_lst **B) 
{
	int	count;

	count = 0;
	if ((*A)->content > (*A)->next->content && (*A)->content > (*A)->next->next->content)
	{
		count += sa(*A);
		count += pb(A, B);
		count += sa(*A);
		count += pa(A, B);
		if ((*A)->content > (*A)->next->content)
			count += sa(*A);
	}
	else
	{
		count += pb(A, B);
		count += sa(*A);
		count += pa(A, B);
		if ((*A)->content > (*A)->next->content)
			count += sa(*A);
	}
	return (count);
}

int	sort_B_top2(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{ 
	int	count;

	count = 0;
	if ((*B)->content < (*B)->next->content)
		count += sb(*B);
	count += pa(A, B);
	count += pa(A, B);
	int_lstdel_front(sub_stack_size_lst);
	return (count);
}

int	sort_B_top3(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 3)
	{
		if (i == 2 && (*A)->content > (*A)->next->content)
			count += sa(*A);
		if (i < 2 && (*B)->content < (*B)->next->content)
			count += sb(*B);
		count += pa(A, B);
		i++;
	}
	int_lstdel_front(sub_stack_size_lst);
	return (count);
}

int	sort_A(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst, int pa_count)
{
	int	size;
	int	i;
	int	pb_count;
	int	operation_count;

//	ft_printf("pa_count = %d\n", pa_count);
	
	size = (*sub_stack_size_lst)->content;
	if (pa_count == 1)
		return (0);
	pb_count = find_pb_count(A, pa_count);
//	ft_printf("pb_count = %d\n", pb_count);
//	if (pb_count == -1)
//		return (-1);
	if (pb_count == 2)
		return(sa(*A));
	else if (pb_count == 3)
		return(sort_A_top3(A, B)); 
	i = 0;
	operation_count = 0;
	while (i < pb_count)
	{
		operation_count += pb(A, B);
		i++;
	}
	if (i > 0)
		int_lstadd_front(sub_stack_size_lst, int_lstnew(pb_count));
	return (operation_count);
}

int	sort_B(int_lst **B, int_lst **sub_stack_size_lst, int rb_count, int pa_count)
{
	int	count;
	int	prev_sub_stack_size;
	
//	ft_printf("rb_count = %d\n", rb_count);
	prev_sub_stack_size = (*sub_stack_size_lst)->content;
	count = 0;
	while (rb_count > 0 && int_lstsize(*sub_stack_size_lst) > 1)
	{
		count += rrb(B);
		rb_count--;
	}
	(*sub_stack_size_lst)->content = prev_sub_stack_size - pa_count;
	return (count);
}

int	split_sub_stack(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	int	operation_count;
	int	pa_count;
	int	rb_count;
	int	median;
	int	size;
	int	max_pa;

	size = (*sub_stack_size_lst)->content;
	median = find_median(*B, size);
//	ft_printf("median = %d\n", median);
	pa_count = 0;
	rb_count = 0;
	operation_count = 0;
	max_pa = size / 2;
//	ft_printf("max_pa = %d\n", max_pa);
	while (size > 0 && pa_count < max_pa)
	{
		if ((*B)->content > median)
			pa_count += pa(A, B);
		else
			rb_count += rb(B);
		size--;
	}
	// Need to stop auto pb for pa: 4 - 6, and handle those cases separately
	// split them into, 2:2 2:3, and 3:3 cases
	operation_count += pa_count + rb_count;
	operation_count += sort_B(B, sub_stack_size_lst, rb_count, pa_count);	
	operation_count += sort_A(A, B, sub_stack_size_lst, pa_count);
	return (operation_count);
}

int	back_track_sort(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	int	count;

	count = 0;
	while (*B)
	{
		print_stacks_both(*A, *B);
		ft_printf("sub stack sizes = ");
		print_stack(*sub_stack_size_lst);
	//	ft_printf("size of B = %d\n", int_lstsize(*B));
		if ((*sub_stack_size_lst)->content == 1)
		{
			count += pa(A, B);
			int_lstdel_front(sub_stack_size_lst);
			continue ;
		}	
		else if ((*sub_stack_size_lst)->content == 2)
			count += sort_B_top2(A, B, sub_stack_size_lst);
		else if ((*sub_stack_size_lst)->content == 3)
			count += sort_B_top3(A, B, sub_stack_size_lst);
		else 
			count += split_sub_stack(A, B, sub_stack_size_lst);
		if (int_lstsize(*B) == 1)
			count += pa(A, B);
	}
	return (count);
}

int	splitA_to_B(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	int	count;
	int	size;
	int	median;
	int	sub_stack_size;

	count = 0;
	while (int_lstsize(*A) > 1)
	{
		size = int_lstsize(*A);
		median = find_median(*A, size);
		sub_stack_size = 0;
		while (size > 0)
		{
			if ((*A)->content > median)
				count += ra(A);
			else
			{
				count += pb(A, B);
				sub_stack_size++;
			}
			size--;
		}
		int_lstadd_front(sub_stack_size_lst, int_lstnew(sub_stack_size));
//		ft_printf("size A = %d\n", int_lstsize(*A));
//		print_stacks_both(*A, *B);
	}
	return (count);
}

void	push_swap(int_lst **A)
{
	// rather than finding count manually, create a fn to read how many lines printed to stdoutput

	int_lst	**B;
	int_lst	**sub_stack_size_lst;
	int		count;

	B = malloc(sizeof(int_lst *));
	if (!B)
		return ;
	*B = NULL;
	
	sub_stack_size_lst = malloc(sizeof(int_lst *));
	if (!sub_stack_size_lst)
		return ;
	*sub_stack_size_lst = NULL;
	count = 0;
//	count += bucket_sort(A, B, sub_stack_size_lst);
//	ft_printf("size A = %d\n", int_lstsize(*A));
//	ft_printf("size B = %d\n", int_lstsize(*B));
	count += splitA_to_B(A, B, sub_stack_size_lst);
//	ft_printf("\n\n\n BREAK		BREAK \n\n\n\n");
//	ft_printf("size B = %d\n", int_lstsize(*B));
//	print_stack(*sub_stack_size_lst);	
	count += back_track_sort(A, B, sub_stack_size_lst);
	
	print_stacks_both(*A, *B);
	ft_printf("no. operations = %d\n\n", count);
	
	int_lstclear(sub_stack_size_lst);
	free(sub_stack_size_lst);
	int_lstclear(B);
	free(B);
}
/*
int	main(int argc, char **argv)
{
	int_lst	**A;
	int_lst	*tmp;
	int		i;

//	if (!check_input(argc, argv))
//	{
//		ft_printf("Error\n");
//		return (1);
//	}
	A = malloc(sizeof(int_lst *));
	if (!A)
		return (0);
	*A = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = int_lstnew(ft_atoi(argv[i]));
		int_lstadd_back(A, tmp);
		i++;
	}
//	print_stack(*A);
	
	push_swap(A);
	int_lstclear(A);
	free(A);
}
*/
