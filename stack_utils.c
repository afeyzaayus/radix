#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    while (stack->next)
    {
        if ((stack->data > stack->next->data))
            return (0);
        stack = stack->next;
    }
    return (1);
}

int stack_size(t_stack *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}
