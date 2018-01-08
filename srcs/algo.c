/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:15:44 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/08 19:47:20 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	better_push(t_elem *a_pile, t_elem *b_pile)
{
	t_elem	*tmp;

	tmp = a_pile->next;
	if (a_pile && a_pile->nb == b_pile->nb + 1)
		return (1);
	while (tmp)
	{
		if (tmp->nb < a_pile->nb && tmp->nb > b_pile->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*static int	compute_rev(t_elem *a_pile, int size)
{
	t_elem	*tmp;
	int		i;
	
	tmp = a_pile;
	i = 0;
	while (i < (size / 2 + 1) && tmp->next && tmp->nb < tmp->next->nb)
	{
		i++;
		tmp = tmp->next;
	}
	if (i >= (size / 2 + 1))
		return (1);
	return (0);
}*/

static void	algo(t_elem **a_pile, t_elem **b_pile, int size)
{
	t_elem *last;
	int i;
	(void)size;

	i = 0;
	while (check_order(*a_pile, *b_pile))
	{
		last = *a_pile;
		while (last->next)
			last = last->next;
		if ((*a_pile)->nb > (*a_pile)->next->nb && (*a_pile)->nb > last->nb)
		{
			if ((*b_pile) && (*a_pile)->nb > (*b_pile)->nb
					&& better_push(*a_pile, *b_pile))
				push(b_pile, a_pile, "pa");
			if ((*b_pile) && (*b_pile)->next && (*b_pile)->nb < (*b_pile)->next->nb)
			{
				rotate(b_pile, NULL);
				rotate(a_pile, "rr");
			}
			else
				rotate(a_pile, "ra");
		}
		else if ((*a_pile)->nb > (*a_pile)->next->nb && (*a_pile)->nb < last->nb)
			swap(a_pile, "sa");
		else if (check_order(*a_pile, NULL) && (*a_pile)->nb < (*a_pile)->next->nb && (*a_pile)->nb < last->nb)
		{
			push(a_pile, b_pile, "pb");
			if ((*b_pile) && (*b_pile)->next && (*b_pile)->nb < (*b_pile)->next->nb)
				rotate(b_pile, "rb");
		}
		else if (better_push(*a_pile, *b_pile))
			push(b_pile, a_pile, "pa");
		else
			rotate(a_pile, "ra");
		print_pile(*a_pile, *b_pile);
		i++;
		dprintf(1, "COUP = %d\n", i);
	}
}

void		push_swap(t_elem **a_pile, t_elem **b_pile, int size)
{
	algo(a_pile, b_pile, size);
}
