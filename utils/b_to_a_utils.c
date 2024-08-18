#include "push_swap.h"

t_cnt   *init_struct(t_cnt *current)
{
        current = malloc(sizeof(t_cnt));
        current->rb = 0;
        current->rrb = 0;
        current->ra = 0;
        current->rra = 0;
        current->sum = 0;
        current->min_i = 0;
        current->size = 0;
        current->total_min = 0;
        current->min_ptr = NULL;
        return (current);
}

t_cnt   *unsorted_metrics(t_stack **a, t_cnt *m)
{
        t_stack         *a_stack;

        a_stack = *a;
        m->min_i = 1;
        while (a_stack && a_stack->next && a_stack->data < a_stack->next->data)
        {
                m->min_i++;
                a_stack = a_stack->next;
        }
        a_stack = a_stack->next;
        if (!a_stack)
                m->min_i = 0;
        m->size = ft_stack_size(*a);
        m->min_ptr = a_stack;
        if (!a_stack)
                m->min_ptr = (*a);
        m->total_min = ft_stack_size(m->min_ptr);
        return (m);
}

t_cnt   *distance_to_head(t_stack **b, t_cnt *m, t_stack *b_stack)
{
        int                     count;
        int                     size;
        t_stack         *bb;

        bb = *b;
        count = 0;
        while (bb->data != b_stack->data)
        {
                count++;
                bb = bb->next;
	}
        size = ft_stack_size(*b);
        if (count > size / 2)
                m->rrb = size - count;
        else
                m->rb = count;
        return (m);
}

void    unsorted_compare(t_stack **a, t_stack *a_compare, \
t_stack *b_stack, t_cnt *m)
{
        if (!a_compare)
        {
                m->ra = count_less_than_start (a, b_stack);
                if (m->ra > m->size / 2)
                        m->rra = m->size - m->ra;
                if (m->ra > m->size / 2)
                        m->ra = 0;
        }
        else
        {
                if (m->min_i > m->size / 2)
                        m->rra = m->size - m->min_i;
                else
                        m->ra = m->min_i;
        }
}

t_cnt   *unsorted_commands(t_stack **a, t_stack *b_stack, t_cnt *m)
{
        t_stack         *a_compare;

        if (m->min_ptr->data > b_stack->data)
        {
                if (m->min_i > m->size / 2)
                        m->rra = m->size - m->min_i;
                else
                        m->ra = m->size - m->total_min;
                return (m);
        }
        a_compare = m->min_ptr;
        while (a_compare)
        {
                if (a_compare->data > b_stack->data)
                        break ;
                m->min_i++;
                a_compare = a_compare->next;
        }
        unsorted_compare(a, a_compare, b_stack, m);
        return (m);
}
