/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:34:08 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/15 16:37:51 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int		c_size(t_elem *pile)
{
	t_elem *tmp;
	int size;

	tmp = pile;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);

}

int		check_sort(t_elem *pile, int size, int rev)
{
	int		i;
	t_elem	*tmp;

	tmp = pile;
	i = 0;
	if (rev)
	{
		while (tmp && tmp->next && tmp->nb > tmp->next->nb && ++i < size)
			tmp = tmp->next;
	}
	else if (!rev)
	{
		while (tmp && tmp->next && tmp->nb < tmp->next->nb && ++i < size)
			tmp = tmp->next;
	}
	if (i >= size - 1)
		return (0);
	return (1);
}
