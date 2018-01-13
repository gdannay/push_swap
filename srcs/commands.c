/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:15:58 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/13 17:26:15 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		push(t_elem **lose, t_elem **get, char *print, int com)
{
	t_elem *tmp;

	(void)com;
	if (*lose)
	{
		tmp = *lose;
		*lose = (*lose)->next;
		tmp->next = *get;;
		(*get) = tmp;
	}
	if (print)
		ft_printf("%s\n", print);
	return (0);
}

int		swap(t_elem **pile, char *print, int com)
{
	t_elem *tmp;

	(void)com;
	if (*pile && (*pile)->next)
	{
		tmp = (*pile)->next;
		(*pile)->next = tmp->next;
		tmp->next = (*pile);
		(*pile) = tmp;
	}
	if (print)
		ft_printf("%s\n", print);
	return (0);
}

int		rotate(t_elem **pile, char *print, int com)
{
	t_elem *tmp;

	(void)com;
	if (*pile && (*pile)->next)
	{
		tmp = (*pile);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (*pile);
		(*pile) = (*pile)->next;
		tmp->next->next = NULL;
	}
	if (print)
		ft_printf("%s\n", print);
	return (0);
}

int		rev_rotate(t_elem **pile, char *print, int com)
{
	t_elem *tmp;
	t_elem *tmp2;

	(void)com;
	if (*pile && (*pile)->next)
	{
		tmp = (*pile);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = (*pile);
		(*pile) = tmp2;
	}
	if (print)
		ft_printf("%s\n", print);
	return (0);
}
