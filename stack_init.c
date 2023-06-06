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

t_node *getnode(int data)
{
  t_node  *new;

  new = malloc(sizeof(t_node));
  if (new == NULL)
    return (NULL);
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_stack *stack_init(void)
{
  t_stack *stack;

  stack = malloc(sizeof(t_stack));
  stack->top = NULL;
  stack->bottom = NULL;
  stack->size = 0;
  return (stack);
}

void  *push_top(t_stack *list, int data)
{
  t_node *new;
  t_node *oldtop;

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