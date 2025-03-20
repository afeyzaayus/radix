#include "push_swap.h"
#include "unistd.h"


static int push_swap(char **argv)
{
    t_stack *head;
    char **arr;

    arr = parse_args(argv);
    if (!arr)
        return (free_arr_2d(arr));
    head = stack_a_init(arr, ft_strlen_2d(arr));
    free_arr_2d(arr);
    if (!head)
        return(0);
    if (is_sorted(head))
        if (!free_stack(head))
            return (0);
    sort(&head);
    free_stack(head);
    return (1);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        return (0);
    if (!check_arguments(argc, argv))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if(!push_swap(argv))
        return (1);
    return 0;
}
