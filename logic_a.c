/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:12:36 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/22 14:45:52 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	logic(t_stack *a)
{
	t_node	*now;

	now = a->top;
	if (now->data > now->prev->data && now->prev->data > a->bottom->data)
	{
		sa(a);
		rra(a);
	}
	else if (now->data > a->bottom->data && a->bottom->data > now->prev->data)
		ra(a);
	else if (a->bottom->data > now->data && now->data > now->prev->data)
		sa(a);
	else if (now->prev->data > now->data && now->data > a->bottom->data)
		rra(a);
	else if (now->prev->data > a->bottom->data && a->bottom->data > now->data)
	{
		rra(a);
		sa(a);
	}
	else
		return ;
}

/*
sortcheck serve a vedere se la pila a e' in ordine crescente. 
*/

void	sortcheck(t_stack *a, t_stack *b)
{
	t_node	*now;

	now = a->top;
	while (now->prev)
	{
		if (now->data < now->prev->data)
			now = now->prev;
		else
			return ;
	}
	clear(a);
	clear(b);
	exit(0);
}

void	logic_plus(t_stack *a)
{
	if (a->size <= 1)
		return ;
	else if (a->size == 2)
	{
		if (a->top->data > a->bottom->data)
			sa(a);
	}
	else
		logic(a);
}
