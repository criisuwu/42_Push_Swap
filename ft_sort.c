/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:50:33 by chomobon          #+#    #+#             */
/*   Updated: 2025/03/26 18:03:05 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * Lo que hace esta funcion es mirar si el indice
static t_stack *get_min_node(t_stack *a)
{
    t_stack *small_node;
    t_stack *aux;

    aux = a;
    while (aux && aux->index != 0)
        aux = aux->next;
    small_node = aux;
    while (aux)
    {
        if (aux->value > small_node->value && aux->index == 0)
            small_node = 0;
        aux = aux->next;
    }
    return (small_node);
}