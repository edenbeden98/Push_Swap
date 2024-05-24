/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:28:52 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/24 13:16:56 by eamsalem         ###   ########.fr       */
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

int	sort_A_top3(int_lst **A)
{
	int	count;
	int	top;
	int mid;
	int bottom;

	count = 0;
	top = (*A)->content;
	mid = (*A)->next->content;
	bottom = (*A)->next->next->content;
	if (top < mid && top < bottom && mid < bottom)
		return (0);
	else if (mid < top && top < bottom)
		return (sa(*A));
	else if (mid > top && mid > bottom)
	{
		count += ra(A);
		count += sa(*A);
		count += rra(A);
		if (top > bottom)
			count += sa(*A);
	}
	else if (top > mid && top > bottom)
	{
		count += sa(*A);
		count += ra(A);
		count += sa(*A);
		count += rra(A);
		if (mid > bottom)
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
	int_lstdel_front(&sub_stack_size_lst[1]);
	return (count);
}

int	sort_B_top3(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	int	count;
	int	top;
	int mid;
	int bottom;

	count = 0;
	top = (*B)->content;
	mid = (*B)->next->content;
	bottom = (*B)->next->next->content;

	if (top > mid && top > bottom)
		return (pa(A, B) + sort_B_top2(A, B, sub_stack_size_lst));
	else if (mid > top && mid > bottom)
	{
		count += sb(*B);
		count += pa(A, B);
		count += sort_B_top2(A, B, sub_stack_size_lst);
		return (count);
	}
	else if (bottom > top && bottom > mid)
	{
		count += pa(A, B);
		count += sb(*B);
		count += pa(A, B);
		count += sa(*A);
		count += pa(A, B);
		if (mid > top)
			count += sa(*A);
	}
	int_lstdel_front(&sub_stack_size_lst[1]);
	return (count);
}


int	find_max_pb(int	size)
{
	if (size == 1)
		return (1);
	else if (size % 2 == 0)
		return (size / 2);
	else
		return ((size / 2) + 1);
}

int	merge_sortA_to_B(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	int	operation_count;
	int	pb_count;
	int	ra_count;
	int	max_pb;
	int	median;
	int	size;

	size = sub_stack_size_lst[0]->content;
	median = find_median(*A, size);
	pb_count = 0;
	ra_count = 0;
	operation_count = 0;
	max_pb = find_max_pb(size); 
	//	ft_printf("max_pa = %d\n", max_pa);
	while (size > 0 && pb_count < max_pb)
	{
		if ((*A)->content > median)
			ra_count += ra(A);
		else
			pb_count += pb(A, B);
		size--;
	}
	operation_count += pb_count + ra_count;
	int_lstadd_front(&sub_stack_size_lst[1], int_lstnew(pb_count));
	sub_stack_size_lst[0]->content = pb_count;
	while (ra_count > 0)
	{
		operation_count += rra(A);
		ra_count--;
	}
	return (operation_count);
}

int	sort_A(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst, int pa_count)
{
	int	size;
	int	pb_count;
	int	operation_count;

	size = sub_stack_size_lst[1]->content;
	pb_count = find_pb_count(A, pa_count);
	if (pa_count < 1 || pb_count <= 1)
		return (0);
	else if (pb_count == 2)
		return(ss(*A, *B));
	else if (pb_count == 3)
		return(sort_A_top3(A)); 
	else
		sub_stack_size_lst[0]->content = pb_count;
	operation_count = 0;
	while (sub_stack_size_lst[0]->content > 3)
		operation_count += merge_sortA_to_B(A, B, sub_stack_size_lst);
	if (sub_stack_size_lst[0]->content == 3)
		operation_count += sort_A_top3(A);
	else if (sub_stack_size_lst[0]->content == 2 && (*A)->content > (*A)->next->content)
		operation_count += sa(*A);
	return (operation_count);
}

int	sort_B(int_lst **B, int_lst **sub_stack_size_lst, int rb_count, int pa_count)
{
	int	count;
	int	prev_sub_stack_size;
	
//	ft_printf("rb_count = %d\n", rb_count);
	prev_sub_stack_size = sub_stack_size_lst[1]->content;
	count = 0;
	while (rb_count > 0 && int_lstsize(sub_stack_size_lst[1]) > 1)
	{
		count += rrb(B);
		rb_count--;
	}
	sub_stack_size_lst[1]->content = prev_sub_stack_size - pa_count;
	return (count);
}

int	merge_sortB_to_A(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	int	operation_count;
	int	pa_count;
	int	rb_count;
	int	median;
	int	size;
	int	max_pa;

	print_stacks_both(*A, *B);
	ft_printf("A sub stack sizes = ");
	print_stack(sub_stack_size_lst[0]);


	size = sub_stack_size_lst[1]->content;
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

int	merge_sort(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	int	count;

	count = 0;
	while (*B)
	{
		print_stacks_both(*A, *B);
		ft_printf("B sub stack sizes = ");
		print_stack(sub_stack_size_lst[1]);
	//	ft_printf("size of B = %d\n", int_lstsize(*B));
		if ((sub_stack_size_lst[1])->content == 1)
		{
			count += pa(A, B);
			int_lstdel_front(&sub_stack_size_lst[1]);
			continue ;
		}	
		else if (sub_stack_size_lst[1]->content == 2)
			count += sort_B_top2(A, B, sub_stack_size_lst);
		else if (sub_stack_size_lst[1]->content == 3)
			count += sort_B_top3(A, B, sub_stack_size_lst);
		else 
			count += merge_sortB_to_A(A, B, sub_stack_size_lst);
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
	int	A_sub_stack_size;
	int	B_sub_stack_size;

	count = 0;
	A_sub_stack_size = sub_stack_size_lst[0]->content;
	while (A_sub_stack_size > 3)
	{
		size = int_lstsize(*A);
		median = find_median(*A, size);
		B_sub_stack_size = 0;
		while (size > 0)
		{
			if ((*A)->content > median)
				count += ra(A);
			else
			{
				count += pb(A, B);
				A_sub_stack_size--;
				B_sub_stack_size++;
			}
			size--;
		}
		int_lstadd_front(&sub_stack_size_lst[1], int_lstnew(B_sub_stack_size));
//		ft_printf("size A = %d\n", int_lstsize(*A));
//		print_stacks_both(*A, *B);
	}
	sort_A_top3(A);
	sub_stack_size_lst[0]->content = A_sub_stack_size;
//	print_stack(sub_stack_size_lst[0]);
//	print_stack(sub_stack_size_lst[1]);
	return (count);
}

void	push_swap(int_lst **A)
{
	// rather than finding count manually, create a fn to read how many lines printed to stdoutput

	int_lst	**B;
	int_lst	*sub_stack_size_lst[2];
	int		count;

	B = malloc(sizeof(int_lst *));
	if (!B)
		return ;
	*B = NULL;
	sub_stack_size_lst[0] = int_lstnew(int_lstsize(*A));
	sub_stack_size_lst[1] = NULL;
	count = 0;
//	count += bucket_sort(A, B, sub_stack_size_lst);
	count += splitA_to_B(A, B, sub_stack_size_lst);
	ft_printf("\n\n\n BREAK		BREAK \n\n\n\n");
//	ft_printf("size B = %d\n", int_lstsize(*B));
//	print_stack(*sub_stack_size_lst);	
	count += merge_sort(A, B, sub_stack_size_lst);
	
	print_stacks_both(*A, *B);
	ft_printf("no. operations = %d\n\n", count);
	
	int_lstclear(&sub_stack_size_lst[0]);
	int_lstclear(&sub_stack_size_lst[1]);
	int_lstclear(B);
	free(B);
}

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

