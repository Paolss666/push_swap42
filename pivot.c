/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:34 by npaolett          #+#    #+#             */
/*   Updated: 2023/06/21 13:24:53 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
Il pivot viene scelto come ultimo elemento dell'array.
partizione in due. 
a sinistra del pivot <= pivot et a destra >=pivot 
ripete i passaggi 1 e 3 ricorsivamente per i due sotto-array fino a quando
l'array non e' completamente ordinato
Nella funzione quick,
l'algoritmo di partizionamento viene implementato attraverso 
un'iterazione che utilizza due indici i e j.
L'indice i viene incrementato finché gli elementi dell'array 
a sinistra di esso sono più piccoli del pivot.
L'indice j viene decrementato finché gli elementi dell'array 
a destra di esso sono più grandi del pivot. 
Quando i e j si incrociano o si sovrappongono, la partizione è completata.
Durante l'iterazione, se i è minore di j, 
viene eseguito uno scambio tra gli elementi arr[i] e arr[j] 
per posizionare correttamente gli elementi più 
piccoli e più grandi rispetto al pivot.
*/

void	quick(int start, int end, int *arr)
{
	int	p;
	int	i;
	int	j;

	if (start >= end)
		return ;
	p = end;
	i = start;
	j = end - 1;
	while (i <= j)
	{
		while (i <= end && arr[i] < arr[p])
			++i;
		while (j >= start && arr[j] > arr[p])
			--j;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[i], &arr[p]);
	quick(start, i - 1, arr);
	quick(i + 1, end, arr);
}

/*
Nella funzione pivot(),
vengono creati un array dinamico arr per memorizzare 
i valori della lista e un array p per i valori di pivot calcolati.
Viene inizializzato un puntatore now con il top della lista. 
Successivamente, viene eseguito un loop 
per copiare i valori della lista nell'array arr.
Dopo aver copiato tutti i valori, viene chiamata la funzione quick() 
per ordinare l'array arr.
Infine, i valori di pivot vengono calcolati in base all'indice dell'array arr 
e restituiti come risultato.
*/

int	pivot(t_stack *list, int num)
{
	int		*arr;
	int		p[4];
	int		i;
	t_node	*now;

	arr = (int *)malloc(sizeof(int) * list->size);
	if (!arr)
		return (0);
	i = 0;
	now = list->top;
	while (i < list->size)
	{
		arr[i] = now->data;
		now = now->prev;
		i++;
	}
	quick(0, i - 1, arr);
	p[0] = (arr[(i - 1) / 5]);
	p[1] = (arr[(((i - 1) / 5) * 2)]);
	p[2] = (arr[(((i - 1) / 5) * 3)]);
	p[3] = (arr[(((i - 1) / 5) * 4)]);
	free(arr);
	return (p[num]);
}

/*
suddividiamo l'array in diverse sezioni. 
nella prima fase facciamo solo una divizione per 5 
che significa che il primo valore del pivot verra preso ogni 
5 elementi in arr.
- * 2 vuol dire che lo prendo in una distanza doppia del primo. esempio 10.
- etc etc
*/