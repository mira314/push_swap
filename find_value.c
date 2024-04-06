/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 07:33:29 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/06 09:15:14 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_sort_median(int *tab, int size)
{
	int	tmp;
	int	i;
	int median;
	median = size / 2;
	while (size--)
	{
		i = 0;
		while (i < size -1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
	return (tab[median]);
}
int	cost_go_to_this_element(t_stack *pile, int value)
{
	int	move;
	t_stack *temp;

	temp = pile;
	move = 0;
	while (temp->value != value)
	{
		if (temp->next == NULL)
			return (-1);
		move++;
		temp = temp->next;
	}
	return (move);
}
int	find_median(t_container *container)
{
	t_stack *tmp;
	int median;
	int *tab;
	int	size;
	int i;

	i = 0;
	size = ft_pile_size(container->pile_a);
	tmp = container->pile_a;
	tab =(int *)malloc(sizeof(int) * size);
		if (!tab)
			return (-1);
	while (tmp->next != NULL)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	median = ft_sort_median(tab, size);
	free(tab);
	return (median);
}