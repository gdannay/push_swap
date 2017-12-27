#include "checker.h"

static int	error(t_elem **a_pile, t_elem **b_pile, char **com)
{
	ft_strdel(com);
	write(2, "Error\n", 6);
	del_lst(a_pile);
	del_lst(b_pile);
	return (1);
}

int		main(int ac, char **av)
{
	t_elem	*a_pile;
	t_elem	*b_pile;
	char	*com;

	a_pile = NULL;
	b_pile = NULL;
	if (ac > 1)
	{
		if ((a_pile = check_args(ac, av)) == NULL)
			return (1);
		while (get_next_line(0, &com))
		{
			if (exec_command(&a_pile, &b_pile, com))
				return (error(&a_pile, &b_pile, &com));
			ft_strdel(&com);
		}
	}
	return (0);
}
