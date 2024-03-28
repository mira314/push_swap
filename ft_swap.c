/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 07:31:02 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/28 09:00:44 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap_pile(t_stack **pile)
{
	t_stack	*temp;

	temp = *pile;
	if (*pile != 0 && (*pile)->next != 0)
	{
		temp = (*pile)->next;
		(*pile)->next = (*pile)->next->next;
		temp->next = *pile;
		*pile = temp;
	}
}

t_container	*swap_a(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_a;
	next = pile->next;
	if (pile != 0 && pile->next != 0)
	{
		ft_swap_pile(&pile);
		ft_printf("sa\n");
		container->hit += 1;
	}
	container->top_a = next;
	return (container);
}

t_container	*swap_b(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_b;
	next = pile->next;
	if (pile != 0 && pile->next != 0)
	{
		ft_swap_pile(&pile);
		ft_printf("sb\n");
		container->hit += 1;
	}
	container->top_b = next;
	return (container);
}

t_container	*swap_ss(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_b;
	next = pile->next;
	if (pile != 0 && pile->next != 0)
		ft_swap_pile(&pile);
	container->top_b = next;
	pile = container->top_a;
	next = pile->next;
	if (pile != 0 && pile->next != 0)
		ft_swap_pile(&pile);
	container->top_a = next;
	container->hit += 1;
	ft_printf("ss\n");
	return (container);
}
