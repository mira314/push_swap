/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/07 17:04:25 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_container *split_pile_first(t_container *container)
{
	int	median;
	int median3;

	container = updatel(container);
	median = find_median_a(container, 2, 1);
	median3 = find_median_a(container, 4, 1);
	while (find_below_median(container->pile_a, median) != 0)
	{
		if (container->pile_a->value < median)
			{
				container = push_b(container);
				container = updatel(container);
				if (container->pile_b->value < median3)
				{
					if (container->pile_a->value > median)
					{
						container = ft_rotate_r(container);
					}
					else
					container = ft_rotate_b(container);
				}
			}
		else
			container = ft_rotate_a(container);
		container = updatel(container);
	}
	return (container);
}


t_container *sort_a_remain(t_container *container)
{
	container = reverse_rotate_a(container);
	container = push_b(container);
	container = reverse_rotate_a(container);
	container = updatel(container);

	while (container->size_pile_b < 24)
	{
		if (container->pile_b < bottom_pile(container->pile_b))
		{
			container = reverse_rotate_rr(container);
		}
		else
			container = reverse_rotate_a(container);
		container = push_b(container);
		container = updatel(container);
	}
	return (container);
}

t_container *split_pile_b(t_container *container)
{
	int	median;
	int size;
	int move;

	move = 0;
	container = updatel(container);
	size = container->size_pile_b;
	median = find_median_b(container, 4);
	while (size-- && find_under_median(container->pile_a, median) != 0)
	{
		if (container->pile_b->value > median)
		{
			container = push_a(container);
			move++;
		}
		else
			container = ft_rotate_b(container);
		container = updatel(container);
	}
	while (move--)
	{
		//container = push_min_value(container);
	}

	return (container);
}

t_container *split_pile_bb(t_container *container)
{
	int	median;
	int size;

	container = updatel(container);
	size = container->size_pile_b;
	median = find_median_b(container, 2);
	while (size--)
	{
		if (container->pile_b->value < median)
		{
			container = push_a(container);
			container = ft_rotate_a(container);
		}
		else
			container = ft_rotate_b(container);
		container = updatel(container);
	}
	return (container);
}

int main(int argc, const char *argv[])
{	
	t_container *container;
//	int test;

//	test = 60;
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
/*

//ft_printf("double est %d\n",ft_check_double(container));
	ft_printf("pile a    => ");
	print_pile(container->top_a);
	ft_printf("\n---------------------------\n");
	ft_printf("pile b    => ");
	print_pile(container->top_b);
	ft_printf("\n---------------------------\n");

*/
//	print_pile(container->pile_a);
	//container->top_a = ft_swap_pile(&(container->pile_a));
	//(&(container->top_b));
	//container->top_a = del_one_pile(container->top_a);
	//pile_a = container->top_a;
	container = split_pile_first(container);

	container = split_recusive(container);

	while (container->size_pile_b > 0)
	{
	container = fusion_pile(container);
	}

	/*
	container = split_pile_bb(container);
	while (container->size_pile_b > 0)
	{
	container = fusion_pile(container);
	}
	container = sort_a_remain(container);
*/


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
	
//	ft_printf("le median est %d \n",find_median(container));
//	printf("la taille de la pile est %d\n",ft_pile_size(pile_a));
	container->top_a = clear_pile(container->top_a);
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