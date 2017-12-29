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
