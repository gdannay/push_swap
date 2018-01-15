/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:16:06 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/15 10:59:10 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			exec_command(t_elem **a_pile, t_elem **b_pile, char *com)
{
	if (!(ft_strcmp(com, "sa")))
		return (swap(a_pile, NULL, 0, NULL));
	else if (!(ft_strcmp(com, "sb")))
		return (swap(b_pile, NULL, 0, NULL));
	else if (!(ft_strcmp(com, "ss")))
	{
		swap(a_pile, NULL, 0, NULL);
		return (swap(b_pile, NULL, 0, NULL));
	}
	else if (!(ft_strcmp(com, "pa")))
		return (push(b_pile, a_pile, NULL, 0, NULL));
	else if (!(ft_strcmp(com, "pb")))
		return (push(a_pile, b_pile, NULL, 0, NULL));
	else if (!(ft_strcmp(com, "ra")))
		return (rotate(a_pile, NULL, 0, NULL));
	else if (!(ft_strcmp(com, "rb")))
		return (rotate(b_pile, NULL, 0, NULL));
	else if (!(ft_strcmp(com, "rr")))
	{
		rotate(a_pile, NULL, 0, NULL);
		return (rotate(b_pile, NULL, 0, NULL));
	}
	else if (!(ft_strcmp(com, "rra")))
		return (rev_rotate(a_pile, NULL, 0, NULL));
	else if (!(ft_strcmp(com, "rrb")))
		return (rev_rotate(b_pile, NULL, 0, NULL));
	else if (!(ft_strcmp(com, "rrr")))
	{
		rev_rotate(a_pile, NULL, 0, NULL);
		return (rev_rotate(b_pile, NULL, 0, NULL));
	}
	else
		return (1);
}
static int	error(t_elem **a_pile, t_elem **b_pile, char **com)
{
	ft_strdel(com);
	write(2, "Error\n", 6);
	del_lst(a_pile);
	del_lst(b_pile);
	return (1);
}

void	print_pile(t_elem *a_pile, t_elem *b_pile)
{
	t_elem *tmp;

	tmp = a_pile;
	ft_printf("\nA:");
	while (tmp)
	{
		ft_printf(" %d", tmp->nb);
		tmp = tmp->next;
	}
	tmp = b_pile;
	ft_printf("\nB:");
	while (tmp)
	{
		ft_printf(" %d", tmp->nb);
		tmp = tmp->next;
	}
	ft_printf("\n\n");
}

int		get_command(t_elem **a_pile, t_elem **b_pile, int flag)
{
	char	*com;

	com = NULL;
	while (get_next_line(0, &com))
	{
		if (exec_command(a_pile, b_pile, com))
			return (error(a_pile, b_pile, &com));
		if (flag & F_V)
			print_pile(*a_pile, *b_pile);
		ft_strdel(&com);
	}
	return (0);
}
