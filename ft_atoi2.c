/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:53:16 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/22 15:19:18 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned long long int	answer(unsigned long long int num, int sign,
								t_stack *a, t_stack *b)
{
	int	l;

	l = num * sign;
	if (sign == -1 && num > 2147483648)
		clear2stack_error(a, b);
	if (sign == 1 && num > 2147483647)
		clear2stack_error(a, b);
	return (l);
}

int	ft_atoi2(char *str, int len, t_stack *a, t_stack *b)
{
	int					sign;
	int					i;
	unsigned long long	num;

	num = 0;
	sign = 1;
	i = 0;
	str[len] = '\0';
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign *= -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (answer(num, sign, a, b));
}
