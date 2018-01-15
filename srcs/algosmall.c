/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algosmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:20:43 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/15 18:52:46 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.c"

static void push_rotate(t_elem **a, t_elem **b, t_pile *list)
{
	t_elem *max;
	t_elem *min;
	t_elem *lasta;
	t_elem *minb;
	t_elem *maxb;
	t_elem *lastb;

	max = c_max(*a);
	min = c_min(*a);
	lasta = find_last(*a);
	maxb = c_max(*b);
	minb = c_min(*b);
	lastb = find_last(*a);

	while ((*a) && (*b) && ((*a)->nb > (*b)->nb)
			&& (((*b)->nb > lasta->next->nb) || (lasta->next == max)))
	{
		push(b, a, PA, list);
		maxb = c_max(*b);
		minb = c_min(*b);
	}
	if (lastb && lastb->next && (*b) && (*b)->next
			&& ((*b)->nb < (*b)->next->nb || ((*b) == minb
					&& (*b)->next == maxb)) && ((*b)->nb < lastb->next->nb
				|| ((*b) == maxb && lastb->next == min)))
	{
		rotate(a, 0, NULL);
		rotate(b, RR, list);
	}
	else
		rotate(a, RA, list);
}

static void swap_piles(t_elem **a, t_elem **b, t_pile *list)
{
	t_elem *max;
	t_elem *min;
	t_elem *lasta;
	t_elem *minb;
	t_elem *maxb;
	t_elem *lastb;

	max = c_max(*a);
	min = c_min(*a);
	lasta = find_last(*a);
	maxb = c_max(*b);
	minb = c_min(*b);
	lastb = find_last(*a);
	if ((*b) && (*b)->next && (*b)->next->next
			&& ((*b)->nb < (*b)->next->nb
				|| ((*b) == max && (*b)->next == min))
			&& (*b)->nb > lastb->next->nb)
	{
		swap(b, 0, list);
		swap(a, SS, list);
	}
	else
		swap(a, SA, list);
}

static void		rev_rotate_piles(t_elem **a, t_elem **b, t_pile *list)
{
	t_elem *max;
	t_elem *min;
	t_elem *lasta;
	t_elem *minb;
	t_elem *maxb;
	t_elem *lastb;

	max = c_max(*a);
	min = c_min(*a);
	lasta = find_last(*a);
	maxb = c_max(*b);
	minb = c_min(*b);
	lastb = find_last(*a);
	if ((*b) && ((*b)->nb > lastb->next->nb
				|| ((*b) == min && lastb->next == max))
			&& (((*b)->nb < lastb->nb)
				|| ((*b) == max && lastb == min)))
	{
		rev_rotate(a, 0, NULL);
		rev_rotate(a, RRA, list);
	}
	else
		rev_rotate(a, RRA, list);
}

static void		algosmall_next(t_elem **a, t_elem **b, t_pile *list)
{
	t_elem *max;
	t_elem *min;
	t_elem *lasta;
	t_elem *minb;
	t_elem *maxb;
	t_elem *lastb;

	max = c_max(*a);
	min = c_min(*a);
	lasta = find_last(*a);
	maxb = c_max(*b);
	minb = c_min(*b);
	lastb = find_last(*a);
	if (check_order(*a, NULL) && (*a) && (*a)->next
			&& ((*a)->nb < (*a)->next->nb
				|| ((*a) == max && (*a)->next == min))
			&& ((*a)->nb < lasta->next->nb || ((*a) == min && lasta->next == max)))
	{
		while ((*b) && (*b) != maxb)
			rotate(b, RB, list);
		push(a, b, PB, list);
		if ((*a) && (*a)->next && ((*a)->nb < (*a)->next->nb
					|| ((*a) == max && (*a)->next == min))
				&& ((*a)->nb > lasta->next->nb || ((*a) == min && lasta->next == max)))
			rotate(a, RA, list);
	}
	else if ((*a) && (*b) && ((*a)->nb > (*b)->nb)
			&& (((*b)->nb > lasta->next->nb) || lasta->next == max))
		push(b, a, PA, list);
	else
		rotate(a, RA, list);
}

void	algosmall(t_elem **a, t_elem **b, t_pile *list)
{
	t_elem *max;
	t_elem *min;
	t_elem *maxb;
	t_elem *lasta;

	while (check_order(*a, *b))
	{
		lasta = find_last(*a);
		max = c_max(*a);
		min = c_min(*a);
		maxb = c_max(*b);
		if (compute_rev(*a, min, max) && (!(*b) || (maxb && maxb->nb < min->nb)))
		{
			while (check_order(*a, NULL))
				rev_rotate(a, RRA, list);
		}
		else if (check_order(*a, NULL) && (*a) && (*a)->next &&
				((*a)->nb < (*a)->next->nb || ((*a) == max && (*a)->next == min)) &&
				((*a)->nb > lasta->next->nb || ((*a) == min && lasta->next == max)))
			push_rotate(a, b, list);
		else if ((*a) && (*a)->next && ((*a)->nb > (*a)->next->nb
					|| ((*a) == min && (*a)->next == max)))
			swap_piles(a, b, list);
		else if ((*a) && ((*a)->nb < lasta->next->nb || ((*a) == max &&
			lasta->next == min)) && (((*a)->nb > lasta->nb) || ((*a) == min && lasta == max)))
			rev_rotate_piles(a, b, list);
		else
			algosmall_next(a, b, list);

	}
}
