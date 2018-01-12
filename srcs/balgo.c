/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balgo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:31:50 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/12 20:32:27 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_elem *a_pile, t_elem *b_pile, int size)
{
	t_elem *tmp;
	int i;

	tmp = a_pile;
	i = 0;
//	size = size % 2 ? size - 1 : size;
	while (tmp && tmp->next && tmp->nb < tmp->next->nb && ++i < size)
		tmp = tmp->next;
	if (i < size - 1)
	{
		dprintf(1, "RATEORDER1 = %d %d\n", size, i);
		return (0);
	}
	dprintf(1, "PQ = %d %d\n", size, i);
	tmp = b_pile;
	i = 0;
	while (tmp && tmp->next && tmp->nb < tmp->next->nb && ++i < size)
		tmp = tmp->next;
	if (i < size - 1)
	{
		dprintf(1, "RATEORDER2 = %d %d\n", size, i);
		return (0);
	}
	dprintf(1, "PQ = %d %d\n", size, i);
	return (1);
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

void	sort(t_elem **a_pile, t_elem **b_pile, int a_size, int b_size)
{
	dprintf(1, "ICI = %d %d\n", a_size, b_size);
	if (a_size > 1 && *a_pile && (*a_pile)->next
			&& (*a_pile)->nb > (*a_pile)->next->nb)
	{
		swap(a_pile, "sa");
		print_pile(*a_pile, *b_pile);
	}
	if (3 - b_size > 1 && *b_pile && (*b_pile)->next
			&& (*b_pile)->nb > (*b_pile)->next->nb)
	{
		swap(b_pile, "sb");
		print_pile(*a_pile, *b_pile);
	}
	if (a_size + b_size == 3)
	{
		if ((*a_pile)->next->next && (*a_pile)->next->nb > (*a_pile)->next->next->nb)
		{
			rotate(a_pile, "ra");
			swap(a_pile, "sa");
			rev_rotate(a_pile, "rra");
			print_pile(*a_pile, *b_pile);
		}
		if ((*a_pile)->nb > (*a_pile)->next->nb)
		{
			swap(a_pile, "sa");
			print_pile(*a_pile, *b_pile);
		}
	}
	if (a_size % 2)
	{
		if ((*b_pile)->next->next && (*b_pile)->next->nb > (*b_pile)->next->next->nb)
		{
			rotate(b_pile, "rb");
			swap(b_pile, "sb");
			rev_rotate(b_pile, "rrb");
			print_pile(*a_pile, *b_pile);
		}
		if ((*b_pile)->nb > (*b_pile)->next->nb)
		{
			swap(b_pile, "sb");
			print_pile(*a_pile, *b_pile);
		}
	}
}

int		fusiona(t_elem **a_pile, t_elem **b_pile, int size)
{
	t_elem 	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	tmp_a = *a_pile;
	tmp_b = *b_pile;
	i = 0;
	dprintf(1, "FusionSize = %d %d\n", size, (*b_pile)->nb);
	while (++i < size / 2 + size % 2)
	{
		dprintf(1, "FusionSizeA = %d %d\n", size, i);
		if (tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_b->next)
			tmp_b = tmp_b->next;
	}
	i = 0;
	if (tmp_b)
		tmp_b = tmp_b->next;
	if (size % 2)
		tmp_a = tmp_a->next;
//	size = size % 2 ? size - 1 : size;
	while (i < size)
	{
		if ((*b_pile) && (*a_pile) && (*b_pile != tmp_b) &&(*a_pile)->nb > (*b_pile)->nb)
		{
			push(b_pile, a_pile, "pa1");
			print_pile(*a_pile, *b_pile);
		}
		if ((*a_pile) && (*a_pile) == tmp_a)
		{
			rotate(a_pile, "ra4");
			print_pile(*a_pile, *b_pile);
			i++;
			while ((*a_pile) != tmp_b && i < size)
			{
				push(b_pile, a_pile, "pa2");
				print_pile(*a_pile, *b_pile);
				rotate(a_pile, "ra2");
				i++;
				print_pile(*a_pile, *b_pile);
			}
		}
		else
		{
			rotate(a_pile, "ra3");
			print_pile(*a_pile, *b_pile);
		}
		i++;
		dprintf(1, "Recursion = %d %d\n", i, size);
	}
	i = -1;
	while (++i < size)
	{
		rev_rotate(a_pile, "rra3");
		print_pile(*a_pile, *b_pile);
	}
	return (0);
}

int		fusionb(t_elem **a_pile, t_elem **b_pile, int size)
{
	t_elem 	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	tmp_a = *a_pile;
	tmp_b = *b_pile;
	i = 0;
	dprintf(1, "Fusionsize = %d\n", size);
	while (++i < (size / 2) + size % 2)
	{
		dprintf(1, "FusionsizeB = %d %d\n", tmp_a->nb, i);
		if (tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_b->next)
			tmp_b = tmp_b->next;
	}
	tmp_a = tmp_a->next;
	i = 0;
//	size = size % 2 ? size - 1 : size;
	dprintf(1, "LASTTMP = %d %d\n", tmp_a->nb, tmp_b->nb);
	while (i < size)
	{
		if ((*b_pile) && (*a_pile) && (*a_pile) != tmp_a && ((*b_pile)->nb > //(*a_pile)->nb || *b_pile == tmp_b))
		{
			push(a_pile, b_pile, "pb1");
			print_pile(*a_pile, *b_pile);
		}
		if ((*b_pile) && (*b_pile) == tmp_b)
		{
			rotate(b_pile, "rb4");
			print_pile(*a_pile, *b_pile);
			i++;
			while ((*b_pile) != tmp_a && i < size)
			{
				push(a_pile, b_pile, "pb2");
				print_pile(*a_pile, *b_pile);
				rotate(b_pile, "rb2");
				print_pile(*a_pile, *b_pile);
				i++;
			}
		}
		else
		{
			rotate(b_pile, "rb3");
			print_pile(*a_pile, *b_pile);
		}
		i++;
		dprintf(1, "NOOOOON = %d %d\n", i, size);
	}
	i = -1;
	while (++i < size)
	{
		rev_rotate(b_pile, "rrb3");
		print_pile(*a_pile, *b_pile);
	}
	return (0);
}

int		algoa(t_elem **a_pile, t_elem **b_pile, int size, int rest, int ret)
{
	int i;
	int tmp;

	i = -1;
	tmp = c_size(*b_pile);
	dprintf(1, "ICIa = %d %d\n", size, rest);
	if (size > 3)
	{
		dprintf(1, "RET1\n");
		algob(a_pile, b_pile, size / 2, size % 2, 0);
	}
	else
	{
		dprintf(1, "LASIZE = %d\n", size);
		while (++i < size)
		{
			push(a_pile, b_pile, "pb");
			print_pile(*a_pile, *b_pile);
		}
		sort(a_pile, b_pile, size, rest);
		return (0);
	}
	if (ret || (!check_order(*a_pile, NULL, 0) && !check_order(*b_pile, NULL, 0)))
	{
		dprintf(1, "TESTA1 = %d\n", tmp);
		fusiona(a_pile, b_pile, size);
	}
	else
	{
		dprintf(1, "TESTA2 = %d %d\n", tmp, size);
		fusionb(a_pile, b_pile, size);
	}
	if (!check_sort(*a_pile, *b_pile, size - rest) && check_order(*a_pile, *b_pile, 0))
	{
		dprintf(1, "RET2\n");
		algoa(a_pile, b_pile, size + rest, size % 2, 1);
	}
	return (0);
}

int		algob(t_elem **a_pile, t_elem **b_pile, int size, int rest, int ret)
{
	int i;
	int tmp;

	i = -1;
	tmp = c_size(*a_pile);
	dprintf(1, "ICIb = %d %d\n", size, rest);
	if (size + rest > 3)
	{
		dprintf(1, "RET1\n");
		algoa(a_pile, b_pile, size / 2, size % 2, 0);
	}
	else
	{
		dprintf(1, "LASIZE = %d\n", size);
		while (++i < size)
		{
			push(a_pile, b_pile, "pb");
			print_pile(*a_pile, *b_pile);
		}
		sort(a_pile, b_pile, size, rest);
		return (0);
	}
	if (ret || (!check_order(*a_pile, NULL, 0) && !check_order(*b_pile, NULL, 0)))
	{
		dprintf(1, "TESTB2 = %d %d %d\n", tmp, size, ret);
		fusiona(a_pile, b_pile, size);
	}
	else
	{
		dprintf(1, "TESTB1 = %d\n", tmp);
		fusionb(a_pile, b_pile, size);
	}
	if (!check_sort(*a_pile, *b_pile, size - rest) && check_order(*a_pile, *b_pile, 0))
	{
		dprintf(1, "RET2\n");
		algob(a_pile, b_pile, size + rest, size % 2, 1);
	}
	return (0);
}
