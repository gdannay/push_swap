#include "push_swap.h"

static int	better_push(t_elem *a_pile, t_elem *b_pile)
{
	t_elem	*tmp;

	tmp = a_pile->next;
	dprintf(1, "HERE");
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

static int	compute_rev(t_elem *a_pile, int size)
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
}

static void	algo(t_elem **a_pile, t_elem **b_pile, int size)
{
	t_elem *last;

	while (check_order(*a_pile, *b_pile))
	{
		if (*a_pile && (*a_pile)->next && (*a_pile)->next->next && !(check_order((*a_pile)->next, NULL)))
			rotate(a_pile, "ra");
		else if ((*a_pile)->nb < (*a_pile)->next->nb)
		{
			dprintf(1, "ICI\n");
			last = *a_pile;
			while (last->next)
				last = last->next;
			if ((*a_pile) && (*a_pile)->nb > last->nb)
			{
				if ((*b_pile) && (*a_pile) && (*b_pile)->nb < (*a_pile)->nb && better_push(*a_pile, *b_pile))
					push(b_pile, a_pile, "pa");
				if (compute_rev(*a_pile, size))
					rev_rotate(a_pile, "rra");
				else
					rotate(a_pile, "ra");
			}
			else
				push(a_pile, b_pile, "pb");
		}
		else if (*a_pile)
			push(a_pile, b_pile, "pb");
		print_pile(*a_pile, *b_pile);
	}
}

void		push_swap(t_elem **a_pile, t_elem **b_pile, int size)
{
	algo(a_pile, b_pile, size);
}
