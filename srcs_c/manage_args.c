#include "checker.h"

static t_elem	*new_elem(char *av, t_elem **a_pile, t_elem *tmp)
{
	long	nb;
	t_elem	*new;
	int		i;

	i = 0;
	if (!av || !av[0])
		return (NULL);
	if (av[0] && (av[0] == '-' || av[0] == '+'))
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0')
		return (NULL);
	nb = ft_atol(av);
	if (nb < INT_MIN || nb > INT_MAX)
		return (NULL);
	if ((new = (t_elem *)malloc(sizeof(t_elem))) == NULL)
		return (NULL);
	new->nb = (int)nb;
	new->next = NULL;
	if (*a_pile == NULL)
		*a_pile = new;
	else
		tmp->next = new;
	return (new);	
}

static int		check_double(t_elem *a_pile, int n)
{
	t_elem *tmp;

	tmp = a_pile;
	while (tmp->next)
	{
		if (tmp->nb == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_elem			*check_args(int ac, char **av)
{
	t_elem	*a_pile;
	t_elem	*tmp;
	int		i;

	a_pile = NULL;
	i = 1;
	while (i < ac)
	{
		if ((tmp = new_elem(av[i], &a_pile, tmp)) == NULL
		|| check_double(a_pile, tmp->nb))
		{
			del_lst(&a_pile);
			write(2, "Error\n", 6);
			return (NULL);
		}
		i++;
	}
	tmp = a_pile;
	return (a_pile);
}
