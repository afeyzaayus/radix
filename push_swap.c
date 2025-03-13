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
     printf("\n");
}

void apply_command(t_stack **a, t_stack **b, char *cmd)
{
    if (!ft_strncmp(cmd, "sa\n", 3))
        sa(a);
    else if (!ft_strncmp(cmd, "sb\n", 3))
        sb(b);
    else if (!ft_strncmp(cmd, "ss\n", 3))
        ss(a, b);
    else if (!ft_strncmp(cmd, "pa\n", 3))
        pa(a, b);
    else if (!ft_strncmp(cmd, "pb\n", 3))
        pb(a,b);
    else if (!ft_strncmp(cmd, "ra\n", 3))
        ra(a);
    else if (!ft_strncmp(cmd, "rb\n", 3))
        rb(b);
    else if (!ft_strncmp(cmd, "rr\n", 3))
        rr(a, b);
    else if (!ft_strncmp(cmd, "rra\n", 4))
        rra(a);
    else if (!ft_strncmp(cmd, "rrb\n", 4))
        rrb(b);
    else if (!ft_strncmp(cmd, "rrr\n", 4))
        rrr(a, b);
    else
        write(2, "Error\n", 6);
}


void get_rule(t_stack **a, int fd)
{
    t_stack *b;
    char *commad;

    b = NULL;
    int count = 0;
    while(1)
    {
        printf("count: %d\n",count);
        printf("A:   ");
        print_list(a);
        printf("B:   ");
        print_list(&b);
        count++;
        commad = get_next_line(fd);
        if (!commad)
            break;
        apply_command(a, &b, commad);
        free(commad);
    }
}

int push_swap(char **argv)
{
    t_stack *head;
    char **arr;

    arr = parse_args(argv);
    if (!arr)
        return (free_split(arr));
    head = stack_a_init(arr, ft_strlen_2d(arr));
    free_split(arr);
    if (!head)
        return(0);
    if (is_sorted(head))
        if (!free_stack(head))
            return (0);
    int fd = 0;
    get_rule(&head, fd);
    free_stack(head);
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
