/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:55:25 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/08 16:55:25 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *getnode(int data)
{
  t_node  *new;

  new = malloc(sizeof(t_node));
  if (!new)
    return (NULL);
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}
