/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:40:58 by aserbest          #+#    #+#             */
/*   Updated: 2024/10/29 18:41:21 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		ft_lstclear(&new_node, del);
		return (NULL);
	}
	new_node->next = ft_lstmap(lst->next, f, del);
	return (new_node);
}

void * f(void* c)
{
	char *ptr= (char*)c;
	char *new = malloc(sizeof(c) + 1);

	int i =0;
	while (ptr[i])
	{
		new[i]=ptr[i];
		i++;
	}
	return new;
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
	t_list *node1=ft_lstnew(ft_strdup("abc"));

	t_list *p=ft_lstmap(node1, f, free);

	printf("%s ",(char *)p->content);
	return 0;
}

