/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_movements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:03:14 by chomobon          #+#    #+#             */
/*   Updated: 2025/03/26 17:22:08 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * Con esta funcion ejecutamos los movimientos que son de las dos pilas
static void ex_double_mvs(t_stack **a, t_stack **b, int *mvsa, int *mvsb)
{
    if((*mvsa) > 0 && (*mvsb > 0))
    {
        rr(a, b);
        (*mvsa)--;
        (*mvsb)--;
    }
    else if ((*mvsa < 0) && (*mvsb < 0))
    {
        rrr(a, b);
        (*mvsa)++;
        (*mvsb)++;
    }
}

// * Con esta funcion lo que hago es ejecutar los movimientos de rotamiento
static void ex_mvs(t_stack **a, t_stack **b, int mvsa, int mvsb)
{
    while (mvsa != 0 || mvsb != 0)
    {
        if ((mvsa > 0 && mvsb > 0) || (mvsa < 0 && mvsb < 0))
            ex_double_mvs(a, b, &mvsa, &mvsb);
        else if (mvsa < 0)
        {
            r_rotate(a, 'a');
            mvsa++;
        }
        else if (mvsb < 0)
        {
            r_rotate(b, 'b');
            mvsb++;
        }
        else if (mvsa > 0)
        {
            rotate(a, 'a');
            mvsa--;
        }
        else if (mvsb > 0)
        {
            rotate(b, 'b');
            mvsb--;
        }
    }
}