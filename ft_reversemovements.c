/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversemovements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:05:34 by chomobon          #+#    #+#             */
/*   Updated: 2025/01/31 18:13:02 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * lo que hace esta orden es desplazar todos los numeros de la stack hacia
// * abajo, y el ultimo numero pasa a ser el primero. Lo hace de una sola 
// * stack osea que lo hace o en la a o en la b
void r_rotate(t_stack **stack, char option)
{
    t_stack *last;
    t_stack *aux;
    t_stack *prev;

    prev = (*stack);
    last = (*stack)->next;
    if(last != NULL)
    {
        while(last->next)
            last = last->next;
        while(prev->next->next)
            prev = prev->next;
        aux = (*stack);
        (*stack) = last;
        last->next = aux;
        prev->next = NULL;
        if (option == 'a')
            ft_printf("rra\n");
        if (option == 'b')
            ft_printf("rrb\n");
    }
}

// * Lo que hace esta orden es desplazar hacia abajo todos los numeros
// * de las dos stacks tanto de a como b, Y situa el ultimo numero en
// * la primera posicion.
void rrr(t_stack **a, t_stack **b)
{
    r_rotate(a, 'x');
    r_rotate(b, 'x');
    ft_printf("rrr\n ");
}