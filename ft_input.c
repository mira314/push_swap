/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:10:02 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/09 09:02:07 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long	*indexation(t_container *container, long *tab, int size)
{
	long	tmp;
	long	i;

	while (size--)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
	return (tab);
}

t_container	*fill_container_one(const char *str)
{
	t_container	*container;
	int	i;
	char	**splited;
	i = 0;
	container = malloc(sizeof(t_container) + 1);
	if (!container)
		return (0);
	container = initialiser(container);
	splited = ft_split(str, ' ');
	while (splited[i])
	{
		if (!si_atoiable(splited[i]))
		{
			container->top_a = clear_pile(container->top_a);
			while (splited[i])
				free(splited[i++]);
			free(splited);
			free(container);
			return (0);
		}
		container->top_a = insert_pile(container->top_a, ft_atoi(splited[i]));
		free(splited[i++]);
	}
	free(splited);
	return (container);
}

t_container	*fill_container_multi(int argc, const char *argv[])
{
	t_container	*container;
	int			i;

	i = 1;
	container = malloc(sizeof(t_container) + 1);
	if (!container)
		return (0);
	container = initialiser(container);
	while (i <= argc - 1)
	{
		if (!si_atoiable(argv[i]))
		{
			container->top_a = clear_pile(container->top_a);
			free(container);
			return (0);
		}
		container->top_a = insert_pile(container->top_a, ft_atoi(argv[i]));
		i++;
	}
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
	return (container);
}

