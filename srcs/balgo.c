/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balgo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:31:50 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/15 15:23:40 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		c_size(t_elem *pile)
{
	t_elem *tmp;
	int size;

	tmp = pile;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);

}

int		check_sort(t_elem *pile, int size, int rev)
{
	int		i;
	t_elem	*tmp;

	tmp = pile;
	i = 0;
//	dprintf(1, "I GET SIZE %d\n", size);
	if (rev)
	{
		while (tmp && tmp->next && tmp->nb > tmp->next->nb && ++i < size)
		{
			tmp = tmp->next;
//			dprintf(1, "Compare %d %d\n", tmp->nb, tmp->next->nb);
		}
	}
	else if (!rev)
	{
		while (tmp && tmp->next && tmp->nb < tmp->next->nb && ++i < size)
		{
			tmp = tmp->next;
//			dprintf(1, "Compare %d %d\n", tmp->nb, tmp->next->nb);
		}
	}
//	dprintf(1, "FINAL = %d %d\n", i, size);
	if (i >= size - 1)
		return (0);
	return (1);
}

void	sort(t_elem **a_pile, t_elem **b_pile, int a_size, int b_size, t_pile *list)
{
//	dprintf(1, "ICI = %d %d\n", a_size, b_size);
	if (a_size > 0 && *a_pile && (*a_pile)->next
			&& (*a_pile)->nb > (*a_pile)->next->nb)
	{
		swap(a_pile, "sa", 3, list);
//		print_pile(*a_pile, *b_pile);
	}
	if (a_size > 1 && *b_pile && (*b_pile)->next
			&& (*b_pile)->nb > (*b_pile)->next->nb)
	{
		swap(b_pile, "sb", 4, list);
//		print_pile(*a_pile, *b_pile);
	}
	if (a_size + b_size == 3 && a_size == 3)
	{
		if ((*a_pile)->next->next && (*a_pile)->next->nb > (*a_pile)->next->next->nb && (*b_pile)->next->next && (*b_pile)->next->nb > (*b_pile)->next->next->nb)
		{
			rotate(a_pile, NULL, 0, NULL);
			rotate(b_pile, "rr", 11, list);
			swap(a_pile, NULL, 0, NULL);
			swap(b_pile, "ss", 5, list);
			rev_rotate(a_pile, NULL, 0, NULL);
			rev_rotate(b_pile, "rrr", 8, list);
//			print_pile(*a_pile, *b_pile);
		}
		if ((*a_pile)->nb > (*a_pile)->next->nb && (*b_pile)->nb > (*b_pile)->next->nb)
		{
			swap(a_pile, NULL, 0, NULL);
			swap(b_pile, "ss", 5, list);
//			print_pile(*a_pile, *b_pile);
		}
	}
	if (a_size + b_size == 3)
	{
		if ((*a_pile)->next->next && (*a_pile)->next->nb > (*a_pile)->next->next->nb)
		{
			rotate(a_pile, "ra", 9, list);
			swap(a_pile, "sa", 3, list);
			rev_rotate(a_pile, "rra", 6, list);
//			print_pile(*a_pile, *b_pile);
		}
		if ((*a_pile)->nb > (*a_pile)->next->nb)
		{
			swap(a_pile, "sa", 3, list);
//			print_pile(*a_pile, *b_pile);
		}
	}
	if (a_size == 3)
	{
		if ((*b_pile)->next->next && (*b_pile)->next->nb > (*b_pile)->next->next->nb)
		{
			rotate(b_pile, "rb", 10, list);
			swap(b_pile, "sb", 4, list);
			rev_rotate(b_pile, "rrb", 7, list);
//			print_pile(*a_pile, *b_pile);
		}
		if ((*b_pile)->nb > (*b_pile)->next->nb)
		{
			swap(b_pile, "sb", 4, list);
//			print_pile(*a_pile, *b_pile);
		}
	}
}

int		fusiona(t_elem **a_pile, t_elem **b_pile, int size, t_pile *list)
{
	t_elem 	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	tmp_a = *a_pile;
	tmp_b = *b_pile;
	i = 0;
//	dprintf(1, "FusionSize = %d %d\n", size, (*b_pile)->nb);
	while (++i < size / 2)
	{
		if (tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_b->next)
			tmp_b = tmp_b->next;
//		dprintf(1, "FusionSizeA = %d %d %d %d\n", tmp_a->nb, tmp_b->nb, i, size / 2);
	}
	i = 0;
	tmp_b = tmp_b->next;
	if (size % 2)
		tmp_a = tmp_a->next;
//	if (tmp_b)
//		dprintf(1, "LASTTMP = %d %d\n", tmp_a->nb, tmp_b->nb);
	while (i < size)
	{
		if ((*b_pile) && (*a_pile) && (*b_pile != tmp_b) &&(*a_pile)->nb > (*b_pile)->nb)
		{
			push(b_pile, a_pile, "pa", 1, list);
//			print_pile(*a_pile, *b_pile);
		}
		if ((*a_pile) && (*a_pile) == tmp_a)
		{
			rotate(a_pile, "ra", 9, list);
//			print_pile(*a_pile, *b_pile);
			i++;
			while ((*a_pile) != tmp_b && i < size)
			{
				push(b_pile, a_pile, "pa", 1, list);
//				print_pile(*a_pile, *b_pile);
				rotate(a_pile, "ra", 9, list);
				i++;
//				print_pile(*a_pile, *b_pile);
			}
		}
		else
		{
			rotate(a_pile, "ra", 9, list);
//			print_pile(*a_pile, *b_pile);
		}
		i++;
//		dprintf(1, "Recursion = %d %d\n", i, size);
	}
	i = -1;
	if (size != c_size(*a_pile))
	{
		while (++i < size)
		{
			rev_rotate(a_pile, "rra", 6, list);
//			print_pile(*a_pile, *b_pile);
		}
	}
	return (0);
}

int		fusionb(t_elem **a_pile, t_elem **b_pile, int size, t_pile *list)
{
	t_elem 	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	tmp_a = *a_pile;
	tmp_b = *b_pile;
	i = 0;
//	dprintf(1, "Fusionsize = %d\n", size);
	while (++i < size / 2)
	{
		if (tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_b->next)
			tmp_b = tmp_b->next;
//		dprintf(1, "FusionSizeB = %d %d %d %d\n", tmp_a->nb, tmp_b->nb, i, size / 2);
	}
	tmp_a = tmp_a->next;
	if (size % 2)
		tmp_a = tmp_a->next;
	i = 0;
//	dprintf(1, "LASTTMP = %d %d\n", tmp_a->nb, tmp_b->nb);
	while (i < size)
	{
		if ((*b_pile) && (*a_pile) && (*a_pile) != tmp_a && ((*b_pile)->nb > (*a_pile)->nb))
		{
			push(a_pile, b_pile, "pb", 2, list);
//			print_pile(*a_pile, *b_pile);
		}
		if ((*b_pile) && (*b_pile) == tmp_b)
		{
			rotate(b_pile, "rb", 10, list);
//			print_pile(*a_pile, *b_pile);
			i++;
			while ((*b_pile) != tmp_a && i < size)
			{
				push(a_pile, b_pile, "pb", 2, list);
//				print_pile(*a_pile, *b_pile);
				rotate(b_pile, "rb", 10, list);
//				print_pile(*a_pile, *b_pile);
				i++;
			}
		}
		else
		{
			rotate(b_pile, "rb", 10, list);
//			print_pile(*a_pile, *b_pile);
		}
		i++;
//		dprintf(1, "NOOOOON = %d %d\n", i, size);
	}
	i = -1;
	if (size != c_size(*b_pile))
	{
		while (++i < size)
		{
			rev_rotate(b_pile, "rrb", 7, list);
//			print_pile(*a_pile, *b_pile);
		}
	}
	return (0);
}

int		algoa(t_pile *list, int size, int rest, int ret)
{
	int i;

	i = -1;
//	dprintf(1, "ICIa = %d %d\n", size, rest);
	if (ret && !check_sort(*(list->a_pile), size, 0))
		return (0);
	if (size + rest > 3)
	{
		if (!ret && !check_sort(*(list->a_pile), size, 1))
		{
			while (++i < size)
			{
				push(list->a_pile, list->b_pile, "pb", 2, list);
//				print_pile(*(list->a_pile), *(list->b_pile));
			}
			algoa(list, size + rest, rest, 1);
			return (0);
		}
		else
		{
//			dprintf(1, "RET1\n");
			algoa(list, size / 2, size % 2, 0);
		}
	}
	else
	{
//		dprintf(1, "LASIZE = %d\n", size);
		while (++i < size)
		{
			push(list->a_pile, list->b_pile, "pb", 2, list);
//			print_pile(*(list->a_pile), *(list->b_pile));
		}
		sort(list->a_pile, list->b_pile, size, rest, list);
		return (0);
	}
	if (ret || (!check_order(*(list->a_pile), NULL, 0) && !check_order(*(list->b_pile), NULL, 0) && check_order(*(list->a_pile), *(list->b_pile), 0)))
	{
//		dprintf(1, "TESTA1 = %d\n", size);
		fusiona(list->a_pile, list->b_pile, size, list);
	}
	else if (!ret && check_order(*(list->a_pile), *(list->b_pile), 0))
	{
//		dprintf(1, "TESTA2 = %d\n", size);
		fusionb(list->a_pile, list->b_pile, size, list);
	}
//	dprintf(1, "TEST = %d %d\n", size, rest);
	if (check_order(*(list->a_pile), *(list->b_pile), 0) && !ret)
	{
//		dprintf(1, "RET2\n");
		algoa(list, size + rest, rest, 1);
	}
	return (0);
}
