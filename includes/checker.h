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
int					exec_command(t_elem **a_pile, t_elem **b_pile, char *com, int flag);
int					push(t_elem **lose, t_elem **get, int flag);
int					swap(t_elem **pile, t_elem **second, int flag);
int					rotate(t_elem **pile, t_elem **second, int flag);
int					rev_rotate(t_elem **pile, t_elem **second, int flag);

#endif
