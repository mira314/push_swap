/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:08:21 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/06 09:49:10 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min(t_stack *pile)
{
	int	min;
	t_stack *tmp;
	int size;

	min = 2147483647;
	size = ft_pile_size(pile);
	tmp = pile;
	while (size--)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_stack *pile)
{
	int	max;
	t_stack *tmp;
	int size;

	max = -2147483648;
	size = ft_pile_size(pile);
	tmp = pile;
	while (size--)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

t_container *split_pile(t_container *container)
{

	t_stack *lst_a;

	lst_a = 0;
	int size;

	size = (container->size_pile_a / 2);
	if ((container->pile_a == NULL) || (container->pile_a->next == NULL))
		return (container);
	else
	{
		while (size--)
		{
			//three_element(container);
			container = push_b(container);
			container = updatel(container);
			lst_a = bottom_pile(container->pile_a);
			if (lst_a->value < container->pile_a->value)
				container = ft_rotate_a(container);
			container = updatel(container);
		}
	}
		return (container);
}

t_container *fusion_pile(t_container *container)
{
	t_stack *lst_a;

	lst_a  = 0;
	while (container->pile_b != NULL)
	{
		lst_a = bottom_pile(container->pile_a);
		container = push_a(container);
		container = updatel(container);
		if (lst_a->value < container->pile_a->value)
		{
			container = ft_rotate_a(container);
		}
		container = updatel(container);
		three_element(container);
		container = updatel(container);
	}
	return (container);
}
t_container *push_min_value(t_container *container)
{
	t_stack *temp;
	int min;

	min = find_min(container->pile_a);
	temp = container->pile_a;
	while (1)
		{
			if (temp->value == min)
			{
				container = push_b(container);
				break;
			}
			if (cost_go_to_this_element(temp, min) <= (ft_pile_size(temp) / 2))
			{
				temp = temp->next;
				container = ft_rotate_a(container);
			}
			else
			{
				temp = bottom_pile(container->pile_a);
				container = reverse_rotate_a(container);
			}
		}
	container = updatel(container);
	return (container);
}