/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduamart <eduamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:06:52 by eduamart          #+#    #+#             */
/*   Updated: 2024/10/10 11:15:58 by eduamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Explanation of va_list and va_start, va_arg, va_end:
 * 
 * va_list: Defines a variable to store the list of variable arguments.
 * 
 * va_start: Initializes the va_list pointer and associates it with the 
 * variable arguments that follow a fixed parameter.
 * 
 * va_arg: Extracts the next argument from the list, specifying the 
 * expected data type.
 * 
 * va_end: Cleans up the argument list when it is no longer needed. */

#include "ft_printf.h"

int	ft_print_character(int character)
{
	write(1, &character, 1);
	return (1);
}

/**
 * @brief Selects the format in which the character is printed.
 * @return Return size.
 */
static int	ft_select_format(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_print_character(va_arg(argument, int));
	else if (word == 's')
		size += ft_print_string(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_pointer(va_arg(argument, void *));
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

/**
 * @brief Takes a char pointer and a variadic parameter. 
 * It can use the following conversions:
 * 
Conversion ->	Description

%c	->	Prints a single character.

%s	->	Prints a string (as defined by default in C).

%p	->	The void * pointer given as an argument is printed in hexadecimal format.

%d	->	Prints a decimal number (base 10).

%i	->	Prints an integer in base 10.

%u	->	Prints an unsigned decimal number (base 10).

%x	->	Prints a hexadecimal number (base 16) in lowercase.

%X	->	Prints a hexadecimal number (base 16) in uppercase.

%%	->	Prints the percentage symbol.

%(empty)	->	Prints -1.

 * @return Returns an integer representing the total number of characters 
 * printed. This includes both the characters printed directly and those 
 * resulting from the processed format specifiers.
 */

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
			if (str[i + 1] == '\0')
			{
				va_end(argument);
				return (-1);
			}
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
