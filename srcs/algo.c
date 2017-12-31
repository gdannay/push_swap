#include "push_swap.h"

static void	algo(t_elem **a_pile, t_elem **b_pile, int size, int rev)
{
	t_elem *last;

	last = *a_pile;
	while (check_order(*a_pile, *b_pile))
	{
		if ((*a_pile)->nb > (*a_pile)->next->nb)
			swap(a_pile);
		else
		{
			while (last->next)
				last = last->next;
			if ((*a_pile)->nb > last->nb)
			{
				if (rev)
					rev_rotate(a_pile);
				else
					rotate(a_pile);
			}
		}
		print_pile(*a_pile, *b_pile);
		if (rev)
			rev = size;
	}
}

void		push_swap(t_elem **a_pile, t_elem **b_pile, int size)
{
	int		i;
	t_elem	*tmp;
	int		rev;

	i = 0;
	rev = 0;
	tmp = *a_pile;
	while (i < (size / 2 + 1) && tmp->next && tmp->nb < tmp->next->nb)
	{
		i++;
		tmp = tmp->next;
	}
	if (i >= (size / 2 + 1))
		rev = 1;
	algo(a_pile, b_pile, size, rev);
}
