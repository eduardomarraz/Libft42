/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduamart <eduamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:05:56 by eduamart          #+#    #+#             */
/*   Updated: 2024/10/09 10:21:36 by eduamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_hexadecimal(unsigned int num);

static void	ft_search_hexadecimal(unsigned int num, const char word);

/**
 * @brief Prints a number in hexadecimal format, either in lowercase 
 * (if word is 'x') or uppercase (if word is 'X').
 * It also returns the length of the number in its hexadecimal representation.

 * @param fd The file descriptor to use to read the contents of the file.
 * @return Returns ft_length_hexadecimal.
 */
int	ft_print_hexadecimal(unsigned int num, const char word)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_search_hexadecimal(num, word);
	return (ft_length_hexadecimal(num));
}

/**
 * @brief Recursively converts the given number to hexadecimal format, 
 * printing each digit as it decomposes it. 
 * It distinguishes based on the 'word' parameter, whether to use 
 * uppercase or lowercase hexadecimal letters.

 * @param fd The file descriptor to use to read the contents of the file.
 * @return Does not return anything.
 */
static void	ft_search_hexadecimal(unsigned int num, const char word)
{
	if (num >= 16)
	{
		ft_search_hexadecimal(num / 16, word);
		ft_search_hexadecimal(num % 16, word);
	}
	else
	{
		if (num < 10)
			ft_print_character(num + '0');
		else
		{
			if (word == 'x')
				ft_print_character(num - 10 + 'a');
			if (word == 'X')
				ft_print_character(num - 10 + 'A');
		}
	}
}

/**
 * @brief Calculates the length based on the number 
 * in its hexadecimal representation.

 * @param fd The file descriptor to use to read the contents of the file.
 * @return Returns len.
 */
static int	ft_length_hexadecimal(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
