/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:08:46 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/28 09:09:38 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_container	*push_b(t_container *container)
{
	container->pile_a = container->top_a;
	container->pile_b = container->top_b;
	container->size_pile_a = ft_pile_size(container->pile_a);
	if (container->size_pile_a >= 1)
	{
		container->top_a = container->pile_a->next;
		container->pile_a->next = container->pile_b;
		container->top_b = container->pile_a;
		container->hit = container->hit + 1;
	}
	container->size_pile_a = ft_pile_size(container->pile_a);
	ft_printf("pb\n");
	return (container);
}

t_container	*push_a(t_container *container)
{
	container->pile_b = container->top_b;
	container->pile_a = container->top_a;
	container->size_pile_b = ft_pile_size(container->pile_b);
	if (container->size_pile_b >= 1)
	{
		container->top_b = container->pile_b->next;
		container->pile_b->next = container->pile_a;
		container->top_a = container->pile_b;
		container->hit = container->hit + 1;
	}
	container->size_pile_b = ft_pile_size(container->pile_b);
	ft_printf("pa\n");
	return (container);
}
