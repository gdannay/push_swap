/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:38:34 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/15 17:41:30 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static void		compute_last(t_elem **tmp_a, t_elem **tmp_b, int size)
{
	int i;

	i = 0;
	while (++i < size / 2)
	{
		if ((*tmp_a)->next)
			(*tmp_a) = (*tmp_a)->next;
		if ((*tmp_b)->next)
			(*tmp_b) = (*tmp_b)->next;
	}
	if (size % 2)
		(*tmp_a) = (*tmp_a)->next;
}

static void	push_rest_a(t_elem **a_pile, t_elem **b_pile, t_pile *list)
{
	push(b_pile, a_pile, 1, list);
	rotate(a_pile, 9, list);
}

static void	push_rest_b(t_elem **a_pile, t_elem **b_pile, t_pile *list)
{
	push(a_pile, b_pile, 2, list);
	rotate(b_pile, 10, list);
}

void		fusiona(t_elem **a_pile, t_elem **b_pile, int size, t_pile *list)
{
	t_elem 	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	i = -1;
	tmp_a = *a_pile;
	tmp_b = *b_pile;
	compute_last(&tmp_a, &(tmp_b), size);
	tmp_b = tmp_b->next;
	while (++i < size)
	{
		if ((*b_pile) && (*a_pile) && (*b_pile != tmp_b) &&(*a_pile)->nb > (*b_pile)->nb)
			push(b_pile, a_pile, 1, list);
		if ((*a_pile) && (*a_pile) == tmp_a)
		{
			rotate(a_pile, 9, list);
			while ((*a_pile) != tmp_b && ++i < size)
				push_rest_a(a_pile, b_pile, list);
		}
		else
			rotate(a_pile, 9, list);
	}
	i = -1;
	while (size != c_size(*a_pile) && ++i < size)
		rev_rotate(a_pile, 6, list);
}

void		fusionb(t_elem **a_pile, t_elem **b_pile, int size, t_pile *list)
{
	t_elem 	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	i = -1;
	tmp_a = *a_pile;
	tmp_b = *b_pile;
	compute_last(&tmp_a, &(tmp_b), size);
	tmp_a = tmp_a->next;
	while (++i < size)
	{
		if ((*b_pile) && (*a_pile) && (*a_pile) != tmp_a && ((*b_pile)->nb > (*a_pile)->nb))
			push(a_pile, b_pile, 2, list);
		if ((*b_pile) && (*b_pile) == tmp_b)
		{
			rotate(b_pile, 10, list);
			while ((*b_pile) != tmp_a && ++i < size)
				push_rest_b(a_pile, b_pile, list);
		}
		else
			rotate(b_pile, 10, list);
	}
	i = -1;
	while (size != c_size (*b_pile) && ++i < size)
		rev_rotate(b_pile, 7, list);
}
