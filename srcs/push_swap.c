#include "push_swap.h"

int		main(int ac, char **av)
{
	t_elem	*a_pile;
	t_elem	*b_pile;
	
	a_pile = NULL;
	b_pile = NULL;
	if (ac > 1)
	{
		if ((a_pile = check_args(ac, av, NULL)) == NULL)
			return (1);
		push_swap(&a_pile, &b_pile, ac - 1);
	}
	del_lst(&a_pile);
	del_lst(&b_pile);
	return (0);
}
