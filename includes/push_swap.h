/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:20:45 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:12:21 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RRA 6
# define RRB 7
# define RRR 8
# define RA 9
# define RB 10
# define RR 11
# include "checker.h"

typedef struct		s_com
{
	int				com;
	struct s_com	*prev;
	struct s_com	*next;
}					t_com;

int					algobig(t_pile *list, int size, int rest, int ret);
void				algosmall(t_elem **a, t_elem **b, t_pile *list);
void				manage_commands(t_com **com);
int					c_size(t_elem *pile);
int					check_sort(t_elem *pile, int size, int rev);
void				fusionb(t_elem **a_pile, t_elem **b_pile,
					int size, t_pile *list);
void				fusiona(t_elem **a_pile, t_elem **b_pile,
					int size, t_pile *list);
void				del_com(t_com **first, t_com **del, t_com **newnext);

#endif
