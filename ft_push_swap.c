/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:28:49 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/14 17:32:47 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	print_stack(t_stack *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
} */

// * Este archivo solo incluye el main para el push swap
int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	size = 0;
	if (argc < 2)
		ft_print_err();
	a = ft_process(argc, argv, &size);
	if (!a || check_dup(a))
	{
		freestack(&a);
		ft_print_err();
	}
	if (!check_sorted(a))
	{
		sort_stack(&a, &b, size);
		// print_stack(a, "A");
	}
	free_both_stacks(&a, &b);
	exit(EXIT_SUCCESS);
}
