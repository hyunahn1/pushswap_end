#include "push_swap.h"

int     search_num(int n, int *arr, int size)
{
        int             i;

        i = 0;
        while (size--)
        {
                if (arr[i] == n)
                        return (i + 1);
                i++;
        }
        return (0);
}

void    index_by_size(int *arr, t_stack **a)
{
        t_stack         *a_stack;
        t_stack         *aa;
        int                     size;

        size = ft_stack_size (*a);
        a_stack = *a;
        aa = a_stack;
        while (a_stack)
        {
                a_stack->data = search_num (a_stack->data, arr, size);
                a_stack = a_stack->next;
        }
        *a = aa;
}
