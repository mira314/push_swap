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

/*static t_container	*updatel(t_container *ct, t_stack a, t_stack b);
{
	ct->top_a = a;
	ct->top_b = b;
	ct->size_pile_a = ft_pile_size(a);
	ct->size_pile_b = ft_pile_size(b);
	return(ct);
}
*/


int main(int argc, char *argv[])
{	
	t_container *container;
	ft_printf("%d\n",argc);

	container = fill_container_one(argv[1]);
	if (!container)
	{
		free(container);
		return (0);
	}
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
	container =	swap_a(container);
	container =	push_b(container);
	container =	swap_ss(container);
	container =	swap_b(container);
	container =	swap_a(container);
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
void	two_element(t_container *container)
{
	if (container->pile_a->value > container->pile_a->next->value)
		container	= swap_a(container);
}

void	three_element(t_container *container)
{
	if (container->pile_a->value > container->pile_a->next->value)
	{
		if (container->pile_a->next->value <container->pile_a->next->next->value)
		{
			if (container->pile_a->value > container->pile_a->next->next->value)
				container = ft_rotate_a(container);
			else
				container = swap_a(container);
		}
		else
		{
			container = swap_a(container);
			container = reverse_rotate_a(container);
		}
	}
	else
	{
		if (container->pile_a->value > container->pile_a->next->next->value)
			container =  reverse_rotate_a(container);
		else
			container =  three_not_trie(container);
	}
}

void	three_not_trie(t_container *container)
{
	container =  ft_rotate_a(container);
	container = swap_a(container);
	container = reverse_rotate_a(container);
}