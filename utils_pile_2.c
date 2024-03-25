/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:15:29 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/25 09:20:52 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_pile(t_stack *pile)
{
	if (!is_empty_stack(pile))
	{
		ft_printf("[%d]\n",pile->value);
		pile = pile->next;
		print_pile(pile);
	}
}
