/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:08:46 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/28 09:31:57 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate_pile(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*top;

	if (*pile != 0 && (*pile)->next != 0)
	{
		top = (*pile)->next;
		temp = (*pile);
		(*pile) = bottom_pile(*pile);
		(*pile)->next = temp;
		*pile = (*pile)->next;
		(*pile)->next = new_stack();
		*pile = top;
	}
}

t_container	*ft_rotate_a(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_a;
	next = pile->next;
	if (pile != 0 && pile->next != 0)
	{
		ft_rotate_pile(&pile);
		ft_printf("ra\n");
		container->hit += 1;
	}
	container->top_a = next;
	return (container);
}

t_container	*ft_rev_rotate_a(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_b;
	next = pile->next;
	if (pile != 0 && pile->next != 0)
	{
		ft_rotate_pile(&pile);
		ft_printf("rb\n");
		container->hit += 1;
	}
	container->top_b = next;
	return (container);
}

t_container	*ft_rotate_r(t_container *container)
{
	t_stack	*pile;
	void	*next;

	pile = container->top_b;
	next = pile->next;
	if (pile != 0 && pile->next != 0)
	{
		ft_rotate_pile(&pile);
		container->top_b = next;
	}
	pile = container->top_a;
	next = pile->next;
	if (pile != 0 && pile->next != 0)
	{
		ft_rotate_pile(&pile);
		container->top_a = next;
	}
	ft_printf("rr\n");
	container->hit += 1;
	return (container);
}
