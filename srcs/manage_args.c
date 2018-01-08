/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:16:18 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/08 19:20:30 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static t_elem	*usage(int flag)
{
	ft_printf("checker: illegal option -- %c\n", flag * -1);
	write(2, "usage: checker [-cv] [integers] [commands]\n", 43);
	return (NULL);
}

static int		manage_flag(char *av)
{
	int i;
	int flag;

	flag = 0;
	i = 1;
	if (!av[i])
		return (0);
	while (av[i] && (av[i] == 'c' || av[i] == 'v'))
	{
		if (av[i] == 'c')
			flag = flag | F_C;
		else if (av[i] == 'v')
			flag = flag | F_V;
		i++;
	}
	if (av[i] != '\0')
		return (av[i] * -1);
	return (flag);
}

t_elem			*check_args(int ac, char **av, int *flag)
{
	t_elem	*a_pile;
	t_elem	*tmp;
	int		i;

	a_pile = NULL;
	i = 1;
	while (flag && av[i] && av[i][0] == '-')
	{
		if ((*flag = *flag | manage_flag(av[i])) <= 0)
			return (usage(*flag));
		i++;
	}
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
