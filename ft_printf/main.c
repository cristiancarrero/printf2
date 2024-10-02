/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrero <ccarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:50:32 by ccarrero          #+#    #+#             */
/*   Updated: 2024/03/11 15:50:32 by ccarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	test_basic(void)
{
	ft_printf("Prueba básica:\n");
	ft_printf("Carácter: %c\n", 'A');
	ft_printf("Cadena: %s\n", "Hola mundo");
	ft_printf("Número: %d\n", 42);
	ft_printf("Hexadecimal: %x\n", 255);
	ft_printf("Puntero: %p\n", (void *)&test_basic);
}

static void	test_numbers(void)
{
	ft_printf("\nPrueba de números:\n");
	ft_printf("Entero: %d\n", INT_MAX);
	ft_printf("Entero negativo: %d\n", INT_MIN);
	ft_printf("Unsigned: %u\n", UINT_MAX);
	ft_printf("Hexadecimal (min): %x\n", 0);
	ft_printf("Hexadecimal (max): %X\n", UINT_MAX);
}

static void	test_edge_cases(void)
{
	ft_printf("\nPrueba de casos límite:\n");
	ft_printf("Cadena nula: %s\n", NULL);
	ft_printf("Cero: %d\n", 0);
	ft_printf("Puntero nulo: %p\n", NULL);
	ft_printf("Porcentaje: %%\n");
}

int	main(void)
{
	test_basic();
	test_numbers();
	test_edge_cases();
	return (0);
}
