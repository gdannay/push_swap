/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algosmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:20:43 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:26:28 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*find_last(t_elem *pile)
{
	t_elem	*tmp;

	tmp = pile;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static int		better_push(t_elem *a_pile, t_elem *b_pile)
{
	t_elem	*tmp;

	if (a_pile && a_pile->next)
		tmp = a_pile->next;
	if (b_pile && a_pile && a_pile->nb == b_pile->nb + 1)
		return (1);
	while (tmp)
	{
		if (b_pile && tmp->nb < a_pile->nb && tmp->nb > b_pile->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void		algosmall_next(t_elem **a_pile, t_elem **b_pile,
								t_pile *list, t_elem *last)
{
	if (check_order(*a_pile, NULL) && (*a_pile) &&
		(*a_pile)->next && (*a_pile)->nb < (*a_pile)->next->nb
			&& (*a_pile)->nb < last->nb)
	{
		push(a_pile, b_pile, PB, list);
		if ((*b_pile) && (*b_pile)->next && (*b_pile)->nb < (*b_pile)->next->nb)
			rotate(b_pile, RB, list);
	}
	else if ((*b_pile) && better_push(*a_pile, *b_pile))
		push(b_pile, a_pile, PA, list);
	else if ((*a_pile) && (*a_pile)->next && (*a_pile)->nb < (*a_pile)->next->nb
			&& (*a_pile)->nb > last->nb)
		rev_rotate(a_pile, RRA, list);
	else
		rotate(a_pile, RA, list);
}

void			algosmall(t_elem **a_pile, t_elem **b_pile, t_pile *list)
{
	t_elem	*last;

	while (check_order(*a_pile, *b_pile))
	{
		last = find_last(*a_pile);
		if (*a_pile && (*a_pile)->next && (*a_pile)->nb > (*a_pile)->next->nb
				&& (*a_pile)->nb > last->nb)
		{
			if ((*b_pile) && (*a_pile)->nb > (*b_pile)->nb
					&& better_push(*a_pile, *b_pile))
				push(b_pile, a_pile, PA, list);
			rotate(a_pile, RA, list);
		}
		else if ((*a_pile) && (*a_pile)->next &&
				(*a_pile)->nb > (*a_pile)->next->nb && (*a_pile)->nb < last->nb)
			swap(a_pile, SA, list);
		else
			algosmall_next(a_pile, b_pile, list, last);
	}
}
