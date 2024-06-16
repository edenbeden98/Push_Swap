/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:53:07 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/24 16:48:15 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	*set;

	set = malloc(sizeof(int) * argc);
	if (!set)
		return (-1);
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (intsetcmp(ft_atoi(argv[i]), set, j))
			return (0);
		set[j++] = ft_atoi(argv[i++]);
	}
	free(set);
	return (1);
}

bool	check_all_integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_issign(argv[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_int_size(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]) && *argv[i] != '0')
			return (false);
		i++;
	}
	return (true);
}

bool	check_input(int argc, char **argv)
{
	if (!check_all_integers(argc, argv))
		return (false);
	if (!check_duplicates(argc, argv))
		return (false);
	if (!check_int_size(argc, argv))
		return (false);
	return (true);
}
