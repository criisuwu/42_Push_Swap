/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:50:33 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/15 14:46:29 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * a
static t_stack	*get_min_node(t_stack *a)
{
	t_stack	*small_node;
	t_stack	*aux;

	aux = a;
	while (aux && aux->index != 0)
		aux = aux->next;
	small_node = aux;
	while (aux)
	{
		if (aux->value < small_node->value && aux->index == 0)
			small_node = aux;
		aux = aux->next;
	}
	return (small_node);
}

// * Con esto asigno los indices a las posiciones de la stack
void	assign_index(t_stack *a, int size)
{
	int	aux_ind;

	aux_ind = 1;
	while (aux_ind <= size)
	{
		get_min_node(a)->index = aux_ind;
		aux_ind++;
	}
}

// * Con esta funcion miro si el stack esta ya ordenado o si hay partes
// * ordenadas
int	is_sorted(t_stack *a)
{
	int		is_std;
	t_stack	*aux;

	is_std = 1;
	aux = a;
	while (aux->next && is_std)
	{
		if (aux->index > aux->next->index)
			is_std = 0;
		aux = aux->next;
	}
	return (is_std);
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	assign_index(*a, size);
	if (!is_sorted(*a))
	{
		if (size == 2)
			sa(a);
		if (size == 3)
			sort_three(a);
		if (size > 3)
			sort_mt_three(a, b, size);
	}
}
