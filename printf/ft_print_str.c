/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:43:40 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 17:43:42 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_str(char *s)
{
	int	len;

	if (!s)
	{
		len = ft_putstr("(null)");
		return (len);
	}
	len = ft_putstr(s);
	return (len);
}
