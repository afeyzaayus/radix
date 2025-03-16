#include "push_swap.h"

t_stack *push(t_stack **src, t_stack **dest)
{
    t_stack *temp;

    if (!(*src))
        return (NULL);
    temp = (*src);
    *src = (*src)->next;
    return (stack_add_front(dest, temp));
}

int pb(t_stack **a, t_stack **b)
{
    if (push(a, b))
    {
        write(1, "pb\n", 3);
        return (1);
    }
    return (0);
}

int pa(t_stack **a, t_stack **b)
{
    if (push(b, a))
    {
        write(1, "pa\n", 3);
        return (1);
    }
    return (0);
}
