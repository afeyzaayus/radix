#include "push_swap.h"

t_stack *operation_swap(t_stack **stack)
{
    t_stack *temp;

    if (!stack || !(*stack) || !((*stack)->next))
        return (NULL);
    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    *stack = temp;
    return (*stack);
}

int sa(t_stack **stack)
{
    if (operation_swap(stack))
    {
        write(1, "sa\n", 3);
        return (1);
    }
    return (0);
}