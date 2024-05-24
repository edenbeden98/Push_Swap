/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:28:52 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/23 10:29:09 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	rev_bubble_sort_arr(int *arr, int size)
{
	int	i;
	int	swaps;

	while (1)
	{
		swaps = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] < arr[i + 1])
			{
				ft_swap(&arr[i], &arr[i + 1]);
				swaps++;
			}
			i++;
		}
		if (swaps == 0)
			break ;
	}
}


void	bubble_sort_arr(int *arr, int size)
{
	int	i;
	int	swaps;

	while (1)
	{
		swaps = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap(&arr[i], &arr[i + 1]);
				swaps++;
			}
			i++;
		}
		if (swaps == 0)
			break ;
	}
}

int	find_median(int_lst *X, int size)
{
	int	median;
	int	arr[size];
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i++] = X->content;
		X = X->next;
	}
	bubble_sort_arr(arr, size);
	if (size % 2 == 0)
		median = arr[(size / 2) - 1];
//		median = (arr[(size / 2)] + arr[(size / 2) - 1]) / 2;
	else
		median = arr[size / 2];
//	ft_printf("median = %d\n", median);
	return (median);
}


