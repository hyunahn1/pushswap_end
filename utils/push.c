#include "push_swap.h"

void    pa(t_stack **a, t_stack **b)
{
        t_stack         *head_b;
        t_stack         *head_a;
        t_stack         *new;
        int                     top_num;

        if (!(*b) || !b)
                return ;
        head_a = *a;
        head_b = *b;
        top_num = head_b->data;
        *b = head_b->next;
        if (*b)
                (*b)->prev = NULL;
        free (head_b);
        head_b = NULL;
        new = malloc (sizeof (t_stack));
        new->data = top_num;
        new->next = head_a;
        head_a->prev = new;
        *a = new;
        write (1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
        t_stack         *head;
        t_stack         *head_b;
        t_stack         *new;
        int                     top_num;

        if (!(*a) || !a)
                return ;
        head_b = *b;
        head = *a;
        top_num = head->data;
        if (head->next)
                head->next->prev = NULL;
        *a = head->next;
        free (head);
        head = NULL;
        new = malloc (sizeof (t_stack));
        new->data = top_num;
        new->next = NULL;
        if (head_b)
                new->next = head_b;
        new->prev = NULL;
        if (head_b)
                head_b->prev = new;
        *b = new;
        write (1, "pb\n", 3);
}
