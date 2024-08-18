/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:38:41 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/26 15:12:19 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack		*prev;
	struct s_stack		*next;
	int					data;
}		t_stack;

typedef struct s_cnt
{
	int			rra;
	int			rrb;
	int			ra;
	int			rb;
	int			sum;
	int			min_i;
	int			total_min;
	int			size;
	t_stack		*min_ptr;
}		t_cnt;

int     check_to_pivot(t_stack **a, int pivot1);
void    move_cause_pivot(t_stack **a, t_stack **b, int count, int size);
void    a_to_b(int pivot1, int pivot2, t_stack **a, t_stack **b);
t_cnt   *loop_b_stack(t_stack **a, t_stack **b, t_cnt *m, t_cnt *search);
void    b_to_a(t_stack **a, t_stack **b);

int     search_num(int n, int *arr, int size);
void    index_by_size(int *arr, t_stack **a);
void    last_sort(t_stack **a);

long long int   ft_atoi(const char *nptr);
int     ft_empty(char *arr);
int     ft_minus(char *arr);
t_stack *play_parsing(char *arr, t_stack *stack_a);
t_stack *ft_parsing(int argc, char **argv, t_stack *stack_a);

int     *array_values(t_stack **a, t_stack **b);
void    sort_largest_three(t_stack **a_s);
void    push_swap(t_stack **a, t_stack **b);

int     *insert_arr(int *arr, t_stack *a);
int     *insert_num(int ac, char **av, t_stack *a);
void    ft_swap(int *arr, int move_high, int move_low, int pivot);
void    start_sort(int *arr, int high, int pivot);
int     *quick_sort(int ac, char **av, t_stack **a);

int     check_last_three(t_stack *a, int size);
t_stack *make_stack(long long int num, t_stack *s);
int     ft_stack_size(t_stack *a);
int     clear_nodes(t_stack *a);

t_cnt   *init_struct(t_cnt *current);
t_cnt   *unsorted_metrics(t_stack **a, t_cnt *m);
t_cnt   *distance_to_head(t_stack **b, t_cnt *m, t_stack *b_stack);
void    unsorted_compare(t_stack **a, t_stack *a_compare, \
		t_stack *b_stack, t_cnt *m);
t_cnt   *unsorted_commands(t_stack **a, t_stack *b_stack, t_cnt *m);
int     count_less_than_start(t_stack **a, t_stack *b_stack);
t_cnt   *sorted_commands(t_stack **a, t_stack *b_stack, t_cnt *m);
void    apply_commands(t_stack **a, t_stack **b, t_cnt *m);
int     ft_error(int i);
t_cnt   *compare_command_counts(t_cnt *m, t_cnt *search);
int     check_if_sorted(t_stack **a);
void    check_arr_overflow(char *arr, t_stack *stack_a);
int     check_duplicates(t_stack *stack_a);
int     check_int_overflow(t_stack *a);
int     check_error(t_stack *stack_a);

void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    rra(t_stack **n);
void    rrb(t_stack **n);
void    ra(t_stack **n);
void    rb(t_stack **n);
void    sa(t_stack **n);
void    sb(t_stack **n);
void    ss(t_stack **a, t_stack **b);
int     check_arr(int *arr, int size);

#endif
