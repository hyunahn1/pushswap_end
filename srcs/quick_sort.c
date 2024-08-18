#include "push_swap.h"

int     *insert_arr(int *arr, t_stack *a)
{
        int             i;
        int             size;

        size = ft_stack_size(a);
        i = -1;
        while (size-- && a)
        {
                arr[++i] = a->data;
                a = a->next;
        }
        return (arr);
}

int     *insert_num(int ac, char **av, t_stack *a)
{
        int             *arr;
        int             i;

        arr = NULL;
        ac = ft_stack_size(a);
        arr = malloc (sizeof (int) * ac);
        if (!arr)
                return (0);
        i = 0;
        while (av[++i])
                arr = insert_arr (arr, a);
        return (arr);
}

void    ft_swap(int *arr, int move_high, int move_low, int pivot)
{
        int             temp;

        if (move_low < move_high)
        {
                temp = arr[move_low];
                arr[move_low] = arr[move_high];
                arr[move_high] = temp;
                return ;
        }
        temp = *(arr + pivot);
        *(arr + pivot) = *(arr + move_high);
        *(arr + move_high) = temp;
}

void    start_sort(int *arr, int high, int pivot)
{
        int             move_high;
        int             move_low;

        while (check_arr (arr, high) && pivot < high)
        {
                move_low = pivot;
                move_high = high;
                while (move_low < move_high)
                {
                        while (arr[move_high] >= arr[pivot] && move_low < move_high)
                                move_high--;
                        if (pivot == move_high && move_low == pivot)
                                break ;
                        while (arr[move_low] <= arr[pivot] && move_low < move_high)
                                move_low++;
                        if (move_low < move_high)
                                ft_swap (arr, move_high, move_low, pivot);
                }
                if (move_high == move_low && arr[move_low] > arr[pivot])
                        pivot++;
                else if (move_high == move_low && arr[move_low] < arr[pivot])
                        ft_swap (arr, move_high, move_low, pivot);
                else
                        pivot++;
        }
}

int     *quick_sort(int ac, char **av, t_stack **a)
{
        int             *arr;
        int             high;
        int             pivot;

        pivot = 0;
        arr = NULL;
        arr = insert_num(ac, av, *a);
        high = ft_stack_size (*a) - 1;
        start_sort (arr, high, pivot);
        return (arr);
}
