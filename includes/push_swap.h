/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:20:45 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/13 17:20:05 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

typedef struct		s_pile
{
	t_elem			**a_pile;
	t_elem			**b_pile;
}					t_pile;

typedef struct		s_com;
{
	int				com;
	struct s_com	*prev;
	struct s_com	*next;
}					t_com;

int					push_swap(t_elem **a_pile, t_elem **b_pile, int size);
int					algoa(t_pile *list, int size, int rest, int ret);

#endif
