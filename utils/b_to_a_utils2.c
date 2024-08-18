#include "push_swap.h"

int     count_less_than_start(t_stack **a, t_stack *b_stack)
{
        t_stack         *a_stack;
        int                     count;

        count = 0;
        a_stack = *a;
        while (a_stack && b_stack->data > a_stack->data)
        {
                count++;
                a_stack = a_stack->next;
        }
        return (count);
}

t_cnt   *sorted_commands(t_stack **a, t_stack *b_stack, t_cnt *m)
{
        int             i;

        i = count_less_than_start (a, b_stack);
        if (i > m->size / 2)
                m->rra = m->size - i;
        else
                m->ra = i;
        return (m);
}

void    apply_commands(t_stack **a, t_stack **b, t_cnt *m)
{
        int             i;

        i = 0;
        while (m->ra > i++)
                ra (a);
        i = 0;
        while (m->rra > i++)
                rra (a);
        i = 0;
        while (m->rb > i++)
                rb (b);
        i = 0;
        while (m->rrb > i++)
                rrb(b);
        pa (a, b);
}

t_cnt   *compare_command_counts(t_cnt *m, t_cnt *search)
{                                                                             if (search->sum < m->sum)
        {
                m->ra = search->ra;
                m->rra = search->rra;
                m->rb = search->rb;
                m->rrb = search->rrb;
                m->sum = search->sum;
        }
        search->sum = 0;
        search->ra = 0;
        search->rra = 0;
        search->rb = 0;
        search->rrb = 0;
        return (m);
}

int     check_arr(int *arr, int size)
{
        int                     i;

        i = 0;
        while (size--)
        {
                if (arr[i] >= arr[i + 1])
                        return (1);
                i++;
        }
        return (0);
}
