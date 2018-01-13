/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:15:44 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/13 17:17:14 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.c"

static void	algo(t_elem **a_pile, t_elem **b_pile)
{
	t_elem *max = c_max(*a_pile);
	t_elem *min = c_min(*b_pile);
	t_elem *lasta = find_last(*a_pile);
	t_elem *minb = c_min(*b_pile);
	t_elem *maxb = c_max(*b_pile);
	int size = c_size(*a_pile);
//	t_elem *lastb;
	if (0)
		size = 1;
	int i = 0;

	while (check_order(*a_pile, *b_pile, 0))
	{
		max = c_max(*a_pile);
		min = c_min(*a_pile);
		lasta = find_last(*a_pile);
		maxb = c_max(*b_pile);
		minb = c_min(*b_pile);
		t_elem *lastb = find_last(*a_pile);
		if (compute_rev(*a_pile, min, max) && (!(*b_pile) || (maxb && maxb->nb < min->nb)))
		{
			dprintf(1, "TEST1\n");
			while (check_order(*a_pile, NULL, 0))
				call_op(&rev_rotate, NULL, a_pile, b_pile, "rra", &i);
		}
		else if (check_order(*a_pile, NULL, 0) && (*a_pile) && (*a_pile)->next && ((*a_pile)->nb < (*a_pile)->next->nb || ((*a_pile) == max && (*a_pile)->next == min))  && ((*a_pile)->nb > lasta->next->nb || ((*a_pile) == min && lasta->next == max)))
		{
			dprintf(1, "TEST2\n");
			while ((*a_pile) && (*b_pile) && ((*a_pile)->nb > (*b_pile)->nb) && (((*b_pile)->nb > lasta->next->nb) || (lasta->next == max)))
			{
				call_op(NULL, &push, b_pile, a_pile, "pa", &i);
				maxb = c_max(*b_pile);
				minb = c_min(*b_pile);
			}
			if (lastb && lastb->next && (*b_pile) && (*b_pile)->next && ((*b_pile)->nb < (*b_pile)->next->nb || ((*b_pile) == minb && (*b_pile)->next == maxb)) && ((*b_pile)->nb < lastb->next->nb || ((*b_pile) == maxb && lastb->next == min)))
			{
				call_op(&rotate, NULL, a_pile, b_pile, NULL, &i);
				i--;
				call_op(&rotate, NULL, b_pile, a_pile, "rr", &i);
			}
			else
				call_op(&rotate, NULL, a_pile, b_pile, "ra", &i);
		}
		else if ((*a_pile) && (*a_pile)->next && ((*a_pile)->nb > (*a_pile)->next->nb || ((*a_pile) == min && (*a_pile)->next == max)))
		{
			dprintf(1, "TEST3\n");
			if ((*b_pile) && (*b_pile)->next && (*b_pile)->next->next && ((*b_pile)->nb < (*b_pile)->next->nb || ((*b_pile) == max && (*b_pile)->next == min)) && (*b_pile)->nb > lastb->next->nb)
			{
				call_op(&swap, NULL, a_pile, b_pile, "ss", &i);
				i--;
				call_op(&swap, NULL, b_pile, a_pile, NULL, &i);
			}
			else
				call_op(&swap, NULL, a_pile, b_pile, "sa", &i);
		}
		else if ((*a_pile) && ((*a_pile)->nb < lasta->next->nb || ((*a_pile) == max && lasta->next == min)) && (((*a_pile)->nb > lasta->nb) || ((*a_pile) == min && lasta == max)))
		{
			dprintf(1, "TEST4\n");
			if ((*b_pile) && ((*b_pile)->nb > lastb->next->nb || ((*b_pile) == min && lastb->next == max)) && (((*b_pile)->nb < lastb->nb) || ((*b_pile) == max && lastb == min)))
			{
				call_op(&rev_rotate, NULL, a_pile, b_pile, "rrr", &i);
				i--;
				call_op(&rev_rotate, NULL, b_pile, a_pile, NULL, &i);
			}
			else
				call_op(&rev_rotate, NULL, a_pile, b_pile, "rra", &i);
		}
		else if (check_order(*a_pile, NULL, 0) && (*a_pile) && (*a_pile)->next && ((*a_pile)->nb < (*a_pile)->next->nb || ((*a_pile) == max && (*a_pile)->next == min))  && ((*a_pile)->nb < lasta->next->nb || ((*a_pile) == min && lasta->next == max)))
		{
			dprintf(1, "TEST5\n");
			while ((*b_pile) && (*b_pile) != maxb)
				call_op(&rotate, NULL, b_pile, a_pile, "rb", &i);
			call_op(NULL, &push, a_pile, b_pile, "pb", &i);
			if ((*a_pile) && (*a_pile)->next && ((*a_pile)->nb < (*a_pile)->next->nb || ((*a_pile) == max && (*a_pile)->next == min))  && ((*a_pile)->nb > lasta->next->nb || ((*a_pile) == min && lasta->next == max)))
			call_op(&rotate, NULL, a_pile, b_pile, "ra", &i);
		}
		else if ((*a_pile) && (*b_pile) && ((*a_pile)->nb > (*b_pile)->nb) && (((*b_pile)->nb > lasta->next->nb) || lasta->next == max))
		{
			dprintf(1, "TEST6\n");
			call_op(NULL, &push, b_pile, a_pile, "pa", &i);
		}
		else
			call_op(&rotate, NULL, a_pile, b_pile, "ra", &i);
	}
}

int			push_swap(t_elem **pile_a, t_elem **pile_b, int size)
{
	t_pile	*list;

	if (0)
	algo(pile_a, pile_b);
	if ((list = (t_pile *)malloc(sizeof(t_pile))) == NULL)
		return (1);
	list->a_pile = pile_a;
	list->b_pile = pile_b;
	algoa(list, size, 0, 1);
	return (0);
}
