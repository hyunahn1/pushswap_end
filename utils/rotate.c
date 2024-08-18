#include "push_swap.h"

void    ra(t_stack **n)
{
        t_stack         *origin_head;
        t_stack         *tail;
        t_stack         *new_head;

        if (!(*n) || !n)
                return ;
        origin_head = *n;
        tail = *n;
        new_head = (*n)->next;
        if (new_head)
                new_head->prev = NULL;
        if (origin_head->next)
                origin_head->next->prev = NULL;
        while (tail->next)
                tail = tail->next;
        origin_head->prev = tail;
        origin_head->next = NULL;
        if (tail)
                tail->next = origin_head;
        *n = new_head;
        write (1, "ra\n", 3);
}

void    rb(t_stack **n)
{
        t_stack         *origin_head;
        t_stack         *tail;
        t_stack         *new_head;

        if (!(*n) || !n)
                return ;
        origin_head = *n;
        tail = *n;
        new_head = (*n)->next;
        if (new_head)
                new_head->prev = NULL;
        if (origin_head->next)
                origin_head->next->prev = NULL;
        while (tail->next)
                tail = tail->next;
        origin_head->prev = tail;
        origin_head->next = NULL;
        if (tail)
                tail->next = origin_head;
        *n = new_head;
        write (1, "rb\n", 3);
}
