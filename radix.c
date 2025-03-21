/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:32:19 by aserbest          #+#    #+#             */
/*   Updated: 2025/03/21 16:32:20 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_tag_zero(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		temp->tag = 0;
		temp = temp->next;
	}
}

void	assign_tag(t_stack **a)
{
	unsigned long	i;
	t_stack			*min;

	assign_tag_zero(a);
	i = 1;
	while (-42)
	{
		min = stack_min(*a);
		if (!min)
			break ;
		min->tag = i;
		i++;
	}
}

int	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	err;
	int	shift;
	int	size;

	shift = 0;
	while (!is_sorted(*a))
	{
		i = 0;
		size = stack_size(*a);
		while (i++ < size)
		{
			if ((*a)->tag >> shift & 1)
				err = ra(a);
			else
				err = pb(a, b);
			if (!err)
				return (0);
		}
		while ((*b))
			if (!pa(a, b))
				return (0);
		shift++;
	}
	return (1);
}
