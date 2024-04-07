/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:08:46 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/07 10:12:40 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rev_rotate_pile(t_stack **pile)
{
	t_stack	*top;
	t_stack	*temp;

	temp = 0;
	top = (*pile);
	if (*pile != 0 && (*pile)->next != 0)
	{
		while (top->next != 0)
		{
			temp = top;
			top = top->next;
		}
		temp->next = new_stack();
		top->next = (*pile);
		*pile = top;
	}
}

t_container	*reverse_rotate_a(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_a;
	next = bottom_pile(pile);
	if (pile != 0 && pile->next != 0)
	{
		ft_rev_rotate_pile(&pile);
		ft_printf("rra\n");
		container->hit += 1;
	}
	container->top_a = next;
	return (container);
}

t_container	*reverse_rotate_b(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_b;
	next = bottom_pile(pile);
	if (pile != 0 && pile->next != 0)
	{
		ft_rev_rotate_pile(&pile);
		ft_printf("rrb\n");
		container->hit += 1;
	}
	container->top_b = next;
	return (container);
}

t_container	*reverse_rotate_rr(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_a;
	next = bottom_pile(pile);
	if (pile != 0 && pile->next != 0)
	{
		ft_rev_rotate_pile(&pile);
		container->top_a = next;
	}
	pile = container->top_b;
	next = bottom_pile(pile);
	if (pile != 0 && pile->next != 0)
	{
		ft_rev_rotate_pile(&pile);
		container->top_b = next;
	}
	container->hit += 1;
	ft_printf("rrb\n");
	return (container);
}
