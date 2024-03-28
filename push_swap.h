/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:08:51 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/28 10:37:40 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
} t_stack;

typedef struct s_container
{	void *top_a;
	void *top_b;
	int	size_pile_a;
	int	size_pile_b;
	int	hit;
	struct s_stack *pile_a;
	struct s_stack *pile_b;
	
}t_container;

//********************** utils_pile.c************************//

t_stack	*new_stack(void);
int	is_empty_stack(t_stack *pile);
t_stack	*insert_pile(t_stack *pile, int value);
t_stack	*clear_pile(t_stack *pile);
void	*del_one_pile(t_stack *pile);

//*********************** utils_pile.c***********************//
void	print_pile(t_stack *pile_a);
t_stack	*bottom_pile(t_stack *pile);
int	ft_pile_size(t_stack *pile);

#endif

/**********************ft_swap.c**************************/
void	ft_swap_pile(t_stack **stack);
t_container	*swap_a(t_container *container);
t_container	*swap_b(t_container *container);
t_container	*swap_ss(t_container *container);

/**********************ft_rotate.c***********************/
void	ft_rotate_pile(t_stack **pile);
t_container	*ft_rotate_a(t_container *container);
t_container	*ft_rotate_b(t_container *container);
t_container	*ft_rotate_r(t_container *container);

/*********************push.c*****************************/
t_container	*push_b(t_container *container);
t_container	*push_a(t_container *container);

/***************revers *********************/
void	ft_rev_rotate_pile(t_stack **pile);
t_container *reverse_rotate_a(t_container *container);
t_container *reverse_rotate_b(t_container *container);
t_container *reverse_rotate_rr(t_container *container);

///****************ft_input**********************/////
int	*ft_insert_one(char *str);