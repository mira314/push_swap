/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:08:51 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/07 14:03:31 by vrandria         ###   ########.fr       */
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
t_container	*updatel(t_container *ct);

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
t_container *fill_container_one(const char *str);
t_container	*initialiser(t_container *container);
t_container *fill_container_multi(int argc, const char *argv[]);

///****************check_erroc**********************/////
void	print_error(void);
int	ft_check_double(t_container *container);
int	si_atoiable(const char *str);
int	order_ok(t_container *container);


/*****************algo**************************/
void	three_element(t_container *container);
void	two_element(t_container *container);
void four_element(t_container *container);
void five_element(t_container *container);

///****************** algo3.c  ******************/
t_container *split_pile(t_container *container);
t_container *fusion_pile(t_container *container);
int	find_min(t_stack *pile);
int	find_max(t_stack *pile);
t_container *push_min_value(t_container *container);

t_container *fusion_pile_to_b(t_container *container);
/***************algo_utils***************************/
void six_element(t_container *container);
t_container *split_recusive(t_container *container);

///****************** find_value.c  ******************/
int	find_median_a(t_container *container, int median);
int	find_median_b(t_container *container, int median);
int	cost_go_to_this_element(t_stack *pile, int value);
int	find_below_median(t_stack *pile, int median);

#endif