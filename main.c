/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/27 11:10:04 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_container	*initialiser(t_container *container)
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
/*static t_container	*updatel(t_container *ct, t_stack a, t_stack b);
{
	ct->top_a = a;
	ct->top_b = b;
	ct->size_pile_a = ft_pile_size(a);
	ct->size_pile_b = ft_pile_size(b);
	return(ct);
}
*/
static t_container *test(void)
{
	t_container *container;
	container = malloc(sizeof(t_container));
	container = initialiser(container);
	container->top_a = insert_pile(container->top_a, 1);
	container->top_a = insert_pile(container->top_a, 2);
	container->top_a = insert_pile(container->top_a, 3);
	container->top_a = insert_pile(container->top_a, 4);
	container->top_a = insert_pile(container->top_a, 5);
	container->top_a = insert_pile(container->top_a, 6);
	container->top_a = insert_pile(container->top_a, 7);

	container->top_b = insert_pile(container->top_b, 1);
	container->top_b = insert_pile(container->top_b, 2);
	container->top_b = insert_pile(container->top_b, 3);
	container->top_b = insert_pile(container->top_b, 4);
	return (container);

}

//int main(int argc, const char *argv[])
int main(void)
{	
	t_container *container;
	container = test();

	ft_printf("pile a    => ");
	print_pile(container->top_a);
	//pile_a = del_one_pile(pile_a);
	//ft_rotate_pile(&pile_a);
	ft_printf("\n---------------------------\n");
	ft_printf("pile b    => ");
	print_pile(container->top_b);
	ft_printf("\n---------------------------\n");
//	print_pile(container->pile_a);
	container->pile_a = container->top_a;
	//container->top_a = ft_swap_pile(&(container->pile_a));
	//(&(container->top_b));
	container->pile_a = container->top_a;
	//container->top_a = del_one_pile(container->top_a);
	//pile_a = container->top_a;

	ft_rev_rotate_pile(&(container->pile_a));
	container->top_a = container->pile_a;
	ft_printf("\n---------------------------\n");
	ft_printf("pile a new =>");
	print_pile(container->top_a);
	ft_printf("\n---------------------------\n");
	ft_printf("pile b new =>");
	print_pile(container->top_b);

	printf("action fait est %d\n",container->hit);


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


*/