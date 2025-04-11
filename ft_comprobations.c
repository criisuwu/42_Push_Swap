/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comprobations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:26:22 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 18:43:09 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * Con esta funcion verifico si la lista ya esta ordenda. Como te piden que
// * este ordenada de menor a mayor, mientras que el iterador sea mas
// * pequeñito que el valor que hay en la posicion del iterador de la lista
// * la seguira recorriendo, lo que indica que si que esta ordenada.
int	check_sorted(t_stack *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (i > stack->value)
			return (0);
		i = stack->value;
		stack = stack->next;
	}
	return (1);
}

// * Verifico si el valor que hay dentro de la posicion de ese nodo en la
// * lista no lo he almacenado previamente, evitando asi el duplicado del
// * valor en la pila
int	check_dup(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
