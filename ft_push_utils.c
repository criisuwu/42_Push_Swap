/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:55:57 by chomobon          #+#    #+#             */
/*   Updated: 2025/03/26 16:27:48 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_err(void)
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

void freestack(t_stack **s)
{
    t_stack *tmp;
    
    if (s)
    {
        while(*s)
        {
            tmp = (*s)->next;
            free(*s);
            (*s) = tmp;
        }
    }
}

void free_both_stacks(t_stack **a, t_stack **b)
{
    freestack(a);
    freestack(b);
}

void freestr(char **lst)
{
    char *n_lst;

    if(!lst)
        return;
    while (*lst)
    {
        n_lst = *lst;
        lst++;
        free(n_lst);
    }
    *lst = NULL;
}