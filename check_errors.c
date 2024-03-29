/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:49:48 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/29 10:59:45 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
}
int	si_atoiable(const char *str)
{
	int	i;
	int	count;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	count = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] <= 32)
	{
		i++;
		count++;
	}
	if (str[i] || count == 0 || count > 10)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	ft_check_double(t_stack *pile)
{
	int	value;
	t_stack *prev;
	t_stack	*tmp;
	t_stack *top;

	prev = pile;
	tmp = pile;
	top = pile;
	value = 0;
	while (prev->next != NULL)
	{
		tmp = top;
		while(tmp->next != NULL)
		{
			if (prev->value == pr)

			prev = prev->next;
		}
	}
	return (0);
}