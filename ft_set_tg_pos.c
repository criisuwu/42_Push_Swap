/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tg_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:11:32 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 18:10:49 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	biggest_ind(t_stack **a)
{
	t_stack	*a_aux;
	int		biggest;

	a_aux = *a;
	biggest = a_aux->index;
	while (a_aux)
	{
		if (a_aux->index > biggest)
			biggest = a_aux->index;
		a_aux = a_aux->next;
	}
	return (biggest);
}

void	asg_tg_pos_lower_ind(t_stack **a, t_stack **b)
{
	t_stack	*a_aux;
	int		closer_ind;
	int		tg_pos;

	a_aux = *a;
	closer_ind = biggest_ind(&a_aux);
	while (a_aux)
	{
		if ((*b)->index < a_aux->index && closer_ind > a_aux->index)
		{
			closer_ind = a_aux->index;
			tg_pos = a_aux->pos;
		}
		a_aux = a_aux->next;
	}
	(*b)->target_pos = tg_pos;
}
