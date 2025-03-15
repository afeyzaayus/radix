#include "push_swap.h"
#include <stdio.h>

void print_list(t_stack **a)
{
    t_stack *temp;

    temp = *a;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

int push_swap(int argc, char **argv)
{
    t_stack *head;
    char **arr;

    arr = parse_args(argc, argv);
    if (!arr)
    return (free_split(arr));
    head = stack_a_init(arr, ft_strlen_2d(arr));
    free_split(arr);
    if (!head)
    return(0);
    if (is_sorted(head))
        if (!free_stack(head))
            return (0);
    sort(&head);
    print_list(&head);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        return (0);
    if (!check_arguments(argc, argv))
    {
        write(2, "Error\n", 6);
        exit(0);
    }
    push_swap(argc, argv);
    return 0;
}
