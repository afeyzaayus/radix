#include "push_swap.h"
#include "libft/libft.h"


static int	is_valid_number(char *str)
{
	long num;
	int i;

	i = 0;
	if (str[i] == '-' || str[i] =='+')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (0);
	}
	while (str[i] == '0')
		i++;
	if (ft_strlen(&str[i]) > 11)
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int has_same_number(int argc, char **str)
{
	int i;
	int j;

	if (argc == 2)
		i = 0;
	else 
		i = 1;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int check_args(int argc, char **argv)
{
	int i;

	if (argc == 2)
		i = 0;
	else 
		i = 1;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	if (has_same_number(argc, argv))
		return (0);
	return (1);
}

int check_arguments(int argc, char **argv)
{
	char **split;
	int i;

	if (argc == 2)
	{
		i = 0;
		split = ft_split(argv[1], ' ');
		if (!split)
			return (0);
		i = check_args(argc, split);
		free_arr_2d(split);
		return(i);
	}
	else if (argc > 2)
		return (check_args(argc, argv));
	return (1);
}

