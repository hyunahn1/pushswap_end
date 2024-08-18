#include "push_swap.h"

t_stack *make_stack(long long int num, t_stack *s)
{
        t_stack         *temp;
        t_stack         *new;

        temp = s;
        while (temp && temp->next)
                temp = temp->next;
        new = malloc (sizeof (t_stack));
        if (!new)
                return (0);
        if (!temp)
        {
                s = new;
                new->prev = NULL;
        }
        else
        {
                new->prev = temp;
                temp->next = new;
        }
        new->next = NULL;
        new->data = num;
        temp = s;
        return (s);
}

int	ft_stack_size(t_stack *a)
{
        t_stack *temp;
        int             count;

        count = 0;
        temp = a;
        while (temp)
        {
                count++;
                temp = temp->next;
        }
        return (count);
}

int	clear_nodes(t_stack *a)
{
        t_stack         *temp;

        while (a)
        {
                temp = a;
                a = a->next;
                free (temp);
        }
        return (0);
}
