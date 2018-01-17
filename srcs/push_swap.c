/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:16:34 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 11:21:57 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		push_swap(t_elem **pile_a, t_elem **pile_b, int size)
{
	t_pile	*list;

	if ((list = (t_pile *)malloc(sizeof(t_pile))) == NULL)
		return (1);
	list->a_pile = pile_a;
	list->b_pile = pile_b;
	list->com = NULL;
	if (size < 7)
		algosmall(pile_a, pile_b, list);
	else
		algobig(list, size, 0, 1);
	if (list->com)
		list->com->prev = NULL;
	manage_commands(&(list->com));
	free(list);
	return (0);
}

int				main(int ac, char **av)
{
	t_elem	*a_pile;
	t_elem	*b_pile;
	char	**nb;

	a_pile = NULL;
	b_pile = NULL;
	nb = NULL;
	if (ac > 1)
	{
		if (ac == 2 && ft_strstr(av[1], " ") &&
			!(nb = ft_strsplit(av[1], ' ')))
			return (1);
		if (nb && !(a_pile = check_args(ft_tablen(nb), nb, NULL)))
			return (1);
		else if (!nb && (a_pile = check_args(ac, av, NULL)) == NULL)
			return (1);
		if (nb)
			ft_tabdel(&nb);
		push_swap(&a_pile, &b_pile, ac - 1);
	}
	del_lst(&a_pile);
	del_lst(&b_pile);
	return (0);
}
