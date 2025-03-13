#include "push_swap.h"

t_stack *rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *ptr;

    if (!(*stack) || !(*stack)->next)
        return (NULL);
    temp = *stack;
    *stack = (*stack)->next;
    temp->next = NULL;
    ptr = *stack;
    while (ptr)
    {
        if (!ptr->next)
            break;
        ptr = ptr->next;
    }
    ptr->next = temp;
    return (*stack);
    

}

t_stack *reverse_rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *end;

    if (!(*stack) || !(*stack)->next)
        return (NULL);
    temp = *stack;
    while (temp)
    {
        if (!temp->next)
            break;
        if (temp->next && !(temp->next->next))
            end = temp;
        temp = temp->next;        
    }
    end->next = NULL;
    temp->next = (*stack);
    stack_add_front(stack, temp); //gerekli mi?
    return (*stack);
}

int rra(t_stack **stack_a)
{
    if (reverse_rotate(stack_a))
    {
        write(1, "rra\n", 4);
        return (1);
    }
    return (0);
}

int ra(t_stack **stack_a)
{
    if (rotate(stack_a))
    {
        write(1, "ra\n", 3);
        return (1);
    }
    return (0);
}

int rrb(t_stack **stack_b)
{
    if (reverse_rotate(stack_b))
    {
        write(1, "rrb\n", 4);
        return (1);
    }
    return (0);
}

int rb(t_stack **stack_b)
{
    if (rotate(stack_b))
    {
        write(1, "rb\n", 3);
        return (1);
    }
    return (0);
}