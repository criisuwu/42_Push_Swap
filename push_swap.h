/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:34:12 by chomobon          #+#    #+#             */
/*   Updated: 2025/01/29 17:00:21 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

typedef struct s_stack
{
    int value;
    int index;
    int pos;
    int target_pos;
    struct s_stack *next;
} t_stack;

#endif