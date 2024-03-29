/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:10:02 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/29 10:39:38 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_container *fill_container_one(char *str)
{
	t_container *container;
	int	i;
	char	**splited;

	i = 0;
	splited = ft_split(str,' ');
	container = malloc(sizeof(t_container));
	container = initialiser(container);
	while (splited[i])
	{
		if (!si_atoiable(splited[i]))
		{
			free(splited);
			return (0);
		}
		container->top_a = insert_pile(container->top_a,ft_atoi(splited[i]));
		free(splited[i]);
		i++;
	}
	//container->top_b = insert_pile(container->top_b, 1);
	free(splited);
	return (container);
}
t_container	*initialiser(t_container *container)
{
	container->pile_a = new_stack();
	container->pile_b = new_stack();
	container->top_a = container->pile_a;
	container->top_b = container->pile_b;
	container->size_pile_a = 0;
	container->size_pile_b = 0;
	container->hit = 0;
	return(container);
}