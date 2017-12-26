#include "checker.h"

int		main(int ac, char **av)
{
	t_elem	*a_pile;

	a_pile = NULL;
	if (ac > 1)
	{
		if ((a_pile = check_args(ac, av)) == NULL)
			return (1);
	}
	return (0);
}
