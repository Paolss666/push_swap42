/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:34:06 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/08 17:34:06 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  sa(t_stack *a)
{
  int tmp;

  tmp = a->top->data;
  a->top->data = a->top->prev->data;
  a->top->prev->data = tmp;
  ft_printf("sa\n");
}

void  sb(t_stack *b)
{
  int tmp;

  tmp = b->top->data;
  b->top->data = b->top->prev->data;
  b->top->prev->data = tmp;
  ft_printf("sb\n");
}