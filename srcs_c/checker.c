#include "checker.h"

static int	error(t_elem **a_pile, t_elem **b_pile, char **com)
{
	ft_strdel(com);
	write(2, "Error\n", 6);
	del_lst(a_pile);
	del_lst(b_pile);
	return (1);
}

static void	print_pile(t_elem *a_pile, t_elem *b_pile)
{
	t_elem *tmp;

	tmp = a_pile;
	ft_printf("\nA:");
	while (tmp)
	{
		ft_printf(" %d", tmp->nb);
		tmp = tmp->next;
	}
	tmp = b_pile;
	ft_printf("\nB:");
	while (tmp)
	{
		ft_printf(" %d", tmp->nb);
		tmp = tmp->next;
	}
	ft_printf("\n\n");
}

static void	check_order(t_elem *a_pile, t_elem *b_pile)
{
	t_elem	*tmp;

	tmp = a_pile;
	if (b_pile)
		ft_printf("KO\n");
	else
	{
		while (tmp && tmp->next && tmp->nb < tmp->next->nb)
			tmp = tmp->next;
		if (tmp->next == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");

	}
}

int		main(int ac, char **av)
{
	t_elem	*a_pile;
	t_elem	*b_pile;
	char	*com;
	int		flag;

	flag = 0;
	a_pile = NULL;
	b_pile = NULL;
	if (ac > 1)
	{
		if ((a_pile = check_args(ac, av, &flag)) == NULL)
			return (1);
		while (get_next_line(0, &com))
		{
			if (exec_command(&a_pile, &b_pile, com))
				return (error(&a_pile, &b_pile, &com));
			if (flag & F_V)
				print_pile(a_pile, b_pile);
			ft_strdel(&com);
		}
		check_order(a_pile, b_pile);
	}
	del_lst(&a_pile);
	del_lst(&b_pile);
	return (0);
}
