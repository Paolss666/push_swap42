/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:57:28 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/22 15:21:23 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(t_stack *a, t_stack *b)
{
	sortcheck(a, b);
	if (a->size >= 100)
		division(a, b);
	else if (a->size < 100 && a->size > 10)
		division3(a, b);
	while (a->size > 3)
		pb(a, b);
	logic_plus(a);
	while (b->size)
		btoa(a, b);
	finish(a);
	return ;
}

void	trance_string(int ac, char **av, t_stack *a, t_stack *b)
{
	int	len;
	int	i;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (len == 0)
		{
			free(a);
			error();
		}
		else
			trance(a, av[i], b);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	insert_check(ac, av, a, b);
	trance_string(ac, av, a, b);
	samesame(a, b);
	atob(a, b);
	clear(a);
	clear(b);
}
