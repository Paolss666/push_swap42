/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:30:45 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/20 16:48:56 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
calcola il numero di operazioni ra richieste per posizionare
data nella posizione corretta di a,
cerchiamo il valore max e min nella pila,
-controlliamo se max < data e min > data
se questo e' vero vuol dire che data e' nella poszione corretta
-controlliamo se data > del valore top e < bottom se e' true
data deve essere posizionato all 'interno della pila 
quindi riinviamo 0 perche non sono necessarie ra.
-while(1) per cercare la poszione corretta di data.
se now.data < data e now.prev.data > data e' vero allora
vuol dire che deve essere inserito tra questi due valori.
-controllo per determinare se a_index > size /2 significa
che il numero di operazioni ra e' inferiore a size/2 quindi 
viene restituito un numero *-1 
-Se il controllo non viene sodd, viene restituito il valore posit
di a_index per indicare il numero di oper ra necessarie per
posizionare data.
*/

int	count_ra(t_stack *a, int data)
{
	int		min;
	int		max;
	int		a_index;
	t_node	*now;

	a_index = 1;
	now = a->top;
	max = max0min(a, 0);
	min = max0min(a, 1);
	if (max < data || min > data)
		return (maxormin(a, min));
	if (a->top->data > data && a->bottom->data < data)
		return (0);
	while (1)
	{
		if (now->data < data && now->prev->data > data)
		{
			if (a_index > (a->size) / 2)
				return ((a->size - a_index) * -1);
			return (a_index);
		}
		now = now->prev;
		a_index++;
	}
}

void	count(t_stack *a, t_stack *b, int *ra_c, int *rb_c)
{
	int		b_index;
	int		new_ra_c;
	int		new_rb_c;
	t_node	*now;

	now = b->top;
	b_index = 0;
	while (b_index < b->size)
	{
		new_ra_c = count_ra(a, now->data);
		if (b_index > (b->size) / 2)
			new_rb_c = (b->size - b_index) * -1;
		else
			new_rb_c = b_index;
		if (b_index == 0 || best(*ra_c, *rb_c, new_ra_c, new_rb_c))
		{
			*ra_c = new_ra_c;
			*rb_c = new_rb_c;
		}
		now = now->prev;
		b_index++;
	}
}

void	btoa(t_stack *a, t_stack *b)
{
	int	ra_c;
	int	rb_c;

	ra_c = 0;
	rb_c = 0;
	count(a, b, &ra_c, &rb_c);
	rrrab(a, b, &ra_c, &rb_c);
	rrra(a, &ra_c);
	rrrb(b, &rb_c);
	pa(a, b);
}

void	finish(t_stack *a)
{
	int		min;
	int		a_index;
	t_node	*now;

	a_index = 0;
	now = a->top;
	min = max0min(a, 1);
	while (now->data != min)
	{
		now = now->prev;
		a_index++;
	}
	if (a_index > a->size / 2)
	{
		a_index = a->size - a_index;
		while (a_index--)
			rra(a);
	}
	else
	{
		while (a_index--)
			ra(a);
	}
}
