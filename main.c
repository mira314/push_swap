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
///fichier h
///print pile
/// indexation
int	*index_sort(int *tab, int size)
{
	int	tmp;
	int	i;
	
	while (size--)
	{
		i = 0;
		while (i < size)
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

t_container *target_index(t_container *container, int *tab)
{
	t_stack *tmp;
	int	i;

	i = 0;
	container = updatel(container);
	tmp = container->top_a;
	while (tmp != NULL)
	{
		while (1)
		{
		if (tab[i] == tmp->value)
			{
				tmp->i = i;
				ft_printf("tab[%d] = %d  tmp->value= %d\n",i, tab[i], tmp->value);
				break ;
			}
		else
			i++;
		}
		tmp = tmp->next;
		i = 0;
	}
	return (container);
}

t_container *sorting_index(t_container *container)
{
	t_stack	*tmp;
	int		*tab;
	int		size;
	int		i;

	i = 0;
	container = updatel(container);
	size = ft_pile_size(container->top_a);
	tmp = container->pile_a;
	tab = malloc(sizeof(int) * size + 1);
	if (!tab)
		return (0);
	while (tmp != NULL)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	tab = index_sort(tab, size);
	ft_printf("taybeeb %d\n",tab[3]);
	container = target_index(container, tab);
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

	container = sorting_index(container);
	if (order_ok(container))
		return (0);
	if (container->size_pile_a < 6)
		container = split_recusive(container);
	else
	{
		container = split_pile_first(container);
		container = split_recusive(container);
		while (container->size_pile_b > 0)
		container = fusion_pile(container);
	}
	ft_printf("\n---------------------------\n");
	ft_printf("pile a new =>");
	print_pile(container->top_a);
	ft_printf("\n---------------------------\n");
	ft_printf("pile b new =>");
	print_pile(container->top_b);

	container = updatel(container);
	container->top_a = clear_pile(container->top_a);
	container->top_b = clear_pile(container->top_b);
	free(container);
	return 0;
}
