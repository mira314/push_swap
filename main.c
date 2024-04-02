/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/02 11:06:46 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min(t_container *container)
{
	int min;
	t_stack *temp;
	int size;

	min = 2147483647;
	temp = container->pile_a;
	container = updatel(container);
	size = container->size_pile_a;
	while (size--)
	{
		if (temp->value < min)
				min = temp->value;
		temp = temp->next;
	}
	return (min);
}
t_container *sort_by_select(t_container *container)
{
	t_stack *temp;

	int min;

	min = find_min(container);
	temp = container->pile_a;
	while (temp != NULL)
	{
		if (temp->value == min )
			{
				container = push_b(container);
				break;
			}
		temp = temp->next;
		container = ft_rotate_a(container);
	}
	container = updatel(container);
	return (container);
}

int main(int argc, const char *argv[])
{	
	t_container *container;
	int test;

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

	if (container == 0)
	{
		print_error();
		return (0);
	}
/*
	if (ft_check_double(container) == 1)
	{
		print_error();
		return (0);
	}
*/
//ft_printf("double est %d\n",ft_check_double(container));
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
	
	
	container = updatel(container);
	test = container->size_pile_a;
	while (test > 3)
	{
		container = sort_by_select(container);
		test--;
	}
	three_element(container);
	while (container->pile_b !=NULL)
	{
		container = push_a(container);
	}
	//printf("%s valeu est %d\n","eto----------------------", container->pile_a->value);
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