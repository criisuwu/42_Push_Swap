/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:37:56 by chomobon          #+#    #+#             */
/*   Updated: 2025/03/05 19:00:56 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Con esta funcion situo el final de la lista y lo devulevo
t_stack *lstlast(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}
//Con esto creo una nueva pila y le añado el contenido recibido
t_stack *new_stack(int content)
{
    t_stack *new;

    new = (t_stack *) malloc(sizeof(t_stack));
    if (!new)
        ft_print_err();
    new->value = content;
    new->next = NULL;
    return (new);
}
//Con esta funcion añado un elemento nuevo al final de la stack
void add_back(t_stack **lst, t_stack *new)
{
    t_stack *aux;

    if(!lst)
        return ;
    if (*lst)
    {
        aux = *lst;
        while(aux->next)
            aux = aux->next;
        aux->next = new;
    }
    else
        *lst = new;
}
