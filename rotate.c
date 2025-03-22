/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:33:13 by aserbest          #+#    #+#             */
/*   Updated: 2025/03/22 13:03:47 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

t_stack	*rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*ptr;

	if (!(*stack) || !(*stack)->next)
		return (NULL);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = temp;
	return (*stack);
}

t_stack	*reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*end;

	if (!(*stack) || !(*stack)->next)
		return (NULL);
	temp = *stack;
	while (temp->next)
	{
		if (!(temp->next->next))
			end = temp;
		temp = temp->next;
	}
	end->next = NULL;
	temp->next = (*stack);
	stack_add_front(stack, temp);
	return (*stack);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a))
	{
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}

int	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
	{
		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}
