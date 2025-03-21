/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:40:05 by aserbest          #+#    #+#             */
/*   Updated: 2025/03/21 16:41:52 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_stack	*create_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_stack	*stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return (NULL);
	if (!(*stack))
	{
		*stack = new;
		new->next = NULL;
		return (*stack);
	}
	new->next = *stack;
	*stack = new;
	return (*stack);
}

t_stack	*free_stack(t_stack *head)
{
	t_stack	*ptr;

	while (head)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
	return (NULL);
}

t_stack	*stack_a_init(char **arr, int len)
{
	t_stack	*head;
	int		num;

	len--;
	head = NULL;
	while (len >= 0)
	{
		num = ft_atoi(arr[len]);
		if (!stack_add_front(&head, create_node(num)))
			return (free_stack(head));
		len--;
	}
	return (head);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if (stack->tag == 0 && (!min || stack->data < min->data))
			min = stack;
		stack = stack->next;
	}
	return (min);
}
