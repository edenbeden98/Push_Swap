/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:45:32 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/22 15:45:57 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int_lst *X)
{
	while (X)
	{
		ft_printf("%d, ", X->content);
		X = X->next;
	}
	ft_printf("\n");
}

void	print_stacks_both(int_lst *A, int_lst *B)
{
	ft_printf("A = ");
	print_stack(A);
	ft_printf("B = ");
	print_stack(B);
}

void	print_int_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(*arr, 1);
		write(1, ", ", 2);
		arr++;
		i++;
	}
	write(1, "\n", 1);
}
