/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:49:48 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/07 17:00:52 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

int	si_atoiable(const char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	count = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == 32)
	{
		i++;
		count++;
	}
	if (str[i] || count == 0 || count > 10)
	{
		return (0);
	}
	return (1);
}

int	ft_check_double(t_container *container)
{
	int		value;
	t_stack	*prev;
	t_stack	*tmp;

	prev = container->top_a;
	tmp = container->top_a;
	value = 0;
	while (prev->next != NULL)
	{
		tmp = container->top_a;
		prev = prev->next;
		while (tmp != NULL)
		{
			if (tmp->value == prev->value)
			{
				value++;
				if (value >= 2)
					return (1);
			}
			tmp = tmp->next;
		}
		value = 0;
	}
	container = updatel(container);
	return (0);
}

int	order_ok(t_container *container)
{
	t_stack	*temp;

	temp = container->pile_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
