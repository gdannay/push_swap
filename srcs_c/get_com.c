#include "checker.h"

int			exec_command(t_elem **a_pile, t_elem **b_pile, char *com)
{
	if (!(ft_strcmp(com, "sa")))
		return (swap(a_pile));
	else if (!(ft_strcmp(com, "sb")))
		return (swap(b_pile));
	else if (!(ft_strcmp(com, "ss")))
	{
		swap(a_pile);
		return (swap(b_pile));
	}
	else if (!(ft_strcmp(com, "pa")))
		return (push(b_pile, a_pile));
	else if (!(ft_strcmp(com, "pb")))
		return (push(a_pile, b_pile));
	else if (!(ft_strcmp(com, "ra")))
		return (rotate(a_pile));
	else if (!(ft_strcmp(com, "rb")))
		return (rotate(b_pile));
	else if (!(ft_strcmp(com, "rr")))
	{
		rotate(a_pile);
		return (rotate(b_pile));
	}
	else if (!(ft_strcmp(com, "rra")))
		return (rev_rotate(a_pile));
	else if (!(ft_strcmp(com, "rrb")))
		return (rev_rotate(b_pile));
	else if (!(ft_strcmp(com, "rrr")))
	{
		rev_rotate(a_pile);
		return (rev_rotate(b_pile));
	}
	else
		return (1);
}
