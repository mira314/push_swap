/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:08:46 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/26 11:22:57 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate_pile(t_stack **pile)
{
	t_stack	*temp;
	t_stack *top;
	//t_stack *bottom;


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
