/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:21:59 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/05 08:21:59 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

void  error(void)
{
  write(2, "Error\n", 6);
}

void  insert_check(int ac, char **av)
{
  int i;
  int j;

  i = 1;
  while (i < ac)
  {
    j = 0;
    while (av[i][j])
    {
      if (av[i][j] == '+' || av[i][j] == '-')
      {
        if (av[i][j] >= '0' && av[i][j] <= '9')
          j++;
        else
          error();
      }
      else if ((av[i][j] >= '0' && av[i][j] <= '9' )|| av[i][j] == '-')
        j++;
      else
        error();
    }
    i++;
  }
}