/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:16:59 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/05 08:16:59 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_node
{
  int            data;
  struct s_node *next;
  struct s_node *prev;
}             t_node;

typedef struct s_stack
{
  int         size;
  struct s_node   *top;
  struct s_node   *bottom;
}               t_stack;

t_stack   *stack_init(void);
t_node    *getnode(int data);
void      error(void);
int       ft_atoi2(char *str, int len);
void      push_top(t_stack *list, int data);
void      pop_top(t_stack *list);
void      push_bottom(t_stack *list, int data);
void      pop_bottom(t_stack *list);
void      clear(t_stack *list);
#endif