#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct		s_elem
{
	int				nb;
	struct s_elem	*next;
}					t_elem;

t_elem				*check_args(int ac, char **av);
void				del_lst(t_elem **a_pile);
int					exec_command(t_elem **a_pile, t_elem **b_pile, char *com);
int					push(t_elem **lose, t_elem **get);
int					swap(t_elem **pile);
int					rotate(t_elem **pile);
int					rev_rotate(t_elem **pile);

#endif
