/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:15:58 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/15 15:23:45 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

/*
**1 : PA
**2 : PB
**3 : SA
**4 : SB
**5 : SS
**6 : RRA
**7 : RRB
**8 : RRR
**9 : RA
**10 : RB
**11 : RR
*/

void	add_com(t_com **first, int intcom)
{
	t_com *new;

	if ((new = (t_com *)malloc(sizeof(t_com))) == NULL)
		return ;
	new->com = intcom;
	new->next = NULL;
	if (*first && (*first)->prev)
	{
		(*first)->prev->next = new;
		new->prev = (*first)->prev;
		(*first)->prev = new;
	}
	else if (*first)
	{
		(*first)->next = new;
		new->prev = (*first);
		(*first)->prev = new;
	}
	else
	{
		(*first) = new;
		new->prev = NULL;
	}
}

int		push(t_elem **lose, t_elem **get, char *print, int intcom, t_pile *list)
{
	t_elem *tmp;

	if (*lose)
	{
		tmp = *lose;
		*lose = (*lose)->next;
		tmp->next = *get;
		(*get) = tmp;
	}
	if (0 && print)
		ft_printf("%s\n", print);
	if (list)
		add_com(&(list->com), intcom);
	return (0);
}

int		swap(t_elem **pile, char *print, int intcom, t_pile *list)
{
	t_elem *tmp;

	if (*pile && (*pile)->next)
	{
		tmp = (*pile)->next;
		(*pile)->next = tmp->next;
		tmp->next = (*pile);
		(*pile) = tmp;
	}
	if (0 && print)
		ft_printf("%s\n", print);
	if (list)
		add_com(&(list->com), intcom);
	return (0);
}

int		rotate(t_elem **pile, char *print, int intcom, t_pile *list)
{
	t_elem *tmp;

	if (*pile && (*pile)->next)
	{
		tmp = (*pile);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (*pile);
		(*pile) = (*pile)->next;
		tmp->next->next = NULL;
	}
	if (0 &&print)
		ft_printf("%s\n", print);
	if (list)
		add_com(&(list->com), intcom);
	return (0);
}

int		rev_rotate(t_elem **pile, char *print, int intcom, t_pile *list)
{
	t_elem *tmp;
	t_elem *tmp2;

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
	if (0 && print)
		ft_printf("%s\n", print);
	if (list)
		add_com(&(list->com), intcom);
	return (0);
}
