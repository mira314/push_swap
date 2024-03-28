/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:08:46 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/28 08:23:58 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void ft_rev_rotate_pile(t_stack **pile)
{
    t_stack *top;
    t_stack *temp;

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