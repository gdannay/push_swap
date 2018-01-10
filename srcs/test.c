/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:43:32 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/10 15:13:33 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compute_rev(t_elem *a_pile, t_elem *min, t_elem *max)
{
	t_elem	*tmp;
	int		i;
	int		size;

	tmp = a_pile;
	size = 0;
	i = 1;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	tmp = a_pile;
	while (tmp && tmp->next && tmp->nb < tmp->next->nb)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (0);
	if (tmp && tmp == max && tmp->next && tmp->next == min)
		tmp = tmp->next;
	while (tmp && tmp->next && tmp->nb < tmp->next->nb)
		tmp = tmp->next;
	if (tmp->next == NULL && i >= (size / 2 + 1))
		return (1);
	return (0);
}

static t_elem	*find_last(t_elem *a_pile)
{
	t_elem	*last;

	last = a_pile;
	while (last && last->next && last->next->next)
		last = last->next;
	return (last);
}

static int	c_size(t_elem *a_pile)
{
	t_elem	*tmp;
	int		size;

	size = 0;
	tmp = a_pile;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

static	void	call_op(int (*f)(t_elem **, char *), int (*f2)(t_elem **, t_elem **, char *), t_elem **a_pile, t_elem **b_pile, char *aff, int *i)
{
	if (*f)
		f(a_pile, aff);
	else
		f2(a_pile, b_pile, aff);
	print_pile(*a_pile, *b_pile);
	*i = *i + 1;
	dprintf(1, "COUP = %d\n", *i);
}

t_elem	*c_max(t_elem *a_pile)
{
	t_elem *i;
	t_elem *tmp;

	tmp = a_pile;
	i = tmp;
	while (tmp)
	{
		if (tmp->nb > i->nb)
			i = tmp;
		tmp = tmp->next;
	}
	return (i);
}

t_elem	*c_min(t_elem *a_pile)
{
	t_elem *i;
	t_elem *tmp;

	tmp = a_pile;
	i = tmp;
	while (tmp)
	{
		if (tmp->nb < i->nb)
			i = tmp;
		tmp = tmp->next;
	}
	return (i);
}
