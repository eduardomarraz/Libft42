/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduamart <eduamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:06:34 by eduamart          #+#    #+#             */
/*   Updated: 2024/10/09 10:23:10 by eduamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The long long format is used because it is an integer data type that,
in most compilers (64-bit), ensures that we can handle large values 
(large memory addresses) without overflow.

unsigned is used because memory only handles positive values.
*/

#include "ft_printf.h"

static int	ft_length_pointer(void *ptr);

static void	ft_search_pointer(void *ptr);

/**
 * @brief Prints the memory address (pointer) in hexadecimal format.
 * 
 * 'ptr' The memory address to convert and print.

 * @param fd The file descriptor to use to read the contents of the file.
 * @return Returns size.
 */
int	ft_print_pointer(void *ptr)
{
	int					size;
	unsigned long long	ptr2;

	ptr2 = (unsigned long long)ptr;
	size = 0;
	if (!ptr)
	{
		ft_print_string("(nil)");
		return (5);
	}
	size += ft_print_string("0x");
	if (ptr2 == 0)
		size += write(1, "0", 1);
	else
	{
		ft_search_pointer(ptr);
		size += ft_length_pointer(ptr);
	}
	return (size);
}

/**
 * @brief Returns the number of digits of the pointer in hexadecimal format.

 * @param fd The file descriptor to use to read the contents of the file.
 * @return Returns len.
 */
static int	ft_length_pointer(void *ptr)
{
	int					len;
	unsigned long long	ptr2;

	ptr2 = (unsigned long long)ptr;
	len = 0;
	while (ptr2 > 0)
	{
		len++;
		ptr2 /= 16;
	}
	return (len);
}

/**
 * @brief Converts the pointer value to a hexadecimal string and prints it.
 * It uses recursion to break down the number into its hexadecimal digits.

 * @param fd The file descriptor to use to read the contents of the file.
 * @return Does not return anything.
 */
static void	ft_search_pointer(void *ptr)
{
	unsigned long long	ptr2;

	ptr2 = (unsigned long long)ptr;
	if (ptr2 >= 16)
	{
		ft_search_pointer((void *)(ptr2 / 16));
		ft_search_pointer((void *)(ptr2 % 16));
	}
	else
	{
		if (ptr2 < 10)
			ft_print_character(ptr2 + '0');
		else
			ft_print_character(ptr2 - 10 + 'a');
	}
}
