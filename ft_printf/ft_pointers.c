/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:07:35 by marvin            #+#    #+#             */
/*   Updated: 2024/07/15 12:07:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_pointer(unsigned long long ptr);

static void	ft_search_pointer(unsigned long long ptr);

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		return (ft_print_string("(nil)"));
	size += ft_print_string("0x");
	ft_search_pointer(ptr);
	size += ft_length_pointer(ptr);
	return (size);
}

static int	ft_length_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static void	ft_search_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_search_pointer(ptr / 16);
		ft_search_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_character(ptr + '0');
		else
			ft_print_character(ptr - 10 + 'a');
	}
}
