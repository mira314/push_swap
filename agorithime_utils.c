/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agorithime_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:32:55 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/12 09:45:32 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	six_element(t_container *container)
{
	container = push_min_value(container);
	if (!order_ok(container))
		five_element(container);
	container = updatel(container);
	container = push_a(container);
	container = updatel(container);
}

t_container	*split_recusive(t_container *container)
{
	int	size;

	container = updatel(container);
	size = container->size_pile_a;
	while (size > 6)
	{
		container = split_pile(container);
		container = updatel(container);
		size = container->size_pile_a;
	}
	if (size == 6)
		six_element(container);
	else if (size == 5)
		five_element(container);
	else if (size == 4)
		four_element(container);
	else if (size == 3)
		three_element(container);
	else
		two_element(container);
	container = updatel(container);
	return (container);
}
