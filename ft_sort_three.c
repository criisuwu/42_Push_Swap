/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:50:39 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/15 15:04:28 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	second = (*a)->next;
	third = (*a)->next->next;
	if (first->index > second->index && first->index > third->index)
	{
		rotate(a, 'a');

	}
	else if (first->index < second->index && second->index > third->index)
		r_rotate(a, 'a');
	first = *a;
	second = (*a)->next;
	if (first->index > second->index)
		sa(a);
}
