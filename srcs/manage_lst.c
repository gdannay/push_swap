/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:16:25 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/15 17:28:27 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	del_lst(t_elem **pile)
{
	t_elem	*tmp;

	while (*pile)
	{
		tmp = (*pile)->next;
		free(*pile);
		(*pile) = tmp;
	}
	*pile = NULL;
}

int		check_order(t_elem *a_pile, t_elem *b_pile)
{
	t_elem	*tmp;

	tmp = a_pile;
	if (b_pile)
		return (1);
	while (tmp && tmp->next && tmp->nb < tmp->next->nb)
		tmp = tmp->next;
	if (tmp && tmp->next == NULL)
		return (0);
	return (1);
}

t_elem		*new_elem(char *av, t_elem **a_pile, t_elem *tmp)
{
	long	nb;
	t_elem	*new;
	int		i;

	i = 0;
	if (!(av) || !(av[0]))
		return (NULL);
	if ((av[0] == '-' || av[0] == '+') && av[1])
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0')
		return (NULL);
	nb = ft_atol(av);
	if (nb < INT_MIN || nb > INT_MAX)
		return (NULL);
	if ((new = (t_elem *)malloc(sizeof(t_elem))) == NULL)
		return (NULL);
	new->nb = (int)nb;
	new->next = NULL;
	if (*a_pile == NULL)
		*a_pile = new;
	else
		tmp->next = new;
	return (new);
}
