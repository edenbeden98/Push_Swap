/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:06:50 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/23 17:04:31 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_n_push(int_lst **A, int_lst **B, int rot_count)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < rot_count)
	{
		count += ra(A);
		i++;
	}
	count += pb(A, B);
	return (count);
}

int	rev_rot_n_push(int_lst **A, int_lst **B, int rot_count)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < rot_count + 1)
	{	
		count += rra(A);
		i++;
	}
	count += pb(A, B);
	return (count);
}

int	fill_bucket(int_lst **A, int_lst **B, int bucket_size)
{
	int	i;
	int	*arr;
	int	arr_size;
	int	count;
	int	rot_count;
	int_lst *first;
	int_lst *last;

	arr_size = int_lstsize(*A);
	arr = int_lst_to_arr(*A, arr_size);
	bubble_sort_arr(arr, arr_size);
//	print_int_arr(arr, bucket_size);
	i = 0;
	count = 0;
	while (i < bucket_size)
	{
		first = *A;
		last = int_lstlast(*A);
		rot_count = 0;
		while (1)
		{
		//	write(1, "1\n", 2);
			if (int_lstsize(*A) == 0)
				break ;
			if (intsetcmp(first->content, arr, bucket_size))
			{
				count += rot_n_push(A, B, rot_count);
				break ;
			}
			else if (intsetcmp(last->content, arr, bucket_size))
			{
				count += rev_rot_n_push(A, B, rot_count);
				break ;
			}
			rot_count++;
			first = first->next;
			last = last->prev;
		}
		i++;
	}
	free(arr);
	return (count);
}

int	bucket_sort(int_lst **A, int_lst **B, int_lst **sub_stack_size_lst)
{
	// NOT SORTING NUMBERS PROPERLY

	int	bucket_count;
	int	bucket_size;
	int	count;
	int	i;
	
	bucket_count = 4; //create fn to get count depending on size
	bucket_size = int_lstsize(*A) / bucket_count;
	count = 0;
	i = 0;
	while (i < bucket_count - 1)
	{
		ft_printf("size B = %d\n", int_lstsize(*B));
		count += fill_bucket(A, B, bucket_size);
		int_lstadd_front(&sub_stack_size_lst[1], int_lstnew(bucket_size));
		sub_stack_size_lst[0]->content -= bucket_size;
		ft_printf(" \n\n BREAK \n\n\n");
		i++;
	}
	print_stack(sub_stack_size_lst[0]);
	print_stack(sub_stack_size_lst[1]);
	return (count);
}
