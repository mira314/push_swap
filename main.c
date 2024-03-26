/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/26 07:40:05 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//int main(int argc, const char *argv[])
int main(void)
{
	t_stack *pile_a;
	pile_a = new_stack();

	pile_a = insert_pile(pile_a, 1);
	pile_a = insert_pile(pile_a, 2);
	pile_a = insert_pile(pile_a, 3);
	pile_a = insert_pile(pile_a, 4);
	pile_a = insert_pile(pile_a, 5);
	pile_a = insert_pile(pile_a, -5);

	print_pile(pile_a);
	//pile_a = del_one_pile(pile_a);
	ft_swap_pile(&pile_a);
	
	ft_printf("---------------------------\n");
	print_pile(pile_a);

	printf("la taille de la pile est %d\n",ft_pile_size(pile_a));
	pile_a = clear_pile(pile_a);
	return 0;
}

