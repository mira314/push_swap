/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:08:46 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/26 07:46:39 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate_pile(t_stack **pile)
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
