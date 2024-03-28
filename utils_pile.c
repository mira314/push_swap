/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:50:38 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/28 08:25:21 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*new_stack(void)
{
	return (0);
}

int	is_empty_stack(t_stack *pile)
{
	if (pile == 0)
		return (1);
	return (0);
}

t_stack	*insert_pile(t_stack *pile, int value)
{
	t_stack	*new_pile;

	new_pile = malloc(sizeof(t_stack));
	if (!new_pile)
		return (0);
	new_pile->value = value;
	new_pile->next = pile;
	return (new_pile);
}

t_stack	*clear_pile(t_stack *pile)
{
	t_stack	*tmp;

	if (is_empty_stack(pile))
		return (new_stack());
	tmp = pile->next;
	free(pile);
	return (clear_pile(tmp));
}

void	*del_one_pile(t_stack *pile)
{	
	t_stack	*tmp;

	if (!is_empty_stack(pile))
	{
		tmp = pile->next;
		free(pile);
	}
	return (tmp);
}
