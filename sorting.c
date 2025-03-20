#include "push_swap.h"

static int find_rotates(t_stack *stack)
{
    int i;
    int size;
    t_stack *min;
    t_stack *temp;

    i = 0;
    temp = stack;
    min = stack_min(temp);
    while (temp != min)
    {
        i++;
        temp = temp->next;
    }
    size = stack_size(stack);
    if (i > size / 2)
        i = -(size - i);
    return (i);
}

static void smart_rotate(t_stack **stack)
{
    int i;
    int rotate_count;
    int (*rotate_function) (t_stack**);

    rotate_count = find_rotates(*stack);
    if (rotate_count < 0)
    {
        rotate_function = &rra;
        rotate_count = -rotate_count;
    }
    else
        rotate_function = &ra;
    i = 0;
    while (i < rotate_count)
    {
        rotate_function(stack);
        i++;
    }
}

static void sort_three(t_stack **s)
{
    int num1 = (*s)->data;
    int num2 = (*s)->next->data;
    int num3 = (*s)->next->next->data;

    if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(s);
	else if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		sa(s);
		rra(s);
	}
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ra(s);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(s);
		ra(s);
	}
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rra(s);
}

int sort_small(t_stack **a, t_stack **b)
{
    int size;
    int i;

    i = 0;
    size = stack_size(*a);
    while (i < size - 3)
    {
        smart_rotate(a);
        if (is_sorted(*a))
            break;
        if (!pb(a, b))
            return (0);
        i++;
    }
    sort_three(a);
    while (*b)
    {
        if (!pa(a, b))
            return (0);
    }
    return (1);
}

int sort(t_stack **a)
{
    int value;
    t_stack *b;
    int size;

    b = (void*)0;
    size = stack_size(*a);
    if (size == 2)
        value = sa(a);
    else if (size <= 6)
    {
        value = sort_small(a, &b);
        free_stack(b);
    }
    else if (size > 6)
    {
        value = radix_sort(a, &b);
        free_stack(b);
    }
    return (value);
}
