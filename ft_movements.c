/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:04:59 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 18:04:57 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * esta orden lo que hace es cambiar el primer elemento con el segundo de la
// * stack a (si hay uno o menos no hace nada)
void	sa(t_stack **stack)
{
	t_stack	*second;

	second = (*stack)->next;
	if (second != NULL)
	{
		(*stack)->next = second->next;
		second->next = (*stack);
		(*stack) = second;
		write(1, "sa\n", 3);
	}
}

// * Con esta orden vamos a pasar las cosas de una pila a otra, en caso de que
// * pasemos el primer elemento de la pila b a la a imprime pa, en caso
// * contrario (de a a b) imprime pb. Si la pila de origen esta vacia no hace
// * nada.
void	push(t_stack **src, t_stack **dest, char stackdest)
{
	t_stack	*aux;

	aux = (*src);
	(*src) = aux->next;
	aux->next = (*dest);
	(*dest) = aux;
	if (stackdest == 'a')
		write(1, "pa\n", 3);
	if (stackdest == 'b')
		write(1, "pb\n", 3);
}

// * Con esta orden lo que vamos a hacer es desplazar los elementos hacia
// * arriba, rota todos los elementos hacia arriba y el primer elemento pasa a
// * ser el ultimo elemento tanto en ra como en rb. Solo lo hace en uno de los
// * stacks, osea en a o en b.
void	rotate(t_stack **stack, char option)
{
	t_stack	*last;
	t_stack	*aux;

	last = (*stack)->next;
	if (last != NULL)
	{
		while (last->next)
			last = last->next;
		aux = (*stack);
		last->next = aux;
		aux ->next = NULL;
		if (option == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

// * Con esta orden lo que hacemos es rotar a y b a mismo tiempo
void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	write(1, "rr\n", 3);
}
