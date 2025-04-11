/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_movements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:03:14 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 17:58:41 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * Con esta funcion ejecutamos los movimientos que son de las dos pilas
static void	ex_double_mvs(t_stack **a, t_stack **b, int *mvsa, int *mvsb)
{
	if ((*mvsa) > 0 && (*mvsb > 0))
	{
		rr(a, b);
		(*mvsa)--;
		(*mvsb)--;
	}
	else if ((*mvsa < 0) && (*mvsb < 0))
	{
		rrr(a, b);
		(*mvsa)++;
		(*mvsb)++;
	}
}

// * Con esta funcion lo que hago es ejecutar los movimientos de rotamiento
static void	ex_mvs(t_stack **a, t_stack **b, int mvsa, int mvsb)
{
	while (mvsa != 0 || mvsb != 0)
	{
		if ((mvsa > 0 && mvsb > 0) || (mvsa < 0 && mvsb < 0))
			ex_double_mvs(a, b, &mvsa, &mvsb);
		else if (mvsa < 0)
		{
			r_rotate(a, 'a');
			mvsa++;
		}
		else if (mvsb < 0)
		{
			r_rotate(b, 'b');
			mvsb++;
		}
		else if (mvsa > 0)
		{
			rotate(a, 'a');
			mvsa--;
		}
		else if (mvsb > 0)
		{
			rotate(b, 'b');
			mvsb--;
		}
	}
}

void	ex_opt_mvs(t_stack **a, t_stack **b, int *sz_a, int *sz_b)
{
	t_stack	*best_node;
	t_stack	*b_aux;

	b_aux = *b;
	while (b_aux)
	{
		if (abs_val(best_node->cost_a) + abs_val(best_node->cost_b)
			> (abs_val(b_aux->cost_a) + abs_val(b_aux->cost_b)))
		{
			best_node = b_aux;
		}
		b_aux = b_aux->next;
	}
	ex_mvs(a, b, best_node->cost_a, best_node->cost_b);
	push(b, a, 'a');
	(*sz_a)++;
	(*sz_b)--;
}

static int	calc_num_rot(t_stack **a, int sz_a)
{
	t_stack	*a_aux;

	a_aux = *a;
	calculate_pos(*a);
	while (a_aux)
	{
		if (a_aux->index == 1)
		{
			if ((a_aux->pos + 1) <= sz_a / 2 +1)
				return (a_aux->pos);
			else
				return (a_aux->pos - sz_a);
		}
		a_aux = a_aux->next;
	}
	return (0);
}

void	rotate_until_sorted(t_stack **a, int sz_a)
{
	int	num_rotate;

	num_rotate = calc_num_rot(a, sz_a);
	while (num_rotate != 0)
	{
		if (num_rotate < 0)
		{
			r_rotate(a, 'a');
			num_rotate++;
		}
		else
		{
			rotate(a, 'a');
			num_rotate--;
		}
	}
}
