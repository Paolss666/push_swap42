/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:25:52 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/20 17:01:19 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	division3(t_stack *a, t_stack *b)
{
	int	max;
	int	min;
	int	a_size;
	int	p1;

	a_size = a->size;
	max = max0min(a, 0);
	min = max0min(a, 1);
	p1 = (max + min) / 3;
	while (a_size--)
	{
		if (a->top->data > p1 * 2)
			ra(a);
		else
		{
			pb(a, b);
			if (b->top->data < p1)
				rb(b);
		}
	}
}

void	division2(t_stack *a, t_stack *b, int p3, int p0)
{
	int	a_size;

	a_size = a->size;
	while (a_size--)
	{
		if (a->top->data > p3)
			ra(a);
		else
		{
			pb(a, b);
			if (b->top->data <= p0)
				rb(b);
		}
	}
}

void	division(t_stack *a, t_stack *b)
{
	int	p[4];
	int	a_size;

	p[0] = pivot(a, 0);
	p[1] = pivot(a, 1);
	p[2] = pivot(a, 2);
	p[3] = pivot(a, 3);
	a_size = a->size;
	while (a_size--)
	{
		if (a->top->data > p[2] || a->top->data <= p[0])
			ra(a);
		else if (a->top->data <= p[2] && a->top->data > p[0])
		{
			pb(a, b);
			if (b->top->data < p[1])
				rb(b);
		}
	}
	division2(a, b, p[3], p[0]);
}

// void print_stack(t_stack *stack) {
//     t_node *current = stack->top;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->prev;
//     }
//     printf("\n");
// }

// void division3(t_stack *a, t_stack *b) {
//     int max;
//     int min;
//     int a_size;
//     int p1;

//     a_size = a->size;
//     max = max0min(a, 0);
//     min = max0min(a, 1);
//     p1 = (max + min) / 3;
//     while (a_size--) {
//         if (a->top->data > p1 * 2) {
//             ra(a);
//             printf("ra(a): ");
//             print_stack(a);
//         } else {
//             pb(a, b);
//             printf("pb(a, b): ");
//             printf("a: ");
//             print_stack(a);
//             printf("b: ");
//             print_stack(b);
//             if (b->top->data < p1) {
//                 rb(b);
//                 printf("rb(b): ");
//                 print_stack(b);
//             }
//         }
//     }
// }

// void division2(t_stack *a, t_stack *b, int p3, int p0) {
//     int a_size;

//     a_size = a->size;
//     while (a_size--) {
//         if (a->top->data > p3) {
//             ra(a);
//             printf("ra(a): ");
//             print_stack(a);
//         } else {
//             pb(a, b);
//             printf("pb(a, b): ");
//             printf("a: ");
//             print_stack(a);
//             printf("b: ");
//             print_stack(b);
//             if (b->top->data <= p0) {
//                 rb(b);
//                 printf("rb(b): ");
//                 print_stack(b);
//             }
//         }
//     }
// }

// void division(t_stack *a, t_stack *b) {
//     int p[4];
//     int a_size;

//     p[0] = pivot(a, 0);
//     p[1] = pivot(a, 1);
//     p[2] = pivot(a, 2);
//     p[3] = pivot(a, 3);
//     a_size = a->size;
//     while (a_size--) {
//         if (a->top->data > p[2] || a->top->data <= p[0]) {
//             ra(a);
//             printf("ra(a): ");
//             print_stack(a);
//         } else if (a->top->data <= p[2] && a->top->data > p[0]) {
//             pb(a, b);
//             printf("pb(a, b): ");
//             printf("a: ");
//             print_stack(a);
//             printf("b: ");
//             print_stack(b);
//             if (b->top->data < p[1]) {
//                 rb(b);
//                 printf("rb(b): ");
//                 print_stack(b);
//             }
//         }
//     }
//     division2(a, b, p[3], p[0]);
// }

// int main() {
//     // Definisci gli array a e b come stack iniziali
//     t_stack *a;
//     t_stack *b;

//     // Inizializza gli stack a e b con i dati desiderati
// a = stack_init();
// b = stack_init();

//     // Aggiungi i numeri desiderati all'array a
//     push_top(a, 9);
//     push_top(a, 3);
//     push_top(a, 7);
//     push_top(a, 5);
//     push_top(a, 2);
//     push_top(a, 6);
//     push_top(a, 1);
//     push_top(a, 8);
//     // Esegui la divisione
//     printf("Stato iniziale di a: ");
//     print_stack(a);
//     printf("Stato iniziale di b: ");
//     print_stack(b);

//     division3(a, b);

//     printf("Stato finale di a: ");
//     print_stack(a);
//     printf("Stato finale di b: ");
//     print_stack(b);

//     return 0;
// }