/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/09 09:00:55 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_container *sorting_index(t_container *container)
{
	t_stack	*tmp;
	long		*tab;
	int		size;
	int		i;

	i = 0;
	container = updatel(container);
	size = ft_pile_size(container->top_a);
	tmp = container->pile_a;
	tab = (long *)malloc(sizeof(long) * size);
	if (!tab)
		return (-1);
	while (tmp->next != NULL)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	tab = indexation(container, tab, size)
	free(tab);
	return (container);
}
int main(int argc, const char *argv[])
{	
	t_container *container;

	if (argc == 1)
		return (0);
	if (argc == 2)
		container = fill_container_one(argv[1]);
	if (argc > 2)
		container = fill_container_multi(argc, argv);
	if (container == 0)
	{
		print_error();
		return (0);
	}
	if (ft_check_double(container) == 1)
	{
		container->top_a = clear_pile(container->top_a);
		container->top_b = clear_pile(container->top_b);
		free(container);
		print_error();
		return (0);
	}

	container = split_pile_first(container);
	container = split_recusive(container);
	while (container->size_pile_b > 0)
	container = fusion_pile(container);
	container = updatel(container);
	container->top_a = clear_pile(container->top_a);
	container->top_b = clear_pile(container->top_b);
	free(container);
	return 0;
}
/*	
	ft_printf("\n---------------------------\n");
	ft_printf("pile a new =>");
	print_pile(container->top_a);
	ft_printf("\n---------------------------\n");
	ft_printf("pile b new =>");
	print_pile(container->top_b);
*/