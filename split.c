/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 06:52:37 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/09 08:13:29 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_container	*split_pile_first(t_container *container)
{
	int	median;
	int	median3;

	container = updatel(container);
	median = find_median_a(container, 2);
	median3 = find_median_a(container, 4);
	while (find_below_median(container->pile_a, median) != 0)
	{
		if (container->pile_a->value < median)
		{
			container = push_b(container);
			container = updatel(container);
			if (container->pile_b->value < median3)
			{
				if (container->pile_a->value > median)
					container = ft_rotate_r(container);
				else
					container = ft_rotate_b(container);
			}
		}
		else
			container = ft_rotate_a(container);
		container = updatel(container);
	}
	return (container);
}
