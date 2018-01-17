/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:20:28 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:13:46 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static t_com	*delete_coms(t_com **first, t_com **del, t_com **secdel)
{
	t_com	*tmp;
	t_com	*tmp2;

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

static t_com	*merge_com(t_com **merge, t_com **secmer, t_com **secnext)
{
	if (((*merge)->com == SA && (*secmer)->com == SB)
		|| ((*merge)->com == SB && (*secmer)->com == SA))
		(*merge)->com = SS;
	else if (((*merge)->com == RRA && ((*secmer)->com == RRB))
		|| ((*merge)->com == RRB && (*secmer)->com == RRA))
		(*merge)->com = RRR;
	else if (((*merge)->com == RA && (*secmer)->com == RB)
		|| ((*merge)->com == RB && (*secmer)->com == RA))
		(*merge)->com = RR;
	else if (((*merge)->com == RRR && (*secmer)->com == RB)
		|| ((*merge)->com == RB && (*secmer)->com == RRR))
		(*merge)->com = RRA;
	else if (((*merge)->com == RRR && (*secmer)->com == RA)
		|| ((*merge)->com == RA && (*secmer)->com == RRR))
		(*merge)->com = RRB;
	else if (((*merge)->com == RRB && (*secmer)->com == RR)
		|| ((*merge)->com == RR && (*secmer)->com == RRB))
		(*merge)->com = RA;
	else if (((*merge)->com == RRA && (*secmer)->com == RR)
		|| ((*merge)->com == RR && (*secmer)->com == RRA))
		(*merge)->com = RB;
	else
		return (*secmer);
	del_com(merge, secmer, secnext);
	return (*merge);
}

static void		print_next(t_com *tmp)
{
	if (tmp->com == RRA)
		ft_printf("rra\n");
	else if (tmp->com == RRB)
		ft_printf("rrb\n");
	else if (tmp->com == RRR)
		ft_printf("rrr\n");
	else if (tmp->com == RA)
		ft_printf("ra\n");
	else if (tmp->com == RB)
		ft_printf("rb\n");
	else if (tmp->com == RR)
		ft_printf("rr\n");
}

static void		print_com(t_com **first)
{
	t_com	*tmp;

	tmp = *first;
	while (tmp)
	{
		(*first) = (*first)->next;
		if (tmp->com == PA)
			ft_printf("pa\n");
		else if (tmp->com == PB)
			ft_printf("pb\n");
		else if (tmp->com == SA)
			ft_printf("sa\n");
		else if (tmp->com == SB)
			ft_printf("sb\n");
		else if (tmp->com == SS)
			ft_printf("ss\n");
		else
			print_next(tmp);
		free(tmp);
		tmp = (*first);
	}
}

void			manage_commands(t_com **first)
{
	t_com	*tmp;
	int		i;

	tmp = *first;
	i = 0;
	while (tmp)
	{
		if (tmp && tmp->next &&
			((tmp->com == PA && tmp->next->com == PB) ||
			(tmp->com == PB && tmp->next->com == PA) ||
			(tmp->com == RRA && tmp->next->com == RA) ||
			(tmp->com == RA && tmp->next->com == RRA) ||
			(tmp->com == RB && tmp->next->com == RRB) ||
			(tmp->com == RRB && tmp->next->com == RB)))
			tmp = delete_coms(first, &tmp, &(tmp->next));
		else if (tmp && tmp->next && ((tmp->com == SA) ||
			(tmp->com == SB) || (tmp->com == RRA) ||
			(tmp->com == RRB) || (tmp->com == RRR) ||
			(tmp->com == RB) || (tmp->com == RR) || (tmp->com == RA)))
			tmp = merge_com(&tmp, &(tmp->next), &(tmp->next->next));
		else
			tmp = tmp->next;
		i++;
	}
	print_com(first);
}
