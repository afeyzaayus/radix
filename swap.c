/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:41:58 by aserbest          #+#    #+#             */
/*   Updated: 2025/03/21 16:42:39 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

t_stack	*operation_swap(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return (NULL);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	return (*stack);
}

int	sa(t_stack **stack)
{
	if (operation_swap(stack))
	{
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}
