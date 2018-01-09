/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:15:44 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/09 21:50:43 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	better_push(t_elem *a_pile, t_elem *b_pile)
  {
  t_elem	*tmp;

  if (a_pile && a_pile->next && b_pile)
  {
  tmp = a_pile->next;
  if (a_pile && a_pile->nb == b_pile->nb + 1)
  return (1);
  while (tmp)
  {
  if (tmp->nb < a_pile->nb && tmp->nb > b_pile->nb)
  return (0);
  tmp = tmp->next;
  }
  }
  return (0);
  }*/

/*static int	compute_rev(t_elem *a_pile)
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
  while (i <= (size / 2) && tmp->next && tmp->nb > tmp->next->nb)
  {
  i++;
  tmp = tmp->next;
  }
  if (i >= (size / 2 + 1))
  return (1);
  return (0);
  }*/

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

static void	algo(t_elem **a_pile, t_elem **b_pile)
{
	int size;
	int i;
	long rep;
	t_elem *last;
	t_elem *lastb;

	size = c_size(*a_pile);
	last = find_last(*a_pile);
	lastb = find_last(*b_pile);
	rep = REP_INIT;
	i = 0;
	while (check_order(*a_pile, *b_pile, 0))
	{
		dprintf(1, "ICI5\n");
		while ((*a_pile)->next && !(check_order(*a_pile, *b_pile, 0) ^ check_order(*a_pile, NULL, 0)) && (c_size(*b_pile) < (size / 2) || (*a_pile)->nb < (*a_pile)->next->nb))
		{
			size = c_size(*a_pile);
			dprintf(1, "ICI6\n");
			last = find_last(*a_pile);
			lastb = find_last(*b_pile);
			if (check_order(*a_pile, *b_pile, 0) && ((*a_pile) && (*a_pile)->next && (*a_pile)->next->next && (*a_pile)->nb < last->next->nb) && (*a_pile)->nb > last->nb)
			{
				rev_rotate(a_pile, "rra1");
				print_pile(*a_pile, *b_pile);
				swap(a_pile, "sa1");
				print_pile(*a_pile, *b_pile);
				rotate(a_pile, "ra1");
				print_pile(*a_pile, *b_pile);
				i++;
				rotate(a_pile, "ra1");
				print_pile(*a_pile, *b_pile);
				i++;
				last = find_last(*a_pile);
				i += 2;
			}
			while (check_order(*a_pile, NULL, 0) && (*a_pile) && (*a_pile)->next && (*a_pile)->nb > last->next->nb)
			{
				rotate(a_pile, "ralala");
				print_pile(*a_pile, *b_pile);
				i++;
				last = find_last(*a_pile);
			}
			if (check_order(*a_pile, *b_pile, 0) && (*a_pile) && (*a_pile)->next && (*a_pile)->nb > (*a_pile)->next->nb)
			{
				swap(a_pile, "sa");
				i++;
				print_pile(*a_pile, *b_pile);
			}
			lastb = find_last(*b_pile);
			if (check_order(*a_pile, *b_pile, 0) && (*a_pile) && (*b_pile) && (*b_pile)->next && (*b_pile)->next->next && (*a_pile)->nb > lastb->next->nb && (*a_pile)->nb < (*b_pile)->nb && (*a_pile)->nb < (*b_pile)->next->nb)
			{
				rev_rotate(b_pile, "rrb");
				i++;
				print_pile(*a_pile, *b_pile);
				push(a_pile, b_pile, "pb");
				i++;
				print_pile(*a_pile, *b_pile);
				rotate(b_pile, "rb");
				print_pile(*a_pile, *b_pile);
				i++;
			}
			else if (check_order(*a_pile, *b_pile, 0))
			{
				push(a_pile, b_pile, "pb");
				i++;
				print_pile(*a_pile, *b_pile);
			}
			if (check_order(*a_pile, *b_pile, 0) && (*b_pile) && (*b_pile)->next && (*b_pile)->next->next && (*b_pile)->nb < (*b_pile)->next->nb && (*b_pile)->nb > (*b_pile)->next->next->nb)
			{
				swap(b_pile, "sb1");
				i++;
				print_pile(*a_pile, *b_pile);
			}
			while (check_order(*a_pile, *b_pile, 0) && (*b_pile) && (*b_pile)->next && (*b_pile)->nb < (*b_pile)->next->nb)
			{
				rotate(b_pile, "rb");
				print_pile(*a_pile, *b_pile);
				i++;
			}
		}
		while (check_order(*a_pile, *b_pile, 0) && check_order(*a_pile, *b_pile, 0) && (*b_pile) && (*a_pile) && (*a_pile)->nb < (*b_pile)->nb)
		{
			rotate(a_pile, "ra");
			print_pile(*a_pile, *b_pile);	
			i++;
		}
		while (check_order(*a_pile, *b_pile, 0) && (*b_pile) && (*a_pile)->nb > (*b_pile)->nb)
		{
			push(b_pile, a_pile, "pa");
			print_pile(*a_pile, *b_pile);	
			i++;
		}
		while (check_order(*a_pile, *b_pile, 0) && (*a_pile) && (*a_pile)->next && (*a_pile)->nb < (*a_pile)->next->nb)
		{
			rotate(a_pile, "rahaha");
			last = find_last(*a_pile);
			if (rep == REP_INIT && last && last->next && (*b_pile) && (*a_pile) && (*b_pile)->nb < last->next->nb && (*b_pile)->nb < (*a_pile)->nb)
			{
				rep = (*b_pile)->nb;
				rotate(b_pile, "rb");
				print_pile(*a_pile, *b_pile);
				i++;
				last = find_last(*a_pile);
			}
			while (check_order(*a_pile, *b_pile, 0) && last && last->next && (*b_pile) && (*a_pile) && (*b_pile)->nb < last->next->nb && (*b_pile)->nb < (*a_pile)->nb && (*b_pile)->nb != rep)
			{
				rotate(b_pile, "rb");
				print_pile(*a_pile, *b_pile);
				i++;
				last = find_last(*a_pile);
			}
			if ((*b_pile) && rep == (*b_pile)->nb)
			{
				rep = REP_INIT;
				break;
			}
			while (check_order(*a_pile, *b_pile, 0) && last && (*a_pile) && (*b_pile) && last->next->nb && (*b_pile)->nb < (*a_pile)->nb && (*b_pile)->nb < last->next->nb)
			{
				rotate(a_pile, "ra");
				print_pile(*a_pile, *b_pile);	
				i++;
				last = find_last(*a_pile);
			}
			while (check_order(*a_pile, *b_pile, 0) && last && last->next && (*a_pile) && (*b_pile) && (*a_pile)->nb > (*b_pile)->nb && ((*b_pile)->nb > last->next->nb || !(check_order(*a_pile, NULL, 0))))
			{
				push(b_pile, a_pile, "pa");
				print_pile(*a_pile, *b_pile);	
				i++;
				last = find_last(*a_pile);
			}
			print_pile(*a_pile, *b_pile);
			i++;
		}
		dprintf(1, "COUP = %d\n", i);
	}
}

/*static void	algo(t_elem **a_pile, t_elem **b_pile, int size)
  {
  t_elem *last;
  t_elem *lastb;
  t_elem *tmp;
  int max;
  int i;
  (void)size;

  i = 0;
  while (check_order(*a_pile, *b_pile, 0))
  {
  last = find_last(*a_pile);
  if ((*a_pile) && (*a_pile)->next && (*a_pile)->next->next && (*a_pile)->nb < last->next->nb && (*a_pile)->nb > last->nb)
  {
  while (((*a_pile) && (*a_pile)->next && (*a_pile)->next->next && (*a_pile)->nb < last->next->nb))
  {
  rev_rotate(a_pile, "rra1");
  print_pile(*a_pile, *b_pile);
  swap(a_pile, "sa1");
  print_pile(*a_pile, *b_pile);
  last = find_last(*a_pile);
  i += 2;
  }
  }
  last = find_last(*a_pile);
  if ((*a_pile) && (*a_pile)->next && (*a_pile)->nb > last->next->nb)
  {
  rotate(a_pile, "ralala");
  print_pile(*a_pile, *b_pile);
  i++;
  last = find_last(*a_pile);
  }
  if ((*a_pile) && (*a_pile)->next && (*a_pile)->nb > (*a_pile)->next->nb && (*a_pile)->nb < last->next->nb)
  {
  swap(a_pile, "sa2");
  print_pile(*a_pile, *b_pile);
  i++;
  }
  last = find_last(*a_pile);
  if (check_order(*a_pile, NULL, 0) && (*a_pile) && (*a_pile)->next && (*a_pile)->nb < (*a_pile)->next->nb && (*a_pile)->nb < last->next->nb)
  {
  dprintf(1, "ICI");
  lastb = find_last(*b_pile);
  if (lastb)
  lastb = lastb->next;
  if (*b_pile && lastb && (*b_pile)->next && (*b_pile)->next->next && (*a_pile)->nb < (*b_pile)->nb && (*a_pile)->nb > lastb->nb)
  {
  while ((*b_pile)->nb > (*a_pile)->nb)
  {
  rotate(b_pile, "rb10");
  print_pile(*a_pile, *b_pile);
  i++;
  }
  }
  push(a_pile, b_pile, "pb4");
  print_pile(*a_pile, *b_pile);
  i++;
  lastb = find_last(*b_pile);
  if (lastb)
  lastb = lastb->next;
  if (lastb && *b_pile && (*b_pile)->next && (*b_pile)->next->next && (*b_pile)->nb < lastb->nb && (*b_pile)->nb < (*b_pile)->next->nb)
  {
  rotate(b_pile, "rb3");
  print_pile(*a_pile, *b_pile);
  i++;	
  }
  if (*b_pile && (*b_pile)->next && (*b_pile)->nb < (*b_pile)->next->nb)
  {
  swap(b_pile, "sb9");
  print_pile(*a_pile, *b_pile);
i++;
}
while ((*a_pile)->nb < (*b_pile)->nb)
{
	push(a_pile, b_pile, "pb5");
	print_pile(*a_pile, *b_pile);
	i++;
}
tmp = (*b_pile);
max = tmp->nb;
while (tmp)
{
	if (tmp->nb > max)
		max = tmp->nb;
	tmp = tmp->next;
}
if (compute_rev(*b_pile))
{
	while ((*b_pile)->nb != max)
	{
		rev_rotate(b_pile, "rrb5");
		print_pile(*a_pile, *b_pile);
		i++;
	}
}
else
{
	while ((*b_pile)->nb != max)
	{
		rotate(b_pile, "rb5");
		print_pile(*a_pile, *b_pile);
		i++;
	}
}
if ((*a_pile) && (*a_pile)->next && (*a_pile)->nb > (*a_pile)->next->nb && (*a_pile)->nb > last->next->nb)
{
	rotate(a_pile, "ra42");
	print_pile(*a_pile, *b_pile);
	i++;
	last = find_last(*a_pile);
}
}		
while ((*a_pile) && (*b_pile) && (*a_pile)->nb > (*b_pile)->nb)
{
	push(b_pile, a_pile, "pa6");
	print_pile(*a_pile, *b_pile);
	i++;
}
else
{
	rotate(a_pile, "ra7");
	print_pile(*a_pile, *b_pile);
	i++;
}
dprintf(1, "COUP = %d\n", i);
}
}*/

void		push_swap(t_elem **a_pile, t_elem **b_pile, int size)
{
	(void)size;
	algo(a_pile, b_pile);
}
