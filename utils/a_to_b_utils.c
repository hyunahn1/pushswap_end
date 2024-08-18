#include "push_swap.h"

int     check_last_three(t_stack *a, int size)
{
        int             compare;

        compare = size - 2;
        while (a)
        {
                if (a->data < compare)
                        return (0);
                a = a->next;
        }
        return (1);
}
