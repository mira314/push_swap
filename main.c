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

static t_container	*updatel(t_container *ct, t_stack a, t_stack b);
{
	ct->top_a = a;
	ct->top_b = b;
	ct->size_pile_a = ft_pile_size(a);
	ct->size_pile_b = ft_pile_size(b);
	return(ct);
}


int main(int argc, const char *argv[])
{	
	t_container *container;
	ft_printf("%d\n",argc);

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
	container->pile_a = container->top_a;
	//container->top_a = ft_swap_pile(&(container->pile_a));
	//(&(container->top_b));
	container->pile_b = container->top_b;
	//container->top_a = del_one_pile(container->top_a);
	//pile_a = container->top_a;
	
	//container =	ft_rotate_b(container);
	//three_element(container);
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
t_container less_six_element(container);
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
	}

}
/* teste 

	ft_swap_pile(&pile_a);
	ft_swap_pile(&pile_a);
	ft_swap_pile(&(container->pile_a));
ft_rev_rotate_pile(&(container->pile_a));
	//pile_a = del_one_pile(pile_a);
	//ft_rotate_pile(&pile_a);
*/