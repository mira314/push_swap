/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 07:33:29 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/06 17:25:01 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_sort_median(int *tab, int size, int median)
{
	int	tmp;
	int	i;
	int med;
	med = size / median;
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
	return (tab[med]);
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
int	find_median(t_container *container, int median)
{
	t_stack *tmp;
	int med;
	int *tab;
	int	size;
	int i;

	i = 0;
	container = updatel(container);
	size = ft_pile_size(container->top_a);
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
	med = ft_sort_median(tab, size, median);
	free(tab);
	return (med);
}
int	find_below_median(t_stack *pile, int median)
{
	t_stack *tmp;
	int	count;

	count = 0;
	tmp = pile;
	while (tmp != NULL)
	{
		if ((tmp->value) < median)
			{
				count++;
				ft_printf("***************************%d vs %d count est %d\n",tmp->value, median, count);
			}
		tmp = tmp->next;
	}
	if (count >= 1)
	{
		return (1);
	}
	return (0);
}