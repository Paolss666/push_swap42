/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:48:58 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/22 15:53:00 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	clear2stack_error(t_stack *a, t_stack *b)
{
	clear(a);
	clear(b);
	error();
}

/*
check se i parametri presenti nell esecuzione sono solo numeri e non sono
lettere. Senno riinviamo errore. (chekkiamo anche se ci sono caratteri scitti
con un piu o con un meno).
*/

void	insert_check(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j + 1] >= '0' && av[i][j + 1] <= '9')
					j++;
				else
				{
					clear2stack_error(a, b);
				}
			}
			else if ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' ')
				j++;
			else
				clear2stack_error(a, b);
		}
		i++;
	}
}

/*
leggiamo la stringa, per esempio se e' scritta con le  " "
convertiamo i numeri e li mettiamo nella nostra pile con push_bottom
*/

void	trance(t_stack *a, char *str, t_stack *b)
{
	int	i;
	int	j;
	int	num;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i] == ' ')
			i++;
		while (str[i + j] != '\0' && str[i + j] != ' ')
			j++;
		num = ft_atoi2(&str[i], j, a, b);
		push_bottom(a, num);
		i = i + j;
		i++;
	}
}

/*
check se ci sono cifre uguali
*/

void	samesame(t_stack *a, t_stack *b)
{
	int		tmp;
	t_node	*i;
	t_node	*j;

	i = a->top;
	if (!i)
		return ;
	while (i)
	{
		tmp = i->data;
		j = i->prev;
		while (j)
		{
			if (tmp == j->data)
				clear2stack_error(a, b);
			j = j->prev;
		}
		i = i->prev;
	}
}
