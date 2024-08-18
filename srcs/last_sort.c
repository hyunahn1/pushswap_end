#include "push_swap.h"

void    last_sort(t_stack **a)
{
        int                     size;
        int                     idx;
        int                     i;
        t_stack         *temp;

        temp = *a;
        idx = 0;
        size = ft_stack_size(*a);
        while (temp && temp->data != 1)
        {
                idx++;
                temp = temp->next;
        }
        i = -1;
        if (idx > size / 2)
                while (size - idx > ++i)
                        rra (a);
        else
                while (idx > ++i)
                        ra (a);
}
