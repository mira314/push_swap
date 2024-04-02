/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:08:21 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/02 08:12:14 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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