/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:08:51 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/25 09:42:44 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
} t_stack;

//********************** utils_pile.c************************//

t_stack	*new_stack(void);
int	is_empty_stack(t_stack *pile);
t_stack	*insert_pile(t_stack *pile, int value);
t_stack	*clear_pile(t_stack *pile);
t_stack	*del_one_pile(t_stack *pile);

//*********************** utils_pile.c***********************//
void	print_pile();


#endif
