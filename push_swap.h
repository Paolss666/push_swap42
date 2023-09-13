/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:00:28 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/22 15:54:48 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

// MAIN ET CHECK
t_stack				*stack_init(void);
t_node				*getnode(int data);
void				error(void);
void				clear2stack_error(t_stack *a, t_stack *b);
int					ft_strlen(char *s);
int					ft_atoi2(char *str, int len, t_stack *a, t_stack *b);
void				insert_check(int ac, char **av,
						t_stack *a, t_stack *b);
void				samesame(t_stack *a, t_stack *b);
void				sortcheck(t_stack *a, t_stack *b);
void				trance(t_stack *a, char *str, t_stack *b);
void				trance_string(int ac, char **av, t_stack *a, t_stack *b);

// ALGO
int					max0min(t_stack *list, int num);
int					maxormin(t_stack *a, int min);
int					cal(int ra, int rb);
int					best(int ra_c, int rb_c, int new_ra_c, int new_rb_c);
void				swap(int *a, int *b);
int					pivot(t_stack *list, int num);
void				quick(int start, int end, int *arr);
int					count_ra(t_stack *a, int data);
void				count(t_stack *a, t_stack *b, int *ra_c, int *rb_c);
void				btoa(t_stack *a, t_stack *b);
void				finish(t_stack *a);
void				division3(t_stack *a, t_stack *b);
void				division2(t_stack *a, t_stack *b, int p3, int p0);
void				division(t_stack *a, t_stack *b);
void				atob(t_stack *a, t_stack *b);

// MANIP LIST
void				push_top(t_stack *list, int data);
void				pop_top(t_stack *list);
void				push_bottom(t_stack *list, int data);
void				pop_bottom(t_stack *list);
void				clear(t_stack *list);

// REGLE
void				sb(t_stack *b);
void				sa(t_stack *a);
void				ss(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				rrrab(t_stack *a, t_stack *b, int *ra_c, int *rb_c);
void				rrra(t_stack *a, int *ra_c);
void				rrrb(t_stack *b, int *rb_c);
void				logic(t_stack *a);
void				logic_plus(t_stack *a);

#endif