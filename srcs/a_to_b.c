#include "push_swap.h"

int     check_to_pivot(t_stack **a, int pivot1)
{
        t_stack         *a_stack;

        a_stack = *a;
        while (a_stack)
        {
                if (a_stack->data <= pivot1)
                        return (1);
                a_stack = a_stack->next;
        }
        return (0);
}

void    move_cause_pivot(t_stack **a, t_stack **b, int count, int size)
{
        int             pivot1;
        int             pivot2;

        pivot1 = size / 3;
        pivot2 = 2 * size / 3;
        while (count < pivot2 && (*a))
        {
                if ((*a)->data > pivot1 && (*a)->data <= pivot2)
                        count++;
                if ((*a)->data > pivot1 && (*a)->data <= pivot2)
                        pb(a, b);
                else
                        ra(a);
        }
        count = size - 2;
        while (!check_last_three((*a), size))
        {
                if ((*a) && (*a)->data < count)
                        pb(a, b);
                else if ((*a) && (*a)->data >= count)
                        ra(a);
        }
}

void	a_to_b(int pivot1, int pivot2, t_stack **a, t_stack **b)
{
        int                     count;
        int                     size;
        int                     size2;

        count = 0;
        size = ft_stack_size(*a);
        if (size <= 3)
                return ;
        while (pivot1 && pivot2 && check_to_pivot(a, pivot1))
        {
                if ((*a)->data >= 1 && (*a)->data <= pivot1)
                        count++;
                if ((*a)->data >= 1 && (*a)->data <= pivot1)
                        pb(a, b);
                else
                        ra(a);
        }
        size2 = ft_stack_size (*a);
        if (size2 <= 3)
                return ;
        move_cause_pivot(a, b, count, size);
}
