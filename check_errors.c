/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 07:49:48 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/02 11:07:26 by vrandria         ###   ########.fr       */
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
		return (0);
	}
	return (1);
}

int	ft_check_double(t_container *container)
{
	int	value;
	t_stack *prev;
	t_stack	*tmp;
	t_stack *top;

	prev = container->top_a;
	tmp = container->top_a;
	top = container->top_a;
	value = 0;
	tmp = top;
	while (prev->next != NULL)
	{
		tmp = container->pile_a;
		prev = prev->next;
		while(tmp->next != NULL)
		{
			if (tmp->value == prev->value)
				{
					value++;
					//ft_printf("tmp %d vs prev %d \n",tmp->value, prev->value );
					if (value > 1)
						return(1);
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