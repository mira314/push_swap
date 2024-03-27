/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:08:46 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/27 11:11:31 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rev_rotate_pile(t_stack **pile)
{
	t_stack *top;

	if (*pile != 0 && (*pile)->next != 0)
	{
		top = (*pile);
		while ((*pile)->next->next != NULL)
			(*pile) = (*pile)->next;
		(*pile)->next->next = top;
		(*pile)->next = new_stack();
		(*pile) = top;
	}
}