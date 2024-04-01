/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:49:48 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/30 16:17:43 by vrandria         ###   ########.fr       */
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
			if (prev->value == tmp->value)
				value++;
			prev = prev->next;
		}
	}
	if (value > 1)
		{
			print_error();
			return(1);
		}
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