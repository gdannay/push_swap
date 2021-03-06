/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:33:10 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/18 10:14:46 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <limits.h>
# define F_V 1
# define F_C 2

typedef struct		s_elem
{
	int				nb;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_pile
{
	t_elem			**a_pile;
	t_elem			**b_pile;
	struct s_com	*com;
}					t_pile;

t_elem				*check_args(int ac, char **av, int *flag, int i);
void				del_lst(t_elem **a_pile);
int					exec_command(t_elem **a_pile, t_elem **b_pile, char *com);
int					push(t_elem **lose, t_elem **get, int com, t_pile *list);
int					swap(t_elem **pile, int com, t_pile *list);
int					rotate(t_elem **pile, int com, t_pile *list);
int					rev_rotate(t_elem **pile, int com, t_pile *list);
t_elem				*new_elem(char *av, t_elem **a_pile, t_elem *tmp);
int					get_command(t_elem **a_pile, t_elem **b_pile, int flag);
int					check_order(t_elem *a_pile, t_elem *b_pile);
void				print_pile(t_elem *a_pile, t_elem *b_pile);

#endif
