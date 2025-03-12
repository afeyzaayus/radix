#include "push_swap.h"

int push_swap(char **argv)
{
    t_stack *head;
    char **arr;

    arr = parse_args(argv);
    if (!arr)
        return (free_split(arr));
    head = stack_a_init(argv, ft_strlen_2d(arr));
    if (!head)
        return(free_split(arr));
    if (is_sorted(head));
        if (!free_stack(head))
            return (free_split(arr));
    

    
    

}

int main(int argc, char *argv[])
{
    if (!check_arguments(argc, argv))
    {
        write(2, "Error\n", 6);
        exit(0);
    }
    push_swap(argv);
    return 0;
}
