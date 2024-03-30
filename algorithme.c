/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:15:15 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/30 16:52:48 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	two_element(t_container *container)
{
	if (container->pile_a->value > container->pile_a->next->value)
		container	= swap_a(container);
}

void	three_element(t_container *container)
{
	if (container->pile_a->value > container->pile_a->next->value)
	{
		if (container->pile_a->next->value <container->pile_a->next->next->value)
		{
			if (container->pile_a->value > container->pile_a->next->next->value)
				container = ft_rotate_a(container);
			else
				container = swap_a(container);
		}
		else
		{
			container = swap_a(container);
			container = reverse_rotate_a(container);
		}
	}
	else
	{
		if (container->pile_a->value > container->pile_a->next->next->value)
			container =  reverse_rotate_a(container);
		else
			container =  three_not_order(container);
	}
}
t_container	*three_not_order(t_container *container)
{
	container =  ft_rotate_a(container);
	container = swap_a(container);
	container = reverse_rotate_a(container);
	return (container);
}
