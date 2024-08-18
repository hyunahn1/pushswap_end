#include "push_swap.h"

int     check_if_sorted(t_stack **a)
{
        t_stack         *a_stack;

        a_stack = *a;
        while (a_stack)
        {
                if (a_stack->next && a_stack->data > a_stack->next->data)
			return (0);
                a_stack = a_stack->next;
        }
        return (1);
}

void    check_arr_overflow(char *arr, t_stack *stack_a)
{
        int             i;

        i = 0;
        while (arr[i] && arr[i] >= '0' && arr[i] <= '9')
                i++;
        if (i > 11)
        {
                clear_nodes(stack_a);
                ft_error(1);
        }
}

int     check_duplicates(t_stack *stack_a)
{
        t_stack         *temp;
        t_stack         *move;

        if (!stack_a)
                return (0);
        temp = stack_a;
        while (temp)
        {
                move = stack_a;
                while (move)
                {
                        if (move != temp && move->data == temp->data)
                                return (1);
                        move = move->next;
                }
                temp = temp->next;
        }
        return (0);
}

int     check_int_overflow(t_stack *a)
{
        while (a)
        {
                if (a->data > 2147483647)
                        return (1);
                else if (a->data < -2147483648)
                        return (1);
                a = a->next;
        }
        return (0);
}

int     check_error(t_stack *stack_a)
{
        if (check_duplicates(stack_a))
        {
                ft_printf("Error\n");
                return (0);
        }
        else if (check_int_overflow(stack_a))
        {
                ft_printf("Error\n");
                return (0);
        }
        else if (check_if_sorted(&stack_a))
                return (0);
        else
                return (1);
}
