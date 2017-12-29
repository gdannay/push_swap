#include "checker.h"



int		push(t_elem **lose, t_elem **get, int flag)
{
	t_elem *tmp;

	if (*lose)
	{
		tmp = *get;
		*get = *lose;
		(*get)->next = tmp;
		*lose = (*lose)->next;
	}
	return (0);
}

int		swap(t_elem **pile, t_elem **second, int flag)
{
	t_elem *tmp;

	if (*pile && (*pile)->next)
	{
		tmp = (*pile)->next;
		(*pile)->next = tmp->next;
		tmp->next = (*pile);
		(*pile) = tmp;
	}
	return (0);
}

int		rotate(t_elem **pile, t_elem **second, int flag)
{
	t_elem *tmp;

	if (*pile && (*pile)->next)
	{
		tmp = (*pile);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (*pile);
		(*pile) = (*pile)->next;
		tmp->next->next = NULL;
	}
	return (0);
}

int		rev_rotate(t_elem **pile, t_elem **second, int flag)
{
	t_elem *tmp;
	t_elem *tmp2;

	if (*pile && (*pile)->next)
	{
		tmp = (*pile);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = (*pile);
		(*pile) = tmp2;
	}
	return (0);
}
