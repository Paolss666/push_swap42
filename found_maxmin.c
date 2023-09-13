/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_maxmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:54:56 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/19 17:42:56 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max0min(t_stack *list, int num)
{
	int		max;
	int		min;
	int		p[2];
	t_node	*now;

	now = list->top;
	max = list->top->data;
	min = list->top->data;
	while (now)
	{
		if (now->data > max)
			max = now->data;
		if (now->data < min)
			min = now->data;
		now = now->prev;
	}
	p[0] = max;
	p[1] = min;
	return (p[num]);
}

int	maxormin(t_stack *a, int min)
{
	int		a_index;
	t_node	*now;

	now = a->top;
	a_index = 0;
	while (now->data != min)
	{
		now = now->prev;
		a_index++;
	}
	if (a_index > (a->size) / 2)
		return ((a->size - a_index) * -1);
	return (a_index);
}

int	best(int ra_c, int rb_c, int new_ra_c, int new_rb_c)
{
	int	old;
	int	new;

	old = cal(ra_c, rb_c);
	new = cal(new_ra_c, new_rb_c);
	if (new < old)
		return (1);
	else
		return (0);
}

int	cal(int ra, int rb)
{
	int	ra_sign;
	int	rb_sign;

	ra_sign = 1;
	rb_sign = 1;
	if (ra < 0)
		ra_sign = -1;
	if (rb < 0)
		rb_sign = -1;
	if (ra_sign * rb_sign == -1)
		return (ra * ra_sign + rb * rb_sign);
	else if (ra * ra_sign < rb * rb_sign)
		return (rb * rb_sign);
	else
		return (ra * ra_sign);
}

// int main(void)
// {
//     // Creazione di una lista di esempio
//     t_stack list;
//     list.size = 5;
//     list.top = NULL;
//     list.bottom = NULL;

//     // Popolamento della lista con alcuni valori di esempio
//     t_node *node1 = malloc(sizeof(t_node));
//     t_node *node2 = malloc(sizeof(t_node));
//     t_node *node3 = malloc(sizeof(t_node));
//     t_node *node4 = malloc(sizeof(t_node));
//     t_node *node5 = malloc(sizeof(t_node));

//     node1->data = 1;
//     node2->data = 2;
//     node3->data = 8;
//     node4->data = 5;
//     node5->data = 4;

//     node1->prev = NULL;
//     node1->next = node2;
//     node2->prev = node1;
//     node2->next = node3;
//     node3->prev = node2;
//     node3->next = node4;
//     node4->prev = node3;
//     node4->next = node5;
//     node5->prev = node4;
//     node5->next = NULL;

//     list.top = node1;
//     list.bottom = node5;

//     // Calcolo del massimo e del minimo
//     int max = max0min(&list, 0);
//     int min = max0min(&list, 1);

//     // Stampa dei risultati
//     printf("Massimo: %d\n", max);
//     printf("Minimo: %d\n", min);

//     return 0;
// }