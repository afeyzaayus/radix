#include "push_swap.h"

int free_split(char **split)
{
    int i;

    if (!split && !(*split))
        return (0);
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
    return (0);
}

int ft_strlen_2d(char **arr)
{
    int i;
    
    i = 0;
    while (arr[i])
        i++;
    return (i);
}

char **ft_strjoin_2d(char **arr, char **split)
{
    char **ptr;
    int i;
    int j;

    // NULL check?
    i = ft_strlen_2d(arr);
    j = ft_strlen_2d(split);
    ptr = ft_calloc(i + j + 1, sizeof(char *));
    if (!ptr)
        return (NULL);
    i = 0;
    j = 0;
    while (arr[i])
        ptr[j++] = arr[i++];
    i = 0;
    while (split[i])
        ptr[j++] = split[i++];
    ptr[j] = NULL;
    return ptr;
}

char **parse_args(char **argv)
{
    char **arr;
    char **split;
    int i;

    arr = ft_calloc(1, sizeof(char *));
    if (!arr)
        return NULL;
    i = 1;
    while (argv[i])
    {
        split = ft_split(argv[i], ' ');
        if (!split)
            break;
        arr = ft_strjoin_2d(arr, split);
        if (!arr)
            break;
        i++;
    }
    if (!split || !arr)
    {
        free_split(arr); // double free?
        return (NULL);
    }
    return (arr);

}


static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	int	i;
	long	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
