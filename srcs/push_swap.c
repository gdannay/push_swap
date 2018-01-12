/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:16:34 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/12 15:08:07 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
