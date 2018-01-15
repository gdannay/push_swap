/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:20:28 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/15 15:47:47 by gdannay          ###   ########.fr       */
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

static t_com 	*delete_coms(t_com **first, t_com **del, t_com **secdel)
{
	t_com	*tmp;
	t_com	*tmp2;

//	dprintf(1, "DEL = %d %d\n", (*del)->com, (*secdel)->com);
	if (del == first)
	{
		(*first) = (*first)->next->next;
		tmp = (*first)->next->next;
		free(*del);
		free(*secdel);
		tmp->prev = NULL;
	}
	else
	{
		tmp = (*del)->prev;
		tmp2 = (*secdel)->next;
		tmp->next = tmp2;
		tmp2->prev = tmp;
		free(*del);
		free(*secdel);
	}
	return (tmp);
}

static t_com	*merge_com(t_com **merge, t_com **secmer)
{
	t_com *tmp;

//	dprintf(1, "MERGE = %d %d\n", (*merge)->com, (*secmer)->com);
	tmp = (*secmer)->next;
//	dprintf(1, "MERGE = %d %d %d\n", (*merge)->com, (*secmer)->com, tmp->com);
	if (((*merge)->com == 3 && (*secmer)->com == 4)
		|| ((*merge)->com == 4 && (*secmer)->com == 3))
		(*merge)->com = 5;
	else if (((*merge)->com == 6 && ((*secmer)->com == 7))
		|| ((*merge)->com == 7 && (*secmer)->com == 6))
		(*merge)->com = 8;
	else if (((*merge)->com == 9 && (*secmer)->com == 10)
		|| ((*merge)->com == 10 && (*secmer)->com == 9))
		(*merge)->com = 11;
	else if (((*merge)->com == 8 && (*secmer)->com == 10)
		|| ((*merge)->com == 10 && (*secmer)->com == 8))
		(*merge)->com = 6;
	else if (((*merge)->com == 8 && (*secmer)->com == 9)
		|| ((*merge)->com == 9 && (*secmer)->com == 8))
		(*merge)->com = 7;
	else if (((*merge)->com == 7 && (*secmer)->com == 11)
		|| ((*merge)->com == 11 && (*secmer)->com == 7))
		(*merge)->com = 9;
	else if (((*merge)->com == 6 && (*secmer)->com == 11)
		|| ((*merge)->com == 11 && (*secmer)->com == 6))
		(*merge)->com = 10;
	free(*secmer);
	(*merge)->next = tmp;
//	dprintf(1, "MERGE = %d %d %d %d\n", (*merge)->com, (*secmer)->com, tmp->com, (*merge)->next->com);
	tmp->prev = (*merge);
//	dprintf(1, "MERGE = %d %d %d %d\n", (*merge)->com, (*secmer)->com, tmp->com, (*merge)->next->com);
	return (*merge);
}

static void	print_com(t_com **first)
{
	t_com	*tmp;

	tmp = *first;
	while (tmp)
	{
		(*first) = (*first)->next;
		if (tmp->com == 1)
			ft_printf("pa\n");
		else if (tmp->com == 2)
			ft_printf("pb\n");
		else if (tmp->com == 3)
			ft_printf("sa\n");
		else if (tmp->com == 4)
			ft_printf("sb\n");
		else if (tmp->com == 5)
			ft_printf("ss\n");
		else if (tmp->com == 6)
			ft_printf("rra\n");
		else if (tmp->com == 7)
			ft_printf("rrb\n");
		else if (tmp->com == 8)
			ft_printf("rrr\n");
		else if (tmp->com == 9)
			ft_printf("ra\n");
		else if (tmp->com == 10)
			ft_printf("rb\n");
		else if (tmp->com == 11)
			ft_printf("rr\n");
		free(tmp);
		tmp = (*first);
	}
}

void	manage_commands(t_com **first)
{
	t_com	*tmp;
	int		i;

	tmp = *first;
	i = 0;
	while (tmp)
	{
		if (tmp && tmp->next &&
			((tmp->com == 1 && tmp->next->com == 2) ||
			(tmp->com == 2 && tmp->next->com == 1) ||
			(tmp->com == 6 && tmp->next->com == 9) ||
			(tmp->com == 9 && tmp->next->com == 6) ||
			(tmp->com == 10 && tmp->next->com == 7) ||
			(tmp->com == 7 && tmp->next->com == 10)))
			tmp = delete_coms(first, &tmp, &(tmp->next));
		else if (tmp && tmp->next &&
				((tmp->com == 3 && tmp->next->com == 4) ||
				(tmp->com == 4 && tmp->next->com == 3) ||
				(tmp->com == 6 && tmp->next->com == 7) ||
				(tmp->com == 7 && tmp->next->com == 6) ||
				(tmp->com == 8 && tmp->next->com == 10) ||
				(tmp->com == 10 && tmp->next->com == 8) ||
				(tmp->com == 11 && tmp->next->com == 7) ||
				(tmp->com == 7 && tmp->next->com == 11) ||
				(tmp->com == 11 && tmp->next->com == 6) ||
				(tmp->com == 6 && tmp->next->com == 11) ||
				(tmp->com == 9 && tmp->next->com == 8) ||
				(tmp->com == 8 && tmp->next->com == 9) ||
				(tmp->com == 10 && tmp->next->com == 9) ||
				(tmp->com == 9 && tmp->next->com == 10)))
			tmp = merge_com(&tmp, &(tmp->next));
		else
			tmp = tmp->next;
		i++;
//		dprintf(1, "COUP = %d\n", i);
	}
	print_com(first);
}
