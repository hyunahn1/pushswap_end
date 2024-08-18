#include "push_swap.h"

void    rra(t_stack **n)
{
        t_stack         *temp_new_head;
        t_stack         *origin_head;
        t_stack         *tmp;

        if (!n || !(*n))
                return ;
        temp_new_head = *n;
        origin_head = *n;
        tmp = NULL;
        if (!n && !(*n)->prev && !(*n)->next)
                return ;
        while (temp_new_head->next)
        {
                tmp = temp_new_head;
                temp_new_head = temp_new_head->next;
        }
        tmp->next = NULL;
        temp_new_head->next = origin_head;
        origin_head->prev = temp_new_head;
        temp_new_head->prev = NULL;
        *n = temp_new_head;
        write (1, "rra\n", 4);
}

void    rrb(t_stack **n)
{
        t_stack         *temp_new_head;
        t_stack         *origin_head;

        temp_new_head = *n;
        origin_head = *n;
        if (!origin_head->prev && !origin_head->next)
                return ;
        while (temp_new_head->next)
                temp_new_head = temp_new_head->next;
        temp_new_head->prev->next = NULL;
        temp_new_head->next = origin_head;
        origin_head->prev = temp_new_head;
        temp_new_head->prev = NULL;
        *n = temp_new_head;
        write (1, "rrb\n", 4);
}
