/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduamart <eduamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:34:13 by eduamart          #+#    #+#             */
/*   Updated: 2024/10/10 15:36:38 by eduamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	character = 'A';
	char	*string = "HELLO WORLD";
	void	*void_ptr = NULL;
	int	number = 420;
	unsigned int	unsigned_number = 420;
	int	number_i = 420;
	int	hex_number_lowercase = 420;
	int	hex_number_uppercase = 420;
	int	n;

	//%Character%
	n = printf("CHAR printf()            = %c", character);
	printf(" (%d)\n", n);
	n = ft_printf("CHAR ft_printf()         = %c", character);
	printf(" (%d)\n\n", n);
	
	//%String%
	n = printf("STRING printf()          = %s", string);
	printf(" (%d)\n", n);
	n = ft_printf("STRING ft_printf()       = %s", string);
	printf(" (%d)\n\n", n);
	
	//%Pointer%
	n = printf("PTR ADDRESS printf()     = %p", &void_ptr);
	printf(" (%d)\n", n);
	n = ft_printf("PTR ADDRESS ft_printf()  = %p", &void_ptr);
	printf(" (%d)\n\n", n);
	
	//%Pointer (nil)%
	n = printf("PTR (NIL) printf()       = %p", void_ptr);
	printf(" (%d)\n", n);
	n = ft_printf("PTR (NIL) ft_printf()    = %p", void_ptr);
	printf(" (%d)\n\n", n);
	
	//%Signed Decimal%
	n = printf("SIGNED DEC printf()      = %d", number);
	printf(" (%d)\n", n);
	n = ft_printf("SIGNED DEC ft_printf()   = %d", number);
	printf(" (%d)\n\n", n);
	
	//%Unsigned Integer%
	n = printf("UNSIGNED INT printf()    = %i", number_i);
	printf(" (%d)\n", n);
	n = ft_printf("UNSIGNED INT ft_printf() = %i", number_i);
	printf(" (%d)\n\n", n);
	
	//%unsigned decimal%
	n = printf("UNSIGNED DEC printf()    = %u", unsigned_number);
	printf(" (%d)\n", n);
	n = ft_printf("UNSIGNED DEC ft_printf() = %u", unsigned_number);
	printf(" (%d)\n\n", n);
	
	//%Hexadecimal Lowercase%
	n = printf("HEX LOW printf()         = %x", hex_number_lowercase);
	printf(" (%d)\n", n);
	n = ft_printf("HEX LOW ft_printf()      = %x", hex_number_lowercase);
	printf(" (%d)\n\n", n);
	
	//%Hexadecimal Uppercase%
	n = printf("HEX UP printf()          = %X", hex_number_uppercase);
	printf(" (%d)\n", n);
	n = ft_printf("HEX UP ft_printf()       = %X", hex_number_uppercase);
	printf(" (%d)\n\n", n);
	
	//%Percentage%
	n = printf("PERCENTAGE printf()      = %% ");
	printf(" (%d)\n", n);
	n = ft_printf("PERCENTAGE ft_printf()   = %% ");
	printf(" (%d)\n\n", n);
	
	//%ERROR HANDLING%
	n = printf("NO MODIFIER printf()     = %");
	printf(" (%d)\n", n);
	n = ft_printf("NO MODIFIER ft_printf()  = %");
	printf(" (%d)\n\n", n);
	
	//%REMIX-1%
	n = printf("printf()                 = %s %", string);
	printf(" (%d)\n", n);
	n = ft_printf("ft_printf()              = %s %", string);
	printf(" (%d)\n\n", n);

	//%REMIX-2%
	n = printf("printf()                 = %%%s%%%c%%%%%%%%%u%%%%%d%%%%%i%%%%%%%xX%%%X%%%p%%%%", string, character, unsigned_number, number, number_i, hex_number_lowercase, hex_number_uppercase, &void_ptr);
	printf(" (%d)\n", n);
	n = ft_printf("ft_printf()              = %%%s%%%c%%%%%%%%%u%%%%%d%%%%%i%%%%%%%xX%%%X%%%p%%%%", string, character, unsigned_number, number, number_i, hex_number_lowercase, hex_number_uppercase, &void_ptr);
	printf(" (%d)\n\n", n);
}