/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:45:56 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/05 10:45:56 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_init(void)
{
  t_stack *stack;

  stack = malloc(sizeof(t_stack));
  stack->top = NULL;
  stack->bottom = NULL;
  stack->size = 0;
  return (stack);
}

void  push_top(t_stack *list, int data)
{
  t_node  *new;
  t_node  *oldtop;

  new = getnode(data);
  if (list->top == NULL)
  {
    list->top = new;
    list->bottom = new;
  }
  else
  {
    oldtop = list->top;
    oldtop->next = new;
    new->prev = oldtop;
    list->top = new;
  }
  list->size++;
}

void printStack(t_stack* list) {
  t_node* current = list->top;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->prev;
  }
  printf("\n");
}

int main(void) {
  t_stack list;
  list.top = NULL;
  list.bottom = NULL;
  list.size = 0;

  push_top(&list, 1);
  push_top(&list, 2);
  push_top(&list, 3);
  push_top(&list, 4);

  printf("Stack contents: ");
  printStack(&list);

  return 0;
}






