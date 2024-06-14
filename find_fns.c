/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:59:10 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 16:12:19 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pb_count(int_lst **a, int_lst **sub_stacks)
{
	int	*arr;
	int	*sorted_arr;
	int	size;
	int	i;

	size = sub_stacks[0]->content;
	//ft_printf("size = %d\n", size);
	arr = int_lst_to_arr(*a, size);
	if (!arr)
		return (-1);
	sorted_arr = int_lst_to_arr(*a, size);
	if (!sorted_arr)
		return (-1);
	bubble_sort_arr(sorted_arr, size);
	i = size - 1;
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

int	find_median(int_lst *x, int size)
{
	int	median;
	int	arr[1000];
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i++] = x->content;
		x = x->next;
	}
	bubble_sort_arr(arr, size);
	if (size % 2 == 0)
		median = arr[(size / 2) - 1];
	else
		median = arr[size / 2];
	//ft_printf("median = %d\n", median);
	return (median);
}

int	find_max_pb(int size)
{
	//ft_printf("size = %d\n", size);
	if (size == 1)
		return (1);
	else if (size % 2 == 0)
		return (size / 2);
	else
		return ((size / 2) + 1);
}
