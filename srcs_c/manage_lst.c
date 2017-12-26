#include "checker.h"

void	del_lst(t_elem **a_pile)
{
	t_elem	*tmp;

	while (*a_pile)
	{
		tmp = (*a_pile)->next;
		free(*a_pile);
		(*a_pile) = tmp;
	}
	*a_pile = NULL;
}
