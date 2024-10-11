/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduamart <eduamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:35:13 by eduamart          #+#    #+#             */
/*   Updated: 2024/10/09 10:20:30 by eduamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Function to check a string and handle 
 * whether it is null or not, printing char by char in the loop.
 * 
 * @param fd The file descriptor to use to read the contents of the file.
 * @return Returns the size.
 */
int	ft_print_string(char *str)
{
	int	size;

	size = 0;
	if (!str)
	{
		size += write(1, "(null)", 6);
	}
	while (str[size])
	{
		size += write(1, &str[size], 1);
	}
	return (size);
}

int	ft_print_number(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += write(1, "0", 1);
	if (n == -2147483648)
	{
		size += write(1, "-2147483648", 11);
		return (size);
	}
	if (n < 0)
	{
		size += write(1, "-", 1);
		n = -n;
	}
	if (n > 0)
		size += ft_print_unsigned((unsigned int)n);
	return (size);
}

/**
 * @brief Recursive function, prints the characters while the calls
 * wait from the lowest to the highest character.

 * @param fd The file descriptor to use to read the contents of the file.
 * @return Returns the size.
 */
int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += write(1, "0", 1);
	else
	{
		if (n / 10 != 0)
			ft_print_unsigned(n / 10);
		ft_print_character((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}
