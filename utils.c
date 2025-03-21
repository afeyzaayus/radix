/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:43:20 by aserbest          #+#    #+#             */
/*   Updated: 2025/03/21 16:45:17 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	free_arr_2d(char **arr)
{
	int	i;

	if (!arr || !(*arr))
		return (0);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

int	ft_strlen_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**ft_strjoin_2d(char **arr, char **split)
{
	char	**ptr;
	int		i;
	int		j;

	i = ft_strlen_2d(arr);
	j = ft_strlen_2d(split);
	ptr = ft_calloc(i + j + 1, sizeof(char *));
	if (!ptr)
	{
		free_arr_2d(arr);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (arr[i])
		ptr[j++] = arr[i++];
	i = 0;
	while (split[i])
		ptr[j++] = split[i++];
	ptr[j] = NULL;
	free(arr);
	return (ptr);
}

char	**parse_args(char **argv)
{
	char	**arr;
	char	**split;
	int		i;

	arr = ft_calloc(1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			break ;
		arr = ft_strjoin_2d(arr, split);
		if (!arr)
			break ;
		i++;
		free(split);
	}
	if (!split || !arr)
	{
		free_arr_2d(split);
		return (NULL);
	}
	return (arr);
}
