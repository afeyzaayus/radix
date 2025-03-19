#include "libft/libft.h"
#include "unistd.h"


typedef struct s_stack
{
	int				data;
	unsigned long	tag;
	struct s_stack	*next;
} t_stack;


int		check_arguments(int argc, char **argv);
int		free_arr_2d(char **arr);
char	**parse_args(char **argv);
t_stack	*stack_a_init(char **arr, int len);
int		ft_strlen_2d(char **arr);
int		is_sorted(t_stack *stack);
t_stack	*free_stack(t_stack *head);
int		stack_size(t_stack *stack);
int		sa(t_stack **stack);
t_stack	*stack_min(t_stack *stack);
t_stack	*stack_add_front(t_stack **stack, t_stack *new);
int		rra(t_stack **stack_a);
int		ra(t_stack **stack_a);
//int		rb(t_stack **stack_b);
int		pb(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
int		sort(t_stack **head_a);
int		radix_sort(t_stack **a, t_stack **b);
long	ft_atol(const char *str);
//void assign_tag_zero(t_stack **a);
int has_same_number(int argc, char **str);
