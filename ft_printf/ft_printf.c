/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:01:22 by marvin            #+#    #+#             */
/*   Updated: 2024/06/01 19:01:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list argument, const char word);

int	ft_print_character(char character)
{
	int	result;

	result = write(1, &character, 1);
	if (result == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	argument;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_select_format(argument, str[i + 1]);
			i++;
		}
		else
			size += ft_print_character(str[i]);
		i++;
	}
	va_end(argument);
	return (size);
}

static int	ft_select_format(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_print_character(va_arg(argument, int));
	else if (word == 's')
		size += ft_print_string(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_pointer(va_arg(argument, unsigned long long));
	else if (word == 'd' || word == 'i')
		size += ft_print_number(va_arg(argument, int));
	else if (word == 'u')
		size += ft_print_unsigned(va_arg(argument, unsigned int));
	else if (word == 'x' || word == 'X')
		size += ft_print_hexadecimal(va_arg(argument, unsigned int), word);
	else
		size += ft_print_character(word);
	return (size);
}
