/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/12 09:28:25 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

		ft_printf("\n---------------------------\n");
	ft_printf("pile a new =>");
	print_pile(container->top_a);
	ft_printf("\n---------------------------\n");
	ft_printf("pile b new =>");
	print_pile(container->top_b);

	ft_printf("cout %d\n",container->hit);
	
	container->top_a = clear_pile(container->top_a);
	container->top_b = clear_pile(container->top_b);
	free(container);
	return 0;
}
