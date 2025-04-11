/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heuristics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:29:07 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 18:02:12 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_cost_b(t_stack **b, int sz_b)
{
	t_stack	*b_aux;

	b_aux = *b;
	while (b_aux)
	{
		if ((b_aux->pos + 1) <= (sz_b / 2) + 1)
			b_aux->cost_b = b_aux->pos;
		else
			b_aux->cost_b = b_aux->pos - sz_b;
		b_aux = b_aux->next;
	}
}

static void	calc_cost_a(t_stack **b, int sz_a)
{
	t_stack	*b_aux;

	b_aux = *b;
	while (b_aux)
	{
		if ((b_aux->target_pos +1) <= (sz_a / 2) + 1)
			b_aux->cost_a = b_aux->target_pos;
		else
			b_aux->cost_a = b_aux->target_pos - sz_a;
		b_aux = b_aux->next;
	}
}

void	asg_cost(t_stack **b, int sz_a, int sz_b)
{
	calc_cost_b(b, sz_b);
	calc_cost_a(b, sz_a);
}

int	abs_val(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
