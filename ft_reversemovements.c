/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversemovements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:05:34 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 18:10:11 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * lo que hace esta orden es desplazar todos los numeros de la stack hacia
// * abajo, y el ultimo numero pasa a ser el primero. Lo hace de una sola 
// * stack osea que lo hace o en la a o en la b
void	r_rotate(t_stack **stack, char option)
{
	t_stack	*last;
	t_stack	*aux;
	t_stack	*prev;

	prev = (*stack);
	last = (*stack)->next;
	if (last != NULL)
	{
		while (last->next)
			last = last->next;
		while (prev->next->next)
			prev = prev->next;
		aux = (*stack);
		(*stack) = last;
		last->next = aux;
		prev->next = NULL;
		if (option == 'a')
			write(1, "rra\n", 4);
		if (option == 'b')
			write(1, "rrb\n", 4);
	}
}

// * Lo que hace esta orden es desplazar hacia abajo todos los numeros
// * de las dos stacks tanto de a como b, Y situa el ultimo numero en
// * la primera posicion.
void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a, 'x');
	r_rotate(b, 'x');
	write(1, "rrr\n", 4);
}
