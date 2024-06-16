
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:34:24 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/15 13:13:40 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h> 

int	*int_arrlcpy(int *dest, int *src, int size)
{
	int	i;
	int *tmp;

	if (!src || !dest)
		return (NULL);
	i = 0;
	tmp = dest;
	while (i < size)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	return (dest);
}
