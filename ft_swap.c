/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 07:31:02 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/26 07:31:30 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
///void	sa()

//void	sa()

//void	ss()

void	ft_swap_pile(t_stack **pile)
{
	t_stack	*temp;

	if (*pile != 0 && (*pile)->next != 0)
	{
		temp = (*pile)->next;
		(*pile)->next = (*pile)->next->next;
		temp->next = *pile;
		*pile = temp;
	}
}
