/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:15:15 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/06 10:22:12 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
static t_container *three_not_order(t_container *container)
{
    container->top_a = container->pile_a;
    container = ft_rotate_a(container);
    container = swap_a(container);
    container = reverse_rotate_a(container);
    return (container);
}
void two_element(t_container *container)
{
    if (container->pile_a->value > container->pile_a->next->value)
        container = swap_a(container);
}
void three_element(t_container *container)
{
    t_stack *a = container->pile_a;
    
    if (a->value > a->next->value && a->next->value < a->next->next->value)
        container = ft_rotate_a(container);
    else if (a->value > a->next->value && a->next->value > a->next->next->value)
    {
        container = swap_a(container);
        container = reverse_rotate_a(container);
    }
    else if (a->value > a->next->value && a->next->value < a->next->next->value)
        container = swap_a(container);
    else if (a->value < a->next->value && a->next->value > a->next->next->value)
        container = reverse_rotate_a(container);
    else if (a->value < a->next->value && a->next->value > a->next->next->value)
        container = three_not_order(container);
}


void four_element(t_container *container)
{
 container = push_min_value(container);

    if (!order_ok(container))
        three_element(container);
    container = updatel(container);
  //  container = push_a(container);
    container = updatel(container);
}
void five_element(t_container *container)
{
 container = push_min_value(container);

    if (!order_ok(container))
        four_element(container);
    container = updatel(container);
    container = push_a(container);
    container = updatel(container);

}