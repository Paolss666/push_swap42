/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:04:46 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/20 12:13:39 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra_c e rb_c sono il numero di rotazioni da effettuare 
Queste funzioni sono utilizzate nell'algoritmo di ordinamento per eseguire 
le operazioni di rotazione necessarie per ottenere la configurazione 
desiderata delle pile durante l'esecuzione delle istruzioni.
*/

void	rrrab(t_stack *a, t_stack *b, int *ra_c, int *rb_c)
{
	while (*ra_c > 0 && *rb_c > 0)
	{
		rr(a, b);
		*ra_c -= 1;
		*rb_c -= 1;
	}
	while (*ra_c < 0 && *rb_c < 0)
	{
		rrr(a, b);
		*ra_c += 1;
		*rb_c += 1;
	}
}

void	rrra(t_stack *a, int *ra_c)
{
	while (*ra_c)
	{
		if (*ra_c > 0)
		{
			ra(a);
			*ra_c -= 1;
		}
		else
		{
			rra(a);
			*ra_c += 1;
		}
	}
}

void	rrrb(t_stack *b, int *rb_c)
{
	while (*rb_c)
	{
		if (*rb_c > 0)
		{
			rb(b);
			*rb_c -= 1;
		}
		else
		{
			rrb(b);
			*rb_c += 1;
		}
	}
}
