#include "push_swap.h"

void assign_tag_zero(t_stack **a)
{
    t_stack *temp;

    temp = *a;
    while (temp)
    {
        temp->tag = 0;
        temp = temp->next;
    }
}

void assign_tag(t_stack **a)
{
    unsigned long i;
    t_stack *min;

    assign_tag_zero(a);
    i = 1;
    while (1)
    {
        min = stack_min(*a);
        if (!min)
            break;
        min->tag = i;
        i++;
    }
}

void radix_sort_b(t_stack **a, t_stack **b, int bit)
{
    int size;
    int i;

    if (!b || !(*b))
        return;
    i = 0;
    size = stack_size(*b);
    while (i++ < size)
    {
        if (((*b)->tag >> bit) & 1)
            pa(a, b);
        else
            rb(b);
    }
}

int radix_sort(t_stack **a, t_stack **b)
{
    int i;
    int err;
    int shift;
    int size;

    shift = 0; // en düşük bit ile başla
    assign_tag(a);
    while (!is_sorted(*a))
    {
        i = 0;
        size = stack_size(*a);
        while (i++ < size)
        {
            if ((*a)->tag >> shift & 1) // o anki bit 1 ise yerinde kal
                err = ra(a);
            else
                err = pb(a, b); // 0 biti ise stack b'ye gönder
            if (!err)
                return (0);
        }
        //radix_sort_b(a, b, shift + 1);
        while ((*b))
            if (!pa(a, b)) // b içinde kalanları staack a'ya taşı
                return (0);
        shift++;
    }
    return (1);
}
