#include "push_swap.h"

int     *array_values(t_stack **a, t_stack **b)
{
        (void)**a;
        t_stack         *b_stack;
        int                     count;
        int                     *arr;

        count = 0;
        b_stack = *b;
        while (b_stack)
        {
                count++;
                b_stack = b_stack->next;
        }
        b_stack = *b;
        arr = malloc (sizeof (int) * count + 1);
        arr[count] = -1;
        count = 0;
        while (b_stack)
        {
                arr[count++] = b_stack->data;
                b_stack = b_stack->next;
        }
        return (arr);
}

void    sort_largest_three(t_stack **a_s)
{
        t_stack         *a_stack;
        int                     a;
        int                     b;
        int                     c;

        if ((*a_s) && (*a_s)->next && (*a_s)->data > (*a_s)->next->data \
                && !(*a_s)->next->next)
                sa (a_s);
        if (!(*a_s) || !(*a_s)->next || !(*a_s)->next->next)
                return ;
        a_stack = *a_s;
        a = a_stack->data;
        b = a_stack->next->data;
        c = a_stack->next->next->data;
        if (a > b && a > c && b < c)
                rra (a_s);
        if ((b > a && b > c && c < a) || (a > b && a > c && b < c))
                rra (a_s);
        if ((a > b && a > c && b > c))
                ra (a_s);
        if (b > a && b > c && c > a)
                rra (a_s);
        if ((c > a && c > b && b < a) || (a > b && a > c && b > c) || \
        (b > a && b > c && c > a))
                sa (a_s);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int                     pivot1;
        int                     pivot2;
        int                     size;

        size = ft_stack_size(*a);
        pivot1 = size / 3;
        pivot2 = 2 * size / 3;
        if (size <= 5)
                pivot1 = size / 2;
        if (size <= 5)
                pivot2 = pivot1 * 2;
        a_to_b (pivot1, pivot2, a, b);
        sort_largest_three (a);
        b_to_a (a, b);
}
