#include "push_swap.h"

void two_element(t_container *container)
{
    if (container->pile_a->value > container->pile_a->next->value)
        container = swap_a(container);
}

void three_element(t_container *container)
{
    t_node *a = container->pile_a;
    
    if (a->value > a->next->value && a->next->value < a->next->next->value)
        container = ft_rotate_a(container);
    else if (a->value > a->next->value && a->next->value > a->next->next->value)
    {
        container = swap_a(container);
        container = reverse_rotate_a(container);
    }
    else if (a->value > a->next->value && a->next->value < a->next->next->value)
        container = swap_a(container);
    else if (a->value < a->next->value && a->next->value > a->next->next->value)
        container = reverse_rotate_a(container);
    else if (a->value < a->next->value && a->next->value > a->next->next->value)
        container = three_not_order(container);
}

t_container *three_not_order(t_container *container)
{
    container->top_a = container->pile_a;
    container = ft_rotate_a(container);
    container = swap_a(container);
    container = reverse_rotate_a(container);
    return (container);
}
