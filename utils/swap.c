#include "push_swap.h"

void    sa(t_stack **n)
{
        t_stack         *origin_head;
        t_stack         *new_head;

        if (!(*n) || !n)
                return ;
        origin_head = *n;
        if (!origin_head || !origin_head->next)
                return ;
        new_head = (*n)->next;
        origin_head->next = new_head->next;
        if (new_head->next)
                new_head->next->prev = origin_head;
        if (origin_head->prev)
                origin_head->prev = new_head;
        new_head->prev = NULL;
        new_head->next = origin_head;
        *n = new_head;
        write (1, "sa\n", 3);
}

void    sb(t_stack **n)
{
        t_stack         *origin_head;
        t_stack         *new_head;

        if (!(*n) || !n)
                return ;
        origin_head = *n;
        new_head = (*n)->next;
        origin_head->next = new_head->next;
        origin_head->prev = new_head;
        new_head->prev = NULL;
        new_head->next = origin_head;
        *n = new_head;
        write (1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
        t_stack         *origin_head;
        t_stack         *new_head;

        if (!(*a) || !a || !(*b) || !b)
                return ;
        origin_head = *a;
        if (!origin_head || !origin_head->next)
                return ;
        new_head = (*a)->next;
        origin_head->next = new_head->next;
        origin_head->prev = new_head;
        new_head->prev = NULL;
        new_head->next = origin_head;
        *a = new_head;
        origin_head = *b;
        new_head = (*b)->next;
        origin_head->next = new_head->next;
        origin_head->prev = new_head;
        new_head->prev = NULL;
        new_head->next = origin_head;
        *b = new_head;
        write (1, "ss\n", 3);
}
