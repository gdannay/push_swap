/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:08:00 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/06 11:08:16 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			length_nbr(int n)
{
	int		taille;

	taille = 0;
	if (n <= 0)
		taille++;
	while (n)
	{
		n /= 10;
		taille++;
	}
	return (taille);
}
