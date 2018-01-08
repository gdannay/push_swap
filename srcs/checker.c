/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:15:52 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/08 17:15:53 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_elem	*a_pile;
	t_elem	*b_pile;
	int		flag;

	flag = 0;
	a_pile = NULL;
	b_pile = NULL;
	if (ac > 1)
	{
		if ((a_pile = check_args(ac, av, &flag)) == NULL
		|| get_command(&a_pile, &b_pile, flag))
			return (1);
		if (check_order(a_pile, b_pile))
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
	}
	del_lst(&a_pile);
	del_lst(&b_pile);
	return (0);
}
