/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:33:10 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/09 12:33:18 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <limits.h>
# define C_NONE "\033[0m"
# define C_RED "\033[31m"
# define F_V 1
# define F_C 2

typedef struct		s_elem
{
	int				nb;
	struct s_elem	*next;
}					t_elem;

t_elem				*check_args(int ac, char **av, int *flag);
void				del_lst(t_elem **a_pile);
int					exec_command(t_elem **a_pile, t_elem **b_pile, char *com);
int					push(t_elem **lose, t_elem **get, char *print);
int					swap(t_elem **pile, char *print);
int					rotate(t_elem **pile, char *print);
int					rev_rotate(t_elem **pile, char *print);
t_elem				*new_elem(char *av, t_elem **a_pile, t_elem *tmp);
int					get_command(t_elem **a_pile, t_elem **b_pile, int flag);
int					check_order(t_elem *a_pile, t_elem *b_pile, int rev);
void				print_pile(t_elem *a_pile, t_elem *b_pile);

#endif
