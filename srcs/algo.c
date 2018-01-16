/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:15:44 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/16 19:59:48 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			push_swap(t_elem **pile_a, t_elem **pile_b, int size)
{
	t_pile	*list;

	if ((list = (t_pile *)malloc(sizeof(t_pile))) == NULL)
		return (1);
	list->a_pile = pile_a;
	list->b_pile = pile_b;
	list->com = NULL;
	if (size < 7)
		algosmall(pile_a, pile_b, list);
	else
		algobig(list, size, 0, 1);
	if (list->com)
	list->com->prev = NULL;
	manage_commands(&(list->com));
	free(list);
	return (0);
}
