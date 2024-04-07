/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:15:29 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/07 10:07:08 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_pile(t_stack *pile_a)
{
	if (!is_empty_stack(pile_a))
	{
		ft_printf("\n\t [%d] ", pile_a->value);
		pile_a = pile_a->next;
		print_pile(pile_a);
	}
}

t_stack	*bottom_pile(t_stack *pile)
{
	while (pile->next != NULL)
		pile = pile->next;
	return (pile);
}

int	ft_pile_size(t_stack *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}

t_container	*updatel(t_container *ct)
{
	ct->pile_a = ct->top_a;
	ct->pile_b = ct->top_b;
	ct->size_pile_a = ft_pile_size(ct->pile_a);
	ct->size_pile_b = ft_pile_size(ct->pile_b);
	return (ct);
}
