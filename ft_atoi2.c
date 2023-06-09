/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:21:50 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/08 17:21:50 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned long long int answer(unsigned long long int num, int sign)
{
  int a;

  a = num * sign;
  if (sign == -1 && num > 2147483648)
    error();
  if (sign == 1 && num > 2147483647)
    error();
  return (a);
}

int ft_atoi2(char *str, int len)
{
  int                 sign;
  int                 i;
  unsigned long long  num;

  num = 0;
  sign = 1;
  i = 0;
  str[len] = '\0';
  while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
    i++;
  if (str[i] == '+' && (str[i + 1] >= 9 && str[i + 1] <= 13))
    i++;
  if (str[i] == '-' && (str[i + 1] >= 9 && str[i + 1] <= 13))
  {
    sign *= -1;
    i++;
  }
  if (!(str[i] >= 9 && str[i] <= 13))
    error();
  while (str[i] >= 9 && str[i] <= 13)
  {
    num = num * 10 + (str[i] - '0');
    i++;
  }
  return (answer(num, sign));
}