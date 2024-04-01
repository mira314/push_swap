/* ************************************************************************** */
/* a                                                                           */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/28 11:00:22 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//t_container	*ft_rotate_b(t_container *container) mila soloina
static t_container	*updatel(t_container *ct)
{
	ct->pile_a = ct->top_a;
	ct->pile_b = ct->top_b;
	ct->size_pile_a = ft_pile_size(ct->pile_a);
	ct->size_pile_b = ft_pile_size(ct->pile_b);
	return(ct);
}
t_container *split_pile(t_container *container)
{

	t_stack *lst_b;

	lst_b = 0;
	int size;

	size = (container->size_pile_a / 2);
	if ((container->pile_a == NULL) || (container->pile_a->next == NULL))
		return (container);
	else
	{
		while (size--)
		{
			three_element(container);
			container = push_b(container);
			container = updatel(container);
			lst_b = bottom_pile(container->pile_b);
			if (lst_b->value > container->pile_b->value)
				container = ft_rotate_b(container);
			container = updatel(container);
		}
	}
		return (container);
}

t_container *fusion_pile(t_container *container)
{
	t_stack *lst_a;

	lst_a  = 0;
	while (container->pile_b != NULL)
	{
		lst_a = bottom_pile(container->pile_a);
		container = push_a(container);
		container = updatel(container);
		if (lst_a->value > container->pile_a->value)
		{
			container = ft_rotate_a(container);
		}
		container = updatel(container);
		//three_element(container);
		container = updatel(container);
	}
	return (container);
}

int main(int argc, const char *argv[])
{	
	t_container *container;
	ft_printf("%d\n",argc);
	//int test;

	//test = 1;
	container = fill_container_one(argv[1]);
/*	if (!container || ft_check_double(container->top_a))
	{
		free(container);
		return (0);
	}
*/
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
//	while (test--)
//	{
//	container = updatel(container);
//	container = split_pile(container);
//	container = split_pile(container);
//	container = split_pile(container);
//	container = split_pile(container);
//	container = fusion_pile(container);
//	}
	container = updatel(container);
	three_element(container);
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

/*** tsy mbola vita
t_container *less_six_element(container)
{
	int	min_value;

	container = updatel(container, container->pile_a, container->top_b);

	if (container->size_pile_a == 2)
	two_element(container);
	else if (container->size_pile_a == 3)
	three_element(container);
	else
	{
		while (container->pile_a->next->next = NULL)
			container = push_b(container);
		three_element(container);
		container = updatel(container, container->pile_a, container->top_b);

		while ()
	}

}
*/
/* teste 

	ft_swap_pile(&pile_a);
	ft_swap_pile(&pile_a);
	ft_swap_pile(&(container->pile_a));
ft_rev_rotate_pile(&(container->pile_a));
	//pile_a = del_one_pile(pile_a);
	//ft_rotate_pile(&pile_a);
*/