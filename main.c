/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:50:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/21 09:45:25 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "push_swap.h"

int main(int argc, const char *argv[])
{
t_pile	*pile_a;
t_pile	*pile_b;
int	i;
 
i = 0;
pile_a = (t_pile *)malloc(sizeof(t_pile));
pile_a->size_pile = argc - 1;
pile_a->range = (int *)malloc(sizeof(int) * pile_a->size_pile + 1);
while(i < pile_a->size_pile)
{
	pile_a->range[i] = ft_atoi(argv[i + 1]);
	i++;
}
i = 0;
while(i < pile_a->size_pile )
{
	printf("%d \n",pile_a->range[i]);
	i++;
}
	return 0;
}