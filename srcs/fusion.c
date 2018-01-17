/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:38:34 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:22:49 by gdannay          ###   ########.fr       */
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

static void		push_rest_a(t_elem **a, t_elem **b, t_pile *list)
{
	push(b, a, 1, list);
	rotate(a, 9, list);
}

static void		push_rest_b(t_elem **a, t_elem **b, t_pile *list)
{
	push(a, b, 2, list);
	rotate(b, 10, list);
}

void			fusiona(t_elem **a, t_elem **b, int size, t_pile *list)
{
	t_elem	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	i = -1;
	tmp_a = *a;
	tmp_b = *b;
	compute_last(&tmp_a, &(tmp_b), size);
	tmp_b = tmp_b->next;
	while (++i < size)
	{
		if ((*b) && (*a) && (*b != tmp_b) && (*a)->nb > (*b)->nb)
			push(b, a, 1, list);
		if ((*a) && (*a) == tmp_a)
		{
			rotate(a, 9, list);
			while ((*a) != tmp_b && ++i < size)
				push_rest_a(a, b, list);
		}
		else
			rotate(a, 9, list);
	}
	i = -1;
	while (size != c_size(*a) && ++i < size)
		rev_rotate(a, 6, list);
}

void			fusionb(t_elem **a, t_elem **b, int size, t_pile *list)
{
	t_elem	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	i = -1;
	tmp_a = *a;
	tmp_b = *b;
	compute_last(&tmp_a, &(tmp_b), size);
	tmp_a = tmp_a->next;
	while (++i < size)
	{
		if ((*b) && (*a) && (*a) != tmp_a && ((*b)->nb > (*a)->nb))
			push(a, b, 2, list);
		if ((*b) && (*b) == tmp_b)
		{
			rotate(b, 10, list);
			while ((*b) != tmp_a && ++i < size)
				push_rest_b(a, b, list);
		}
		else
			rotate(b, 10, list);
	}
	i = -1;
	while (size != c_size(*b) && ++i < size)
		rev_rotate(b, 7, list);
}
