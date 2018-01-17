/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:15:52 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 11:21:46 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	checker(int ac, char **av, t_elem **a_pile, t_elem **b_pile)
{
	char	**nb;
	int		ret;
	int		flag;

	nb = NULL;
	ret = 0;
	flag = 0;
	if (ac == 2 && ft_strstr(av[1], " ") &&
			!(nb = ft_strsplit(av[1], ' ')))
		ret = 1;
	if (nb && ((*a_pile = check_args(ft_tablen(nb), nb, &flag)) == NULL
				|| get_command(a_pile, b_pile, flag)))
		ret = 1;
	else if (!nb && ((*a_pile = check_args(ac, av, &flag)) == NULL
				|| get_command(a_pile, b_pile, flag)))
		ret = 1;
	if (!ret && check_order(*a_pile, *b_pile))
		ft_printf("KO\n");
	else if (!ret && !check_order(*a_pile, *b_pile))
		ft_printf("OK\n");
	if (nb)
		ft_tabdel(&nb);
	return (ret);
}

int			main(int ac, char **av)
{
	t_elem	*a_pile;
	t_elem	*b_pile;
	int		ret;

	a_pile = NULL;
	b_pile = NULL;
	ret = 0;
	if (ac > 1)
		ret = checker(ac, av, &a_pile, &b_pile);
	del_lst(&a_pile);
	del_lst(&b_pile);
	return (ret);
}
