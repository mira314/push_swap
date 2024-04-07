/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:08:21 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/07 12:47:33 by vrandria         ###   ########.fr       */
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
t_container *split_pile_min_b(t_container *container)
{
	int	median;
	int size;

	median = find_median_b(container, 2);
	size = container->size_pile_b;
		while (size--)
	{
		if (container->pile_b->value > median)
			container = push_a(container);
		else
			container = ft_rotate_b(container);
		container = updatel(container);
	}
	return (container);

}

t_container *split_pile(t_container *container)
{
	int	median;
	int size;

	container = updatel(container);
	size = container->size_pile_a;
	median = find_median_a(container, 2);
	while (size-- && find_below_median(container->pile_a, median) != 0)
	{
		if (container->pile_a->value < median)
			container = push_b(container);
		else
			container = ft_rotate_a(container);
		container = updatel(container);
	}
	while (container->size_pile_b > 3)
	container = split_pile_min_b(container);
		return (container);
}
/*
t_container *fusion_pile(t_container *container)
{
	t_stack *b;
	int	max;
	int move;

	move = 0;
	b = container->pile_b;
	max = find_max(b);
	while (b != NULL)
	{
		if (b->value == max)
		{
			container = push_a(container);
			break;
		}
	if (cost_go_to_this_element(b,max) < (container->size_pile_b / 2))
		{
		b = b->next;
		container = ft_rotate_b(container);
		container = updatel(container);
		}
		else
		{
			b = bottom_pile(b);
			container = reverse_rotate_b(container);
			container = updatel(container);
		}
	}
	container = updatel(container);
	return (container);
}
*/
t_container *fusion_pile(t_container *container)
{
	t_stack *b;
	int	max;

	b = container->pile_b;
	max = find_max(b);
	while (b != NULL)
	{
		if (b->value == max)
		{
			container = push_a(container);
			break;
		}
	if (cost_go_to_this_element(b,max) < (container->size_pile_b / 2))
		{
		b = b->next;
		container = ft_rotate_b(container);
		container = updatel(container);
		}
		else
		{
			b = bottom_pile(b);
			container = reverse_rotate_b(container);
			container = updatel(container);
		}
	}
	container = updatel(container);
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
			if (temp->value == min)
			{
				container = push_b(container);
				break;
			}
		}
	container = updatel(container);
	return (container);
}
t_container *fusion_pile_to_b(t_container *container)
{
	t_stack *b;
	int	min;

	b = container->pile_a;
	container = updatel(container);
	int p = 1;
	//while (container->size_pile_a >= container->size_pile_b)

	while (p--)
	{
		min = find_min(b);
		while (1)
		{
			if (b->value == min)
			{
				container = push_b(container);
				break;
			}
			if (cost_go_to_this_element(b,min) < (container->size_pile_a / 2))
			{
				b = b->next;
				container = ft_rotate_a(container);
			}
			else
			{
				b = bottom_pile(b);
				container = reverse_rotate_a(container);
			}
			container = updatel(container);
		}
		container = updatel(container);
	}
	container = updatel(container);
	return (container);
}