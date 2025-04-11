/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mt_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:58:02 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 18:12:23 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_and_decrease(t_stack **a, t_stack **b, int *c_size)
{
	push(a, b, 'b');
	(*c_size)--;
}

static void	push_all_exc_three(t_stack **a, t_stack**b, int sz)
{
	int	half;
	int	c_size;

	half = (sz / 2) + 1;
	c_size = sz;
	while (c_size > half && c_size >= 3)
	{
		if ((*a)->index < half)
			push_and_decrease(a, b, &c_size);
		else
			rotate(a, 'a');
	}
	while (c_size > 3)
	{
		if ((*a)->index == sz || (*a)->index == sz - 1 || (*a)->index == sz - 2)
			rotate(a, 'a');
		else
			push_and_decrease(a, b, &c_size);
	}
	sort_three(a);
}

void	calculate_pos(t_stack *s)
{
	t_stack	*aux;
	int		pos;

	pos = 0;
	aux = s;
	while (aux)
	{
		aux->pos = pos;
		pos++;
		aux = aux->next;
	}
}

void	assign_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*b_aux;

	b_aux = *b;
	while (b_aux)
	{
		asg_tg_pos_lower_ind(a, &b_aux);
		b_aux = b_aux->next;
	}
}

void	sort_mt_three(t_stack **a, t_stack **b, int sz)
{
	int	sz_a;
	int	sz_b;

	push_all_exc_three(a, b, sz);
	sz_a = 3;
	sz_b = sz - 3;
	while (*b)
	{
		calculate_pos(*a);
		calculate_pos(*b);
		assign_target_pos(a, b);
		asg_cost(b, sz_a, sz_b);
		ex_opt_mvs(a, b, &sz_a, &sz_b);
	}
	rotate_until_sorted(a, sz_a);
}
