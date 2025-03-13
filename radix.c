#include "push_swap.h"


int radix_sort(t_stack **a, t_stack **b)
{
    int i;
    int err;
    int shift;
    int size;

    shift = 0; // en düşük bit ile başla
    while (!is_sorted(*a))
    {
        i = 0;
        size = stack_size(*a);
        while (i++ < size)
        {
            if ((*a)->data >> shift & 1) // o anki bit 1 ise yerinde kal
                err = ra(a);
            else
                err = pb(a, b); // 0 biti ise stack b'ye gönder
            if (!err)
                return (0);
        }
        while ((*b))
            if (!pa(a, b)) // b içinde kalanları staack a'ya taşı
                return (0);
        shift++;
    }
    return (1);


}