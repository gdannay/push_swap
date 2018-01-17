/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balgo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:31:50 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:30:39 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_both(t_elem **a_pile, t_elem **b_pile, t_pile *list)
{
	if ((*a_pile) && (*a_pile)->next && (*a_pile)->next->next
			&& (*a_pile)->next->next
			&& (*a_pile)->next->nb > (*a_pile)->next->next->nb
			&& (*b_pile) && (*b_pile)->next && (*b_pile)->next->next
			&& (*b_pile)->next->nb > (*b_pile)->next->next->nb)
	{
		rotate(a_pile, 0, NULL);
		rotate(b_pile, RR, list);
		swap(a_pile, 0, NULL);
		swap(b_pile, SS, list);
		rev_rotate(a_pile, 0, NULL);
		rev_rotate(b_pile, RRR, list);
	}
	if ((*a_pile) && (*a_pile)->next && (*a_pile)->nb > (*a_pile)->next->nb
		&& (*b_pile) && (*b_pile)->next && (*b_pile)->nb > (*b_pile)->next->nb)
	{
		swap(a_pile, 0, NULL);
		swap(b_pile, SS, list);
	}
}

static void		sort_b(t_elem **b_pile, t_pile *list)
{
	if ((*b_pile) && (*b_pile)->next && (*b_pile)->next->next
		&& (*b_pile)->next->nb > (*b_pile)->next->next->nb)
	{
		rotate(b_pile, RB, list);
		swap(b_pile, SB, list);
		rev_rotate(b_pile, RRB, list);
	}
	if ((*b_pile) && (*b_pile)->next &&
		(*b_pile)->nb > (*b_pile)->next->nb)
		swap(b_pile, SB, list);
}

static void		sort(t_elem **a_pile, t_elem **b_pile, int size, t_pile *list)
{
	if (size > 2 && *a_pile && (*a_pile)->next
			&& (*a_pile)->nb > (*a_pile)->next->nb)
		swap(a_pile, SA, list);
	if (size > 3 && *b_pile && (*b_pile)->next
			&& (*b_pile)->nb > (*b_pile)->next->nb)
		swap(b_pile, SB, list);
	if (size == 6)
		sort_both(a_pile, b_pile, list);
	if (size > 4)
	{
		if ((*a_pile) && (*a_pile)->next && (*a_pile)->next->next
			&& (*a_pile)->next->nb > (*a_pile)->next->next->nb)
		{
			rotate(a_pile, RA, list);
			swap(a_pile, SA, list);
			rev_rotate(a_pile, RRA, list);
		}
		if ((*a_pile) && (*a_pile)->next
				&& (*a_pile)->nb > (*a_pile)->next->nb)
			swap(a_pile, SA, list);
	}
	if (size == 6)
		sort_b(b_pile, list);
}

static int		recursive(t_pile *list, int size, int rest, int ret)
{
	int	i;

	i = -1;
	if (!ret && !check_sort(*(list->a_pile), size, 1))
	{
		while (++i < size)
			push(list->a_pile, list->b_pile, PB, list);
		algobig(list, size + rest, rest, 1);
		return (0);
	}
	else
		algobig(list, size / 2, size % 2, 0);
	return (1);
}

int				algobig(t_pile *list, int size, int rest, int ret)
{
	int i;

	i = -1;
	if (ret && !check_sort(*(list->a_pile), size, 0))
		return (0);
	if (size + rest > 3 && !recursive(list, size, rest, ret))
		return (0);
	else if (size + rest <= 3)
	{
		while (++i < size)
			push(list->a_pile, list->b_pile, 2, list);
		sort(list->a_pile, list->b_pile, size * 2 + rest, list);
		return (0);
	}
	if (ret || (!check_order(*(list->a_pile), NULL)
			&& !check_order(*(list->b_pile), NULL)
			&& check_order(*(list->a_pile), *(list->b_pile))))
		fusiona(list->a_pile, list->b_pile, size, list);
	else if (!ret && check_order(*(list->a_pile), *(list->b_pile)))
		fusionb(list->a_pile, list->b_pile, size, list);
	if (check_order(*(list->a_pile), *(list->b_pile)) && !ret)
		algobig(list, size + rest, rest, 1);
	return (0);
}
