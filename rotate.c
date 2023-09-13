/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:51:29 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/13 16:53:14 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	push_bottom(a, a->top->data);
	pop_top(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	push_bottom(b, b->top->data);
	pop_top(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	push_bottom(a, a->top->data);
	pop_top(a);
	push_bottom(b, b->top->data);
	pop_top(b);
	write(1, "rr\n", 3);
}

// int main(int argc, char *argv[])
// {
// 	t_stack stack_a = { 0, NULL, NULL };
// 	t_stack stack_b = { 0, NULL, NULL };

// 	// Esegui le operazioni desiderate basate 
// 	//sugli argomenti da riga di comando
// 	// Esempio:
// 	for (int i = 1; i < argc; i++)
// 	{
// 		int data = atoi(argv[i]);
// 		push_bottom(&stack_a, data);
// 	}

// 	ra(&stack_a);
// 	rb(&stack_b);
// 	rr(&stack_a, &stack_b);
// 	return (0);
// }