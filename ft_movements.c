/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:04:59 by chomobon          #+#    #+#             */
/*   Updated: 2025/01/31 14:46:02 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * esta orden lo que hace es cambiar el primer elemento con el segundo de la
// * stack a (si hay uno o menos no hace nada)
void    sa(t_stack **stack)
{
    t_stack *second;
    
    second = (*stack)->next;
    if (second != NULL)
    {
        (*stack)->next = second->next;
        second->next = (*stack);
        (*stack) = second;
        ft_printf("sa\n");
    }
}

// * Con esta orden vamos a pasar las cosas de una pila a otra, en caso de que
// * pasemos el primer elemento de la pila b a la a imprime pa, en caso
// * contrario (de a a b) imprime pb. Si la pila de origen esta vacia no hace
// * nada.
void push(t_stack **src, t_stack **dest, char stackdest)
{
    t_stack *aux;

    aux = (*src);
    (*src) = aux->next;
    aux->next = (*dest);
    (*dest) = aux;
    if (stackdest == 'a')
        ft_printf("pa\n");
    else
        ft_printf("pb\n");
}

// * Con esta orden lo que vamos a hacer es desplazar los elementos hacia
// * arriba o hacia abajo, en caso de que se rotara hacia arriba lo que hace
// * es ra y rota todos los elementos hacia arriba y el primer elemento pasa a
// * ser el ultimo elemento. En caso de que fuera al reves podemos ver que 
// * se rotan todos hacia abajo y el ultimo pasa a ser el primero (rb).
void rotate(t_stack **stack, char option)
{
    t_stack *last;
    t_stack *aux;

    last = (*stack)->next;
    if (last != NULL)
    {
        while (last->next)
            last = last->next;
        aux = (*stack);
        last->next = aux;
        aux ->next = NULL;
        if (option = 'a')
            ft_printf("ra\n");
        else
            ft_printf("rb\n");
    }
}