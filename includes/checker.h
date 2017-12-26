#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"

typedef struct		s_elem
{
	int				nb;
	struct s_elem	*next;
}					t_elem;

t_elem				*check_args(int ac, char **av);
void				del_lst(t_elem **a_pile);

#endif
