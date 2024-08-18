/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:24:56 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 19:10:37 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	arr = NULL;
	stack_a = ft_parsing(argc, argv, stack_a);
	if (!check_error(stack_a))
		return (clear_nodes(stack_a));
	if (!stack_a)
		return (clear_nodes(stack_a));
	arr = quick_sort(argc, argv, &stack_a);
	index_by_size(arr, &stack_a);
	free(arr);
	argc--;
	push_swap(&stack_a, &stack_b);
	last_sort(&stack_a);
	clear_nodes(stack_a);
	clear_nodes(stack_b);
	return (0);
}
