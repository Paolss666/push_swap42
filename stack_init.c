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
// agg l'int al posto del primo elemento della list.
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
// pop_top, leva il primo int nella list 
void  pop_top(t_stack *list)
{
  t_node *nowtop;
  t_node  *newtop;

  nowtop = list->top;
  if (!(nowtop))
    return ;
  else if (list->size == 1)
  {
    list->top = NULL;
    list->bottom = NULL;
  }
  else
  {
    newtop = list->top->prev;
    newtop->next = NULL;
    list->top = newtop;
  }
  list->size--;
  free(nowtop);
}
// aggiungi all 'ultimo della lista l'int
void  push_bottom(t_stack *list, int data)
{
  t_node  *new;
  t_node  *oldbottom;

  new = getnode(data);
  if (!(list->bottom))
  {
    list->top = new;
    list->bottom = new;
  }
  else
  {
    oldbottom = list->bottom;
    oldbottom ->prev = new;
    new->next = oldbottom;
    list->bottom = new;
  }
  list->size++;
}
// leva l'ultimo int dalla lista. 
void  pop_bottom(t_stack *list)
{
  t_node  *nowbottom;
  t_node  *newbottom;

  nowbottom = list->bottom;
  if (!(nowbottom))
    return ;
  else if (list->size == 1)
  {
    list->top = NULL;
    list->bottom = NULL;
  }
  else
  {
    newbottom = list->bottom->next;
    newbottom->prev = NULL;
    list->bottom = newbottom;
  }
  list->size--;
  free(nowbottom);
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
  push_top(&list, 3);

  printf("Stack contents: ");
  printStack(&list);


  printf("Stack contents pop_top: ");
  pop_top(&list);
  printStack(&list);

  printf("Stack contents push_bottom: ");
  push_bottom(&list, 6);
  printStack(&list);

  printf("Stack contents pop_bottom: ");
  pop_bottom(&list);
  printStack(&list);


  return 0;
}






