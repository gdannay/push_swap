/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:20:45 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/12 17:29:37 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

void		push_swap(t_elem **a_pile, t_elem **b_pile, int size);
int			algob(t_elem **a_pile, t_elem **b_pile, int size, int rest, int ret);
int			algoa(t_elem **a_pile, t_elem **b_pile, int size, int rest, int ret);

#endif
