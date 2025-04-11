/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:29:39 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 19:18:08 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * Verifico si el separador es cualquiera de los carcteres similares al 
// * espacio como el salto de linea. el tabulador, el retorno de carro...
static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f'
		|| c == '\v' || c == '\r')
		return (1);
	return (0);
}

// * Es un atoi pero modificado para que devuleva los errores en caso de 
// * fallo
int	ft_n_atoi(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mod = -1;
		str++;
	}
	if (!*str)
		ft_print_err();
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_print_err();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_print_err();
	return (mod * i);
}

// * Es la funcion que procesa los argumentos recibidos al ejecutar 
// * el codigo, en caso de que falle libera las pilas y devuelve
// * un error y null
t_stack	*ft_process(int argc, char **argv, int *size)
{
	t_stack	*a;
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	a = NULL;
	while (argc > i)
	{
		if (argv[i][0] == '\0')
			return (freestack(&a), ft_print_err(), NULL);
		j = 0;
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (freestack(&a), ft_print_err(), NULL);
		while (tmp[j])
		{
			add_back(&a, new_stack(ft_atoi(tmp[j++])));
			*size += 1;
		}
		freestr(tmp);
		free(tmp);
		i++;
	}
	return (a);
}
