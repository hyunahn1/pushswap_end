#include "push_swap.h"

long long int   ft_atoi(const char *nptr)
{
        int                                                     i;
	int                                                     sign;
	long long int                           num;
        unsigned char                           *arr;

        arr = (unsigned char *)nptr;
        i = 0;
        num = 0;
        sign = 1;
        while ((arr[i] >= 9 && arr[i] <= 13) || arr[i] == 32)
                i++;
        if (arr[i] == '+' || arr[i] == '-')
        {
                if (arr[i] == '-')
                        sign *= -1;
                i++;
        }
        while (arr[i] >= '0' && arr[i] <= '9')
        {
                num = num * 10 + arr[i] - '0';
                i++;
        }
        return (sign * num);
}

int     ft_empty(char *arr)
{
        int             i;

        i = 0;
        while (arr[i])
        {
                if (arr[i] == ' ')
                {
                        while (arr[i] == ' ')
                                i++;
                        if (arr[i] >= '0' && arr[i] <= '9')
                                return (0);
                        if (!arr[i])
                                ft_error(1);
                }
                i++;
        }
        return (0);
}

int     ft_minus(char *arr)
{
        int             i;

        i = 0;
        while (arr[i])
        {
                if (arr[i] == '-' && ((arr[i + 1] == '-') || \
                !(arr[i + 1] >= '0' && arr[i + 1] <= '9')))
                {
                        ft_printf ("Error\n");
                        return (1);
                }
                if (arr[i] >= '0' && arr[i] <= '9')
                {
                        if (arr[i + 1] == '-')
                        {
                                ft_printf("Error\n");
                                return (1);
                        }
                }
                i++;
        }
        return (0);
}

t_stack	*play_parsing(char *arr, t_stack *stack_a)
{
	if (arr && !*arr)
		ft_printf("ERROR\n");
	while (*arr)
	{
		while (arr && *arr == ' ')
			arr++;
		check_arr_overflow(arr, stack_a);
		if ((*arr == '-' && *(arr + 1) >= '0' && *(arr + 1) <= '9') || \
				(*arr >= '0' && *arr <= '9'))
			stack_a = make_stack (ft_atoi(arr), stack_a);
		while (*arr == '-' || (*arr >= '0' && *arr <= '9'))
			arr++;
		while (*arr && !(*arr >= '0' && *arr <= '9') && *arr != '-')
		{
			if (!(*arr == ' '))
				ft_printf("Error\n");
			if (!(*arr == ' '))
				clear_nodes (stack_a);
			if (!(*arr == ' '))
                                return (0);
			arr++;
		}
	}
	return (stack_a);
}

t_stack	*ft_parsing(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 1;
	while (argc > i)

	{

		if (ft_empty(argv[i]))
			ft_error(1);
		if (ft_minus(argv[i]))
			ft_error(1);
		i++;
	}
	i = 1;
	while (argc > i)
	{
		stack_a = play_parsing(argv[i++], stack_a);
		if (!stack_a)
			return (0);
	}
	return (stack_a);
}
