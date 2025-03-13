#include "push_swap.h"

static int	is_valid_number(char *str)
{
    if (*str == '-' || *str =='+')
        str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

int has_same_number(char **str)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (!ft_strncmp(str[i], str[j], ft_strlen(str[i])))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_arguments(int argc, char **argv)
{
    char **arr;
    int i;

    i = 1;
    if (argc == 1)
        return (0);
    while (argv[i])
    {
        if (!is_valid_number(argv[i]))
            return (0);
    }
    if (has_same_number(argv))
        return (0);
    return (1);
}