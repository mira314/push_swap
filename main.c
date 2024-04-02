/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/02 08:56:28 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//t_container	*ft_rotate_b(t_container *container) mila soloina

int main(int argc, const char *argv[])
{	
	t_container *container;
//	int test;

//	test = 60;
	if (argc == 2)
		container = fill_container_one(argv[1]);
	else if (argc > 2)
		container = fill_container_multi(argc, argv);
	else
	{
		print_error();
		return (0);
	}
/*	if (!container || ft_check_double(container->top_a))
	{
		free(container);
		return (0);
	}
*/
	container = updatel(container);
	if (container == NULL)
	{
		print_error();
		return (0);
	}

ft_printf("double est %d\n",ft_check_double(container));
	ft_printf("pile a    => ");
	print_pile(container->top_a);
	ft_printf("\n---------------------------\n");
	ft_printf("pile b    => ");
	print_pile(container->top_b);
	ft_printf("\n---------------------------\n");
//	print_pile(container->pile_a);
	//container->top_a = ft_swap_pile(&(container->pile_a));
	//(&(container->top_b));
	//container->top_a = del_one_pile(container->top_a);
	//pile_a = container->top_a;
	//container = updatel(container);
	while (1)
	{
	container = updatel(container);
	container = split_pile(container);
	container = split_pile(container);
	container = split_pile(container);
	container = fusion_pile(container);
	if (order_ok(container) == 1)
		break;
	}
	container = updatel(container);
	//ft_printf("%d check\n", order_ok(container));
	//three_element(container);
	//container = split_pile(container);
	//container = split_pile(container);
	//container = split_pile(container);
	//container = fusion_pile(container);
	//container = fusion_pile(container);
	//container = ft_rotate_b(container);
	//container =	ft_rotate_b(container);
	//three_element(container);
	//container = updatel(container);
	//container->pile_a = container->top_a;
	//container = push_b(container);
	//container =	swap_ss(container);
	//container =	swap_a(container);
	//container =	push_b(container);
	//container =	reverse_rotate_a(container);
	//container =	push_b(container);
	//container =	swap_ss(container);
	ft_printf("\n---------------------------\n");
	ft_printf("pile a new =>");
	print_pile(container->top_a);
	ft_printf("\n---------------------------\n");
	ft_printf("pile b new =>");
	print_pile(container->top_b);


	ft_printf("\naction fait est %d\n",container->hit);


//	printf("la taille de la pile est %d\n",ft_pile_size(pile_a));
	container->pile_a = clear_pile(container->top_a);
	container->top_b = clear_pile(container->top_b);
	free(container);
	return 0;
}

/* teste 

	ft_swap_pile(&pile_a);
	ft_swap_pile(&pile_a);
	ft_swap_pile(&(container->pile_a));
ft_rev_rotate_pile(&(container->pile_a));
	//pile_a = del_one_pile(pile_a);
	//ft_rotate_pile(&pile_a);
*/