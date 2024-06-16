/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_lst_fns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:26:36 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 13:24:59 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int_lst	*int_lstnew(int content)
{
	int_lst	*lst;

	lst = (int_lst *)malloc(sizeof(int_lst));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	int_lstadd_front(int_lst **lst, int_lst *new)
{
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;	
	}
	*lst = new;
}	

void	int_lstdel_front(int_lst **lst)
{
	int_lst *tmp;

	if (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
		if (*lst)
			(*lst)->prev = NULL;
		else
			*lst = NULL;
	}
}

int		int_lstsize(int_lst *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);	
}

int_lst	*int_lstlast(int_lst *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void		int_lstadd_back(int_lst **lst, int_lst *new)
{
	if (*lst)
	{
		int_lstlast(*lst)->next = new;
		new->prev = int_lstlast(*lst);
	}
	else
		*lst = new;
}

void		int_lstclear(int_lst **lst)
{
	int_lst	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
