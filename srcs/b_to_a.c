#include "push_swap.h"

t_cnt   *loop_b_stack(t_stack **a, t_stack **b, t_cnt *m, t_cnt *search)
{
        t_stack         *b_stack;

        b_stack = (*b)->next;
        while (b_stack)
        {
                search = unsorted_metrics (a, search);
                search = distance_to_head (b, search, b_stack);
                if (!check_if_sorted (a))
                        search = unsorted_commands (a, b_stack, search);
                else
                        search = sorted_commands (a, b_stack, search);
                search->sum = search->ra + search->rra + search->rb + search->rrb;
                m = compare_command_counts(m, search);
                b_stack = b_stack->next;
        }
        return (m);
}

void    b_to_a(t_stack **a, t_stack **b)
{
        t_cnt           *m;
        t_cnt           *search;
        t_stack         *b_stack;

        while (*b)
        {
                b_stack = *b;
                search = init_struct(search);
                m = init_struct (m);
                m = unsorted_metrics (a, m);
                m = distance_to_head (b, m, b_stack);
                if (!check_if_sorted (a))
                        m = unsorted_commands (a, b_stack, m);
                else
                        m = sorted_commands (a, b_stack, m);
                m->sum = m->ra + m->rra + m->rb + m->rrb;
                b_stack = b_stack->next;
                m = loop_b_stack (a, b, m, search);
                apply_commands (a, b, m);
                free (m);
                m = NULL;
                free (search);
                search = NULL;
        }
}
