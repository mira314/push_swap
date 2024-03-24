/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/24 17:58:23 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//int main(int argc, const char *argv[])
int main(void)
{
	t_stack *pile_a;
	pile_a = new_stack();

	pile_a = insert_pile(pile_a, 42);
	pile_a = insert_pile(pile_a, 24);
	pile_a = insert_pile(pile_a, 43);
	pile_a = insert_pile(pile_a, 44);
	//printf("%d\n",pile_a->value);
	//ft_printf("is vide ->%d   \n",is_empty_stack(pile_a));

	pile_a = clear_pile(pile_a);
	//ft_printf("is vide 2 ->%d   \n",is_empty_stack(pile_a));
	ft_putstr_fd("ok\n",1);
	ft_putchar_fd('o',1);
	return 0;

}
